// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/nativium/net/http/NTVHttpClientPlatformService.hpp"  // my header
#include "com/nativium/net/http/NTVHttpRequest.hpp"
#include "com/nativium/net/http/NTVHttpResponse.hpp"

namespace djinni_generated {

NTVHttpClientPlatformService::NTVHttpClientPlatformService() : ::djinni::JniInterface<::nativium::net::http::HttpClientPlatformService, NTVHttpClientPlatformService>("com/nativium/net/http/HttpClientPlatformService$CppProxy") {}

NTVHttpClientPlatformService::~NTVHttpClientPlatformService() = default;

NTVHttpClientPlatformService::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NTVHttpClientPlatformService::JavaProxy::~JavaProxy() = default;

::nativium::net::http::HttpResponse NTVHttpClientPlatformService::JavaProxy::doRequest(const ::nativium::net::http::HttpRequest & c_request) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVHttpClientPlatformService>::get();
    auto jret = jniEnv->CallObjectMethod(Handle::get().get(), data.method_doRequest,
                                         ::djinni::get(::djinni_generated::NTVHttpRequest::fromCpp(jniEnv, c_request)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni_generated::NTVHttpResponse::toCpp(jniEnv, jret);
}

CJNIEXPORT void JNICALL Java_com_nativium_net_http_HttpClientPlatformService_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        delete reinterpret_cast<::djinni::CppProxyHandle<::nativium::net::http::HttpClientPlatformService>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_nativium_net_http_HttpClientPlatformService_00024CppProxy_native_1doRequest(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_request)
{
    try {
        const auto& ref = ::djinni::objectFromHandleAddress<::nativium::net::http::HttpClientPlatformService>(nativeRef);
        auto r = ref->doRequest(::djinni_generated::NTVHttpRequest::toCpp(jniEnv, j_request));
        return ::djinni::release(::djinni_generated::NTVHttpResponse::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated