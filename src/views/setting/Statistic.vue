<template>
  <div class="setting">
    <el-tabs v-model="activeName" stretch @tab-click="handleTab">
      <el-tab-pane label="OverAll" name="overall"></el-tab-pane>
    </el-tabs>
    <el-table :data="statisticData" stripe style="width: 100%" v-if="activeName=='overall'">
      <el-table-column prop="networkType" label="NetworkType" :show-overflow-tooltip="true"></el-table-column>
      <el-table-column prop="connectionType" label="ConnectionType" :show-overflow-tooltip="true"></el-table-column>
      <el-table-column prop="proxyAddr" label="ProxyAddr" :show-overflow-tooltip="true"></el-table-column>
    </el-table>
  </div>
</template>

<script setup lang="ts">
import { ref, onBeforeMount } from 'vue'
import type { TabsPaneContext } from 'element-plus'
const remote = window.require('@electron/remote')
const zoomSettingStatisticCtrl = remote.app.zoomSdkModule.Setting.GetSettingStatisticCtrl()
const activeName = ref('overall')
const statisticData = ref<any>([])

const isInStatisticData = (item: any) => {
  for (let index=0; index<statisticData.value.length; index++) {
    if (statisticData.value[index].type == item.type) {
      return index
    }
  }
  return null
}

const handleStatisticData = (param: any) => {
    statisticData.value = []
    for (let key in param) {
    if (key == 'err') {
      continue
    }
    let keyList = key.split('_')
    let type = keyList.length > 2 ? `${keyList[0]}_${keyList[2]}`: keyList[0]
    let obj = {
      type,
      [keyList[1]]: param[key]
    }
    let index = isInStatisticData(obj)
    if (typeof index == 'number') {
      statisticData.value[index] = {...statisticData.value[index], ...obj}
    } else {
      statisticData.value.push(obj)
    }
  }
}

const handleTab = (tab: TabsPaneContext) => {
  switch (tab.props.name) {
    case 'overall':
      queryOverallStatisticInfo()
      break;
  }
}

const queryOverallStatisticInfo = () => {
  statisticData.value = []
  let ret = zoomSettingStatisticCtrl.Setting_QueryOverallStatisticInfo()
  statisticData.value = [ret]
}

onBeforeMount(() => {
  queryOverallStatisticInfo()
})
</script>
