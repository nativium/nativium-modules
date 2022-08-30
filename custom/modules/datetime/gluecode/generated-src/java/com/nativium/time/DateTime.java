// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.nativium.time;

import com.snapchat.djinni.NativeObjectManager;
import java.util.Date;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class DateTime {
    public static native Date getDateTimeFromString(String value);

    public static native String getStringFromDateTime(Date value);

    public static native Date getDateTimeFromStringWithFormat(String value, String format);

    public static native String getCurrentDateTimeAsString();

    public static native Date getCurrentDateTime();

    public static native Date getDateTimeFromSeconds(long value);

    public static native Date getDateTimeFromMilliseconds(long value);

    public static native long getTimestampInMillisecondsFromDateTime(Date value);

    public static native long getTimestampInSecondsFromDateTime(Date value);

    public static native String getCurrentTimestampInSecondsAsString();

    public static native long getCurrentTimestampInSeconds();

    public static native String getCurrentTimestampInMillisecondsAsString();

    public static native long getCurrentTimestampInMilliseconds();

    public static native String getFormattedStringFromDateTime(Date value, String format);

    public static native long getMillisecondsFromTimeString(String value);

    public static native Date getDateTimeFromTimeInPosixTimezone(String time, String timezone);

    public static final class CppProxy extends DateTime
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