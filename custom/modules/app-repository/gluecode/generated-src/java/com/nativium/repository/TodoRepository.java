// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.nativium.repository;

import com.snapchat.djinni.NativeObjectManager;
import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class TodoRepository {
    public static native void truncate();

    public static native com.nativium.domain.Todo findById(long id);

    public static native ArrayList<com.nativium.domain.Todo> findAllOrderByCreatedAtDesc();

    public static native ArrayList<com.nativium.domain.Todo> findByTitle(String title);

    public static native boolean removeById(long id);

    public static native long update(long id, com.nativium.domain.Todo todo);

    public static native long insert(com.nativium.domain.Todo todo);

    public static native long add(com.nativium.domain.Todo todo);

    public static native boolean setDoneById(long id, boolean done);

    public static native long count();

    public static final class CppProxy extends TodoRepository
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
