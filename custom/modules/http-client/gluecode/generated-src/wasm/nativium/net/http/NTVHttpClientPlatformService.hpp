// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/wasm/djinni_wasm.hpp"
#include "nativium/net/http/HttpClientPlatformService.hpp"

namespace djinni_generated {

struct NTVHttpClientPlatformService : ::djinni::JsInterface<::nativium::net::http::HttpClientPlatformService, NTVHttpClientPlatformService> {
    using CppType = std::shared_ptr<::nativium::net::http::HttpClientPlatformService>;
    using CppOptType = std::shared_ptr<::nativium::net::http::HttpClientPlatformService>;
    using JsType = em::val;
    using Boxed = NTVHttpClientPlatformService;

    static CppType toCpp(JsType j) { return _fromJs(j); }
    static JsType fromCppOpt(const CppOptType& c) { return {_toJs(c)}; }
    static JsType fromCpp(const CppType& c) {
        djinni::checkForNull(c.get(), "NTVHttpClientPlatformService::fromCpp");
        return fromCppOpt(c);
    }

    static em::val cppProxyMethods();

    static em::val doRequest(const CppType& self, const em::val& w_request);

    struct JsProxy: ::djinni::JsProxyBase, ::nativium::net::http::HttpClientPlatformService, ::djinni::InstanceTracker<JsProxy> {
        JsProxy(const em::val& v) : JsProxyBase(v) {}
        ::nativium::net::http::HttpResponse doRequest(const ::nativium::net::http::HttpRequest & request) override;
    };
};

}  // namespace djinni_generated
