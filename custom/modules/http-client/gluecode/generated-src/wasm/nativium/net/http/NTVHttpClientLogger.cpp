// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/net/http/NTVHttpClientLogger.hpp"  // my header
#include "nativium/net/http/NTVHttpRequest.hpp"
#include "nativium/net/http/NTVHttpResponse.hpp"

namespace djinni_generated {

em::val NTVHttpClientLogger::cppProxyMethods() {
    static const em::val methods = em::val::array(std::vector<std::string> {
        "onRequest",
        "onResponse",
    });
    return methods;
}

void NTVHttpClientLogger::onRequest(const CppType& self, const em::val& w_request) {
    try {
        self->onRequest(::djinni_generated::NTVHttpRequest::toCpp(w_request));
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<void>::handleNativeException(e);
    }
}
void NTVHttpClientLogger::onResponse(const CppType& self, const em::val& w_request,const em::val& w_response) {
    try {
        self->onResponse(::djinni_generated::NTVHttpRequest::toCpp(w_request),
                   ::djinni_generated::NTVHttpResponse::toCpp(w_response));
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<void>::handleNativeException(e);
    }
}

EMSCRIPTEN_BINDINGS(nativium_net_http_http_client_logger) {
    em::class_<::nativium::net::http::HttpClientLogger>("HttpClientLogger")
        .smart_ptr<std::shared_ptr<::nativium::net::http::HttpClientLogger>>("HttpClientLogger")
        .function("nativeDestroy", &NTVHttpClientLogger::nativeDestroy)
        .function("onRequest", NTVHttpClientLogger::onRequest)
        .function("onResponse", NTVHttpClientLogger::onResponse)
        ;
}

}  // namespace djinni_generated
