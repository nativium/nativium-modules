<script setup>
import { ref } from "vue";
import { useQuasar } from "quasar";
import { useWasmModuleStore } from "../../stores/wasm-module";

const wm = useWasmModuleStore();
const q = useQuasar();

const fieldUsername = ref(null);
const fieldPassword = ref(null);

function onSubmit() {
    q.notify({
        type: "info",
        message: "Sending request...",
    });

    new Promise((resolve) => {
        (async function () {
            const data = wm.module.CustomerSystemService.login(
                fieldUsername.value,
                fieldPassword.value
            );

            resolve(data);
        })();
    }).then((data) => {
        if (data.response.success) {
            q.notify({
                type: "positive",
                message: "You are logged. Welcome " + data.customer.name + "!",
            });
        } else {
            q.notify({
                type: "negative",
                message: "Invalid username or password, try again!",
            });
        }
    });
}

function onReset() {
    fieldUsername.value = null;
    fieldPassword.value = null;
}
</script>

<template>
    <div class="container q-pa-md text-center">
        <h4>Login</h4>

        <div v-if="wm.module.ApplicationCore.shared().isInitialized()">
            <q-form @submit="onSubmit" @reset="onReset" class="q-gutter-md">
                <q-input
                    rounded
                    outlined
                    type="text"
                    v-model="fieldUsername"
                    label="Username"
                    lazy-rules
                    :rules="[
                        (val) =>
                            (val && val.length > 0) || 'Please type something',
                    ]"
                />

                <q-input
                    rounded
                    outlined
                    type="password"
                    v-model="fieldPassword"
                    label="Password"
                    lazy-rules
                    :rules="[
                        (val) =>
                            (val && val.length > 0) || 'Please type something',
                    ]"
                />

                <small>Use account demo/demo to success login</small>

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
