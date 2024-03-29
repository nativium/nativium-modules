// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/domain/Response.hpp"

namespace djinni_generated {

class NTVDomainResponse final {
public:
    using CppType = ::nativium::domain::Response;
    using JniType = jobject;

    using Boxed = NTVDomainResponse;

    ~NTVDomainResponse();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NTVDomainResponse();
    friend ::djinni::JniClass<NTVDomainResponse>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nativium/domain/Response") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(ZLjava/lang/String;Lcom/nativium/domain/ResponseError;ZLcom/nativium/net/http/HttpResponse;)V") };
    const jfieldID field_mSuccess { ::djinni::jniGetFieldID(clazz.get(), "mSuccess", "Z") };
    const jfieldID field_mMessage { ::djinni::jniGetFieldID(clazz.get(), "mMessage", "Ljava/lang/String;") };
    const jfieldID field_mError { ::djinni::jniGetFieldID(clazz.get(), "mError", "Lcom/nativium/domain/ResponseError;") };
    const jfieldID field_mHasError { ::djinni::jniGetFieldID(clazz.get(), "mHasError", "Z") };
    const jfieldID field_mHttpResponse { ::djinni::jniGetFieldID(clazz.get(), "mHttpResponse", "Lcom/nativium/net/http/HttpResponse;") };
};

}  // namespace djinni_generated
