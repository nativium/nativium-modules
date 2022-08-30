<script setup>
import { ref } from "vue";
import { useQuasar } from "quasar";
import { useWasmModuleStore } from "../../stores/wasm-module";

const wm = useWasmModuleStore();
const q = useQuasar();

const fieldReadFilename = ref(null);
const fieldWriteFilename = ref(null);
const fieldWriteValue = ref(null);

function onSubmitRead() {
    const raw = wm.module.FileHelper.getFileContentAsBinary(
        fieldReadFilename.value
    );

    const data = new TextDecoder().decode(raw);

    q.notify({
        type: "positive",
        message: "Value: " + data,
    });
}

function onSubmitWrite() {
    var enc = new TextEncoder();
    const data = enc.encode(fieldWriteValue.value);

    wm.module.FileHelper.createFileWithBinaryContent(
        fieldWriteFilename.value,
        data
    );

    q.notify({
        type: "positive",
        message: "Data wrote",
    });
}

function onResetRead() {
    fieldReadFilename.value = null;
}

function onResetWrite() {
    fieldWriteFilename.value = null;
    fieldWriteValue.value = null;
}
</script>

<template>
    <div class="container q-pa-md text-center">
        <h4>File</h4>

        <div v-if="wm.module.ApplicationCore.shared().isInitialized()">
            <p class="text-bold">Write File Data</p>

            <q-form
                @submit="onSubmitWrite"
                @reset="onResetWrite"
                class="q-gutter-md"
            >
                <q-input
                    rounded
                    outlined
                    type="text"
                    v-model="fieldWriteFilename"
                    label="Filename"
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

            <p class="text-bold">Read File Data</p>

            <q-form
                @submit="onSubmitRead"
                @reset="onResetRead"
                class="q-gutter-md"
            >
                <q-input
                    rounded
                    outlined
                    type="text"
                    v-model="fieldReadFilename"
                    label="Filename"
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
