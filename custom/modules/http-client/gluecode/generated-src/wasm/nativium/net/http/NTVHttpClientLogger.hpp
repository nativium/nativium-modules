// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/wasm/djinni_wasm.hpp"
#include "nativium/net/http/HttpClientLogger.hpp"

namespace djinni_generated {

struct NTVHttpClientLogger : ::djinni::JsInterface<::nativium::net::http::HttpClientLogger, NTVHttpClientLogger> {
    using CppType = std::shared_ptr<::nativium::net::http::HttpClientLogger>;
    using CppOptType = std::shared_ptr<::nativium::net::http::HttpClientLogger>;
    using JsType = em::val;
    using Boxed = NTVHttpClientLogger;

    static CppType toCpp(JsType j) { return _fromJs(j); }
    static JsType fromCppOpt(const CppOptType& c) { return {_toJs(c)}; }
    static JsType fromCpp(const CppType& c) {
        djinni::checkForNull(c.get(), "NTVHttpClientLogger::fromCpp");
        return fromCppOpt(c);
    }

    static em::val cppProxyMethods();

    static void onRequest(const CppType& self, const em::val& w_request);
    static void onResponse(const CppType& self, const em::val& w_request,const em::val& w_response);

};

}  // namespace djinni_generated
