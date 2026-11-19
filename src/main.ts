import { createApp } from 'vue'
import { createPinia } from 'pinia'
import App from './App.vue'
import router from './router'
import installElementPlus from './plugins/element'

const app: any = createApp(App)
const pinia = createPinia()
installElementPlus(app)
app.use(pinia).use(router).mount('#app')