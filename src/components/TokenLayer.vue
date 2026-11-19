<template>
  <div class="token">
    <el-dialog v-model="dialogVisible" title="SDK Authentication" :close-on-click-modal="false" :close-on-press-escape="false" width="450px">
      <el-form ref="tokenFormRef" :model="tokenForm" :rules="rules" class="overflow">
        <el-form-item prop="jwtToken">
          <el-input v-model.trim="tokenForm.jwtToken" placeholder="input jwt token" clearable />
        </el-form-item>
        <el-form-item prop="publicAppKey">
          <el-input v-model.trim="tokenForm.publicAppKey" placeholder="input public app key" clearable />
        </el-form-item>
        <div class="right">
          <el-button type="primary" @click="submitForm(tokenFormRef)">Submit</el-button>
        </div>
      </el-form>
    </el-dialog>
  </div>
</template>

<script setup lang="ts">
import { reactive, ref } from 'vue'
import type { ElForm } from 'element-plus'
import { getResultDesc } from '../assets/ts/util'
const props = defineProps({
  zoomAuth: {
    type: Object,
    required: true
  }
})
const dialogVisible = ref(false)
const tokenFormRef = ref<InstanceType<typeof ElForm>>()
const tokenForm = reactive({
  jwtToken: '',
  publicAppKey: '',
})

const validateAuth = (rule: any, value: any, callback: any) => {
  const jwtToken = tokenForm.jwtToken?.trim() || '';
  const publicAppKey = tokenForm.publicAppKey?.trim() || '';
  if (!jwtToken && !publicAppKey) {
    callback(new Error('Please input jwt token or public app key'))
  } else {
    callback()
  }
}

const rules = reactive({
  jwtToken: [
    {
      validator: validateAuth,
      trigger: 'change'
    }
  ],
  publicAppKey: [
    {
      validator: validateAuth,
      trigger: 'change'
    }
  ]
})

const submitForm = (formEl: InstanceType<typeof ElForm> | undefined) => {
  if (!formEl) return
  formEl.validate((valid) => {
    if (valid) {
      getResultDesc('SDKAuth', props.zoomAuth.SDKAuth(tokenForm), true)
      dialogVisible.value = false
    } else {
      console.log('error submit!')
    }
  })
}

defineExpose({
  dialogVisible
})
</script>
