// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

import { Customer, DeviceData, InitializationData } from "./app-domain"

export interface ApplicationCore {
    initialize(initializationData: InitializationData, deviceData: DeviceData): void;
    getInitializationData(): InitializationData;
    getDeviceData(): DeviceData;
    getCustomer(): Customer;
    setCustomer(customer: Customer): void;
    getVersion(): string;
    getDbDriverVersion(): string;
    isInitialized(): boolean;
}
export interface ApplicationCore_statics {
    shared(): ApplicationCore;
}

export interface AppCore_statics {
    ApplicationCore: ApplicationCore_statics;
}
