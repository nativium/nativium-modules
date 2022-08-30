<script setup>
import { useQuasar } from "quasar";
import { useWasmModuleStore } from "../../stores/wasm-module";

const wm = useWasmModuleStore();
const q = useQuasar();

function onInitializeCore() {
    q.notify({
        type: "info",
        message: "Initializing...",
    });

    new Promise((resolve) => {
        (async function () {
            wm.initialize();
            resolve();
        })();
    }).then(() => {
        q.notify({
            type: "positive",
            message: "Initialized",
        });
    });
}
</script>

<template>
    <div class="container q-pa-md text-center">
        <h4>Initialize</h4>

        <q-btn
            color="primary"
            label="Initialize Core"
            @click="onInitializeCore()"
        />
    </div>
</template>
