// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.nativium.core;

import com.snapchat.djinni.NativeObjectManager;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class ApplicationCore {
    public abstract void initialize(com.nativium.domain.InitializationData initializationData, com.nativium.domain.DeviceData deviceData);

    public abstract com.nativium.domain.InitializationData getInitializationData();

    public abstract com.nativium.domain.DeviceData getDeviceData();

    public abstract com.nativium.domain.Customer getCustomer();

    public abstract void setCustomer(com.nativium.domain.Customer customer);

    public abstract String getVersion();

    public abstract String getDbDriverVersion();

    public abstract boolean isInitialized();

    public static native ApplicationCore shared();

    public static final class CppProxy extends ApplicationCore
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
            NativeObjectManager.register(this, nativeRef);
        }
        public static native void nativeDestroy(long nativeRef);

        @Override
        public void initialize(com.nativium.domain.InitializationData initializationData, com.nativium.domain.DeviceData deviceData)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_initialize(this.nativeRef, initializationData, deviceData);
        }
        private native void native_initialize(long _nativeRef, com.nativium.domain.InitializationData initializationData, com.nativium.domain.DeviceData deviceData);

        @Override
        public com.nativium.domain.InitializationData getInitializationData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getInitializationData(this.nativeRef);
        }
        private native com.nativium.domain.InitializationData native_getInitializationData(long _nativeRef);

        @Override
        public com.nativium.domain.DeviceData getDeviceData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getDeviceData(this.nativeRef);
        }
        private native com.nativium.domain.DeviceData native_getDeviceData(long _nativeRef);

        @Override
        public com.nativium.domain.Customer getCustomer()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getCustomer(this.nativeRef);
        }
        private native com.nativium.domain.Customer native_getCustomer(long _nativeRef);

        @Override
        public void setCustomer(com.nativium.domain.Customer customer)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setCustomer(this.nativeRef, customer);
        }
        private native void native_setCustomer(long _nativeRef, com.nativium.domain.Customer customer);

        @Override
        public String getVersion()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getVersion(this.nativeRef);
        }
        private native String native_getVersion(long _nativeRef);

        @Override
        public String getDbDriverVersion()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getDbDriverVersion(this.nativeRef);
        }
        private native String native_getDbDriverVersion(long _nativeRef);

        @Override
        public boolean isInitialized()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_isInitialized(this.nativeRef);
        }
        private native boolean native_isInitialized(long _nativeRef);
    }
}
