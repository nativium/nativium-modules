// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

import { Customer, Todo } from "./app-domain"

export interface CustomerHelper {
}
export interface CustomerHelper_statics {
    isLogged(): boolean;
    getToken(): string;
    create(): Customer;
    onCustomerLogin(customer: Customer): void;
}

export interface TodoHelper {
}
export interface TodoHelper_statics {
    create(): Todo;
}

export interface EnvironmentHelper {
}
export interface EnvironmentHelper_statics {
    getSecretKey(): string;
}

export interface SharedDataHelper {
}
export interface SharedDataHelper_statics {
    setCustomer(value: Customer): void;
    getCustomer(): Customer;
    storeCustomer(): void;
    setDemoFlag(value: boolean): void;
    getDemoFlag(): boolean;
}

export interface SecurityHelper {
}
export interface SecurityHelper_statics {
    generateUuidV4(): string;
    generateHash(algorithm: string, value: string): string;
}

export interface AppHelper_statics {
    CustomerHelper: CustomerHelper_statics;
    TodoHelper: TodoHelper_statics;
    EnvironmentHelper: EnvironmentHelper_statics;
    SharedDataHelper: SharedDataHelper_statics;
    SecurityHelper: SecurityHelper_statics;
}
