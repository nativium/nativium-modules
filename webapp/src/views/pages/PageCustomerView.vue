<script setup>
import { ref } from "vue";
import { CustomerStatusEnum } from "../../../../custom/modules/app-enumerator/gluecode/generated-src/ts/app-enumerator";
import { useWasmModuleStore } from "../../stores/wasm-module";

const wm = useWasmModuleStore();

const customer = ref(wm.module.ApplicationCore.shared().getCustomer());
</script>

<template>
    <div class="container q-pa-md text-center">
        <h4>Customer</h4>

        <div v-if="wm.module.CustomerHelper.isLogged()">
            <p><strong>Name:</strong> {{ customer.name }}</p>
            <p>
                <strong>Status:</strong>
                {{
                    customer.status == CustomerStatusEnum.ACTIVE
                        ? "active"
                        : "inactive"
                }}
            </p>
            <p><strong>Token:</strong> {{ customer.token }}</p>
        </div>
        <div v-else>
            You are not logged or you not initialize core to customer data be
            loaded.
        </div>
    </div>
</template>
