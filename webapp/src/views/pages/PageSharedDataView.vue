<script setup>
import { ref } from "vue";
import { useQuasar } from "quasar";
import { useWasmModuleStore } from "../../stores/wasm-module";

const wm = useWasmModuleStore();
const q = useQuasar();

const fieldReadKey = ref(null);
const fieldWriteKey = ref(null);
const fieldWriteValue = ref(null);

function onSubmitRead() {
    const data = wm.module.SharedData.shared().getString(
        "sample",
        fieldReadKey.value
    );

    q.notify({
        type: "positive",
        message: "Value: " + data,
    });
}

function onSubmitWrite() {
    wm.module.SharedData.shared().setString(
        "sample",
        fieldWriteKey.value,
        fieldWriteValue.value
    );

    q.notify({
        type: "positive",
        message: "Data wrote",
    });
}

function onResetRead() {
    fieldReadKey.value = null;
}

function onResetWrite() {
    fieldWriteKey.value = null;
    fieldWriteValue.value = null;
}
</script>

<template>
    <div class="container q-pa-md text-center">
        <h4>Shared Data</h4>

        <div v-if="wm.module.ApplicationCore.shared().isInitialized()">
            <p class="text-bold">Write Value</p>

            <q-form
                @submit="onSubmitWrite"
                @reset="onResetWrite"
                class="q-gutter-md"
            >
                <q-input
                    rounded
                    outlined
                    type="text"
                    v-model="fieldWriteKey"
                    label="Key"
                    lazy-rules
                    :rules="[
                        (val) =>
                            (val && val.length > 0) || 'Please type something',
                    ]"
                />

                <q-input
                    rounded
                    outlined
                    type="text"
                    v-model="fieldWriteValue"
                    label="Value"
                    lazy-rules
                    :rules="[
                        (val) =>
                            (val && val.length > 0) || 'Please type something',
                    ]"
                />

                <div>
                    <q-btn label="Submit" type="submit" color="primary" />
                    <q-btn
                        label="Reset"
                        type="reset"
                        color="primary"
                        flat
                        class="q-ml-sm"
                    />
                </div>
            </q-form>

            <br />
            <br />

            <q-separator />

            <br />
            <br />

            <p class="text-bold">Read Value</p>

            <q-form
                @submit="onSubmitRead"
                @reset="onResetRead"
                class="q-gutter-md"
            >
                <q-input
                    rounded
                    outlined
                    type="text"
                    v-model="fieldReadKey"
                    label="Key"
                    lazy-rules
                    :rules="[
                        (val) =>
                            (val && val.length > 0) || 'Please type something',
                    ]"
                />

                <div>
                    <q-btn label="Submit" type="submit" color="primary" />
                    <q-btn
                        label="Reset"
                        type="reset"
                        color="primary"
                        flat
                        class="q-ml-sm"
                    />
                </div>
            </q-form>
        </div>

        <div v-else>You not initialize core. Initialize it first.</div>
    </div>
</template>
