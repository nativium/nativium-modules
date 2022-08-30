<script setup>
import { useWasmModuleStore } from "../stores/wasm-module";

const wm = useWasmModuleStore();
const currentDateTime = import.meta.env.CURRENT_DATE_TIME;
</script>

<template>
    <div class="q-mt-lg" v-if="wm.isLoaded">
        <p>
            Wasm Module Version:
            {{ wm.module.ApplicationCore.shared().getVersion() }}
        </p>
        <p>Generated at: {{ currentDateTime }}</p>
    </div>
    <div class="q-mt-lg" v-else>
        <p>Loading WASM module...</p>
    </div>
</template>

<style scoped>
/* ignore */
</style>
