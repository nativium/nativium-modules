<script setup>
import { ref } from "vue";
import { useRouter } from "vue-router";
import { useWasmModuleStore } from "../stores/wasm-module";

const wm = useWasmModuleStore();
const router = useRouter();

const menuItemsExpanded = ref(true);
const menuInformationsExpanded = ref(true);

const menuItems = [
    {
        label: "Initialize",
        route: "/page/initialize",
    },
    {
        label: "Customer",
        route: "/page/customer",
    },
    {
        label: "Login",
        route: "/page/login",
    },
    {
        label: "Shared Data",
        route: "/page/shared-data",
    },
    {
        label: "File",
        route: "/page/file",
    },
    {
        label: "Todo List",
        route: "/page/todo-list",
    },
];

function onMenuItemClick(item) {
    router.push(item.route);
}
</script>

<template>
    <q-list>
        <!-- MENU -->
        <q-expansion-item v-model="menuItemsExpanded">
            <template v-slot:header>
                <q-item-section side>
                    <q-avatar
                        icon="menu"
                        color="indigo"
                        text-color="white"
                        size="24px"
                    />
                </q-item-section>

                <q-item-section>Menu</q-item-section>
            </template>

            <q-item
                clickable
                v-ripple
                dense
                v-for="item in menuItems"
                :key="item"
                @click="onMenuItemClick(item)"
            >
                <q-item-section side>
                    <q-icon
                        color="indigo"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>{{ item.label }}</q-item-section>
            </q-item>
        </q-expansion-item>

        <q-separator />

        <!-- INFO -->
        <q-expansion-item v-model="menuInformationsExpanded">
            <template v-slot:header>
                <q-item-section side>
                    <q-avatar
                        icon="help_center"
                        color="teal"
                        text-color="white"
                        size="24px"
                    />
                </q-item-section>

                <q-item-section>Informations</q-item-section>
            </template>

            <!-- DATABASE DRIVER VERSION -->
            <q-item dense>
                <q-item-section side>
                    <q-icon
                        color="teal"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>
                    DB Driver Version:
                    {{
                        wm.module.ApplicationCore.shared().getDbDriverVersion()
                    }}
                </q-item-section>
            </q-item>

            <!-- WASM MODULE VERSION -->
            <q-item dense>
                <q-item-section side>
                    <q-icon
                        color="teal"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>
                    Wasm Module Version:
                    {{ wm.module.ApplicationCore.shared().getVersion() }}
                </q-item-section>
            </q-item>
        </q-expansion-item>
    </q-list>
</template>

<style scoped>
/* ignore */
</style>
