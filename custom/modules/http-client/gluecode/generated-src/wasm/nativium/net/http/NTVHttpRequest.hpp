// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/wasm/djinni_wasm.hpp"
#include "nativium/net/http/HttpRequest.hpp"

namespace djinni_generated {

struct NTVHttpRequest
{
    using CppType = ::nativium::net::http::HttpRequest;
    using JsType = em::val;
    using Boxed = NTVHttpRequest;

    static CppType toCpp(const JsType& j);
    static JsType fromCpp(const CppType& c);
};

}  // namespace djinni_generated
