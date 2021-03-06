// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/util/LoggerLevel.hpp"

namespace djinni_generated {

class NTVLoggerLevel final : ::djinni::JniEnum {
public:
    using CppType = ::nativium::util::LoggerLevel;
    using JniType = jobject;

    using Boxed = NTVLoggerLevel;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NTVLoggerLevel>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NTVLoggerLevel>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NTVLoggerLevel() : JniEnum("com/nativium/util/LoggerLevel") {}
    friend ::djinni::JniClass<NTVLoggerLevel>;
};

}  // namespace djinni_generated
