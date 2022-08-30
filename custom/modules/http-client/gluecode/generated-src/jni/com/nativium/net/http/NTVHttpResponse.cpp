// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/nativium/net/http/NTVHttpResponse.hpp"  // my header
#include "com/nativium/net/http/NTVHttpCookie.hpp"
#include "com/nativium/net/http/NTVHttpHeader.hpp"
#include "djinni/jni/Marshal.hpp"

namespace djinni_generated {

NTVHttpResponse::NTVHttpResponse() = default;

NTVHttpResponse::~NTVHttpResponse() = default;

auto NTVHttpResponse::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NTVHttpResponse>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c.code)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.body)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.url)),
                                                           ::djinni::get(::djinni::List<::djinni_generated::NTVHttpHeader>::fromCpp(jniEnv, c.headers)),
                                                           ::djinni::get(::djinni::List<::djinni_generated::NTVHttpCookie>::fromCpp(jniEnv, c.cookies)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NTVHttpResponse::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 6);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NTVHttpResponse>::get();
    return {::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_mCode)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mBody)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mUrl)),
            ::djinni::List<::djinni_generated::NTVHttpHeader>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mHeaders)),
            ::djinni::List<::djinni_generated::NTVHttpCookie>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mCookies))};
}

}  // namespace djinni_generated