// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.nativium.helper;

import com.snapchat.djinni.NativeObjectManager;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class SecurityHelper {
    public static native String generateUuidV4();

    public static native String generateHash(String algorithm, String value);

    public static final class CppProxy extends SecurityHelper
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
    }
}
