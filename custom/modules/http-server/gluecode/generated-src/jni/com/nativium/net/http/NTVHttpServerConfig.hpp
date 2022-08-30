// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/net/http/HttpServerConfig.hpp"

namespace djinni_generated {

class NTVHttpServerConfig final {
public:
    using CppType = ::nativium::net::http::HttpServerConfig;
    using JniType = jobject;

    using Boxed = NTVHttpServerConfig;

    ~NTVHttpServerConfig();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NTVHttpServerConfig();
    friend ::djinni::JniClass<NTVHttpServerConfig>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nativium/net/http/HttpServerConfig") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(ILjava/lang/String;)V") };
    const jfieldID field_mPort { ::djinni::jniGetFieldID(clazz.get(), "mPort", "I") };
    const jfieldID field_mStaticPath { ::djinni::jniGetFieldID(clazz.get(), "mStaticPath", "Ljava/lang/String;") };
};

}  // namespace djinni_generated