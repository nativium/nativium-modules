<script setup>
import { useQuasar } from "quasar";
import { onMounted, ref } from "vue";
import { RouterView, useRouter } from "vue-router";
import AboutDataVue from "./components/AboutData.vue";
import SideBarVue from "./components/SideBar.vue";
import { useWasmModuleStore } from "./stores/wasm-module";

const wm = useWasmModuleStore();
const router = useRouter();
const q = useQuasar();
const splitterModel = ref(25);

function showLoading() {
    q.loading.show({
        message: "Loading...",
    });
}

function hideLoading() {
    q.loading.hide();
}

function doRestart() {
    router.go("/");
}

onMounted(() => {
    showLoading();
});

wm.$subscribe((mutation, state) => {
    if (state.loaded) {
        hideLoading();
    }
});
</script>

<template>
    <div>
        <q-layout view="lHh lpr lFf" class="shadow-2">
            <q-header elevated>
                <q-bar>
                    <q-icon name="laptop_chromebook" />
                    <div class="cursor-pointer" @click="$router.push('/')">
                        Nativium Modules
                    </div>
                    <q-space />

                    <div v-if="wm.isLoaded">
                        <q-badge>{{
                            wm.module.ApplicationCore.shared().getVersion()
                        }}</q-badge>
                    </div>
                </q-bar>

                <div class="q-pa-sm q-pl-md row items-center">
                    <div class="cursor-pointer non-selectable">
                        File
                        <q-menu>
                            <q-list dense style="min-width: 100px">
                                <q-item clickable v-close-popup>
                                    <q-item-section @click="doRestart()"
                                        >Restart</q-item-section
                                    >
                                </q-item>
                            </q-list>
                        </q-menu>
                    </div>

                    <div class="q-ml-md cursor-pointer non-selectable">
                        More
                        <q-menu auto-close>
                            <q-list dense style="min-width: 100px">
                                <q-item clickable>
                                    <q-item-section
                                        @click="$router.push('/about')"
                                        >About</q-item-section
                                    >
                                </q-item>
                            </q-list>
                        </q-menu>
                    </div>
                </div>
            </q-header>

            <q-page-container>
                <div v-if="wm.isLoaded">
                    <q-splitter v-model="splitterModel" class="main-splitter">
                        <!-- SIDE BAR -->
                        <template v-slot:before>
                            <SideBarVue />
                        </template>

                        <!-- CONTENT -->
                        <template v-slot:after>
                            <router-view v-slot="{ Component }">
                                <transition>
                                    <keep-alive :include="['MainView']">
                                        <component :is="Component"></component>
                                    </keep-alive>
                                </transition>
                            </router-view>
                        </template>
                    </q-splitter>
                </div>
                <div v-else>
                    <div class="container q-pa-md q-mt-xl text-center">
                        <img
                            alt="Nativium Modules Logo"
                            src="@/assets/logo.png"
                            width="128"
                            height="128"
                        />

                        <AboutDataVue />
                    </div>
                </div>
            </q-page-container>
        </q-layout>
    </div>
</template>

<style>
@import "@/assets/base.css";

.main-splitter {
    height: 100vh;
}
</style>
