// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include <string>
#include <utility>

namespace nativium { namespace net { namespace http {

struct HttpRequestParam final {
    std::string name;
    std::string value;

    HttpRequestParam(std::string name_,
                     std::string value_)
    : name(std::move(name_))
    , value(std::move(value_))
    {}
};

} } }  // namespace nativium::net::http
