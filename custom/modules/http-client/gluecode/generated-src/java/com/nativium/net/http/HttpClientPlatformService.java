// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.nativium.net.http;

import com.snapchat.djinni.NativeObjectManager;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class HttpClientPlatformService {
    public abstract HttpResponse doRequest(HttpRequest request);

    public static final class CppProxy extends HttpClientPlatformService
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
        public HttpResponse doRequest(HttpRequest request)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_doRequest(this.nativeRef, request);
        }
        private native HttpResponse native_doRequest(long _nativeRef, HttpRequest request);
    }
}