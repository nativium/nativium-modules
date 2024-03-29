// imports
import { createPinia } from "pinia";
import { createApp } from "vue";

// application
import App from "./App.vue";
const app = createApp(App);

// quasar
import "@quasar/extras/material-icons/material-icons.css";
import "@quasar/extras/mdi-v6/mdi-v6.css";
import "@quasar/extras/roboto-font/roboto-font.css";
import { Dialog, Loading, Quasar, Notify } from "quasar";
import "quasar/src/css/index.sass";

app.use(Quasar, {
    plugins: {
        Dialog,
        Loading,
        Notify,
    },
});

// wasm
import WasmLoader from "./plugins/wasm-loader";
app.use(WasmLoader);

// application
import Application from "./plugins/application";
app.use(Application);

// routes
import router from "./router";

// mount application
app.use(createPinia());
app.use(router);
app.mount("#app");
