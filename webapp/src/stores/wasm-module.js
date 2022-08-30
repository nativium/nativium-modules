import { defineStore } from "pinia";
import SimpleHttpClientPlatformService from "../classes/simple-http-client-ps";
import SimpleSharedDataPlatformService from "../classes/simple-shared-data-ps";

/**
 * @typedef {Object} WasmModule
 * @property {import("../../../nativium/modules/app-core/gluecode/generated-src/ts/app-core").ApplicationCore_statics} ApplicationCore
 * @property {import("../../../nativium/modules/file-helper/gluecode/generated-src/ts/file-helper").FileHelper_statics} FileHelper
 * @property {import("../../../nativium/modules/http-client/gluecode/generated-src/ts/http-client").HttpClient_statics} HttpClient
 * @property {import("../../../nativium/modules/shared-data/gluecode/generated-src/ts/shared-data").SharedData_statics} SharedData
 * @property {import("../../../nativium/modules/app-repository/gluecode/generated-src/ts/app-repository").TodoRepository_statics} TodoRepository
 * @property {import("../../../nativium/modules/logger/gluecode/generated-src/ts/logger").Logger_statics} Logger
 * @property {import("../../../nativium/modules/app-system-service/gluecode/generated-src/ts/app-system-service").CustomerSystemService_statics} CustomerSystemService
 * @property {import("../../../nativium/modules/app-helper/gluecode/generated-src/ts/app-helper").CustomerHelper_statics} CustomerHelper
 * @property {import("../../../nativium/modules/app-helper/gluecode/generated-src/ts/app-helper").TodoHelper_statics} TodoHelper
 * @property {import("../../../nativium/modules/app-helper/gluecode/generated-src/ts/app-helper").EnvironmentHelper_statics} EnvironmentHelper
 * @property {import("../../../nativium/modules/app-helper/gluecode/generated-src/ts/app-helper").SharedDataHelper_statics} SharedDataHelper
 * @property {import("../../../nativium/modules/app-helper/gluecode/generated-src/ts/app-helper").SecurityHelper_statics} SecurityHelper
 */

export const useWasmModuleStore = defineStore({
    id: "wasm-module",
    state: () => ({
        loaded: false,

        /** @type {WasmModule} */
        module: null,
    }),
    getters: {
        isLoaded: (state) => state.loaded,
    },
    actions: {
        setLoaded(value) {
            this.loaded = value;
        },
        initialize() {
            // http client platform service
            this.module.HttpClient.shared().setPlatformService(
                new SimpleHttpClientPlatformService()
            );

            // shared data platform service
            this.module.SharedData.shared().setPlatformService(
                new SimpleSharedDataPlatformService()
            );

            // general data
            /** @type {import("../../../nativium/modules/app-domain/gluecode/generated-src/ts/app-domain").InitializationData} */
            const initializationData = {
                appId: "com.nativium.sample",
                basePath: "/",
                databaseMigrationMaxVersion: -1,
                debug: true,
                name: "nativium",
            };

            /** @type {import("../../../nativium/modules/app-domain/gluecode/generated-src/ts/app-domain").DeviceData} */
            const deviceData = {
                appName: "Nativium Modules",
                appShortVersion: "",
                appVersion: "",
                imei: "",
                language: "",
                localizedModel: "",
                model: "",
                name: "browser",
                region: "",
                screenWidth: 0,
                screenHeight: 0,
                screenScale: 0,
                systemName: "",
                systemOsName: "",
                systemVersion: "",
                uniqueIdentifier: "",
            };

            // application core
            this.module.ApplicationCore.shared().initialize(
                initializationData,
                deviceData
            );

            this.module.Logger.d("Initialized!");
        },
    },
});
