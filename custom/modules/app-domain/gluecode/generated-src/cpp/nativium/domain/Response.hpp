// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "nativium/domain/ResponseError.hpp"
#include <string>
#include <utility>

namespace nativium { namespace domain {

struct Response final {
    bool success;
    std::string message;
    ResponseError error;
    bool hasError;

    Response(bool success_,
             std::string message_,
             ResponseError error_,
             bool hasError_)
    : success(std::move(success_))
    , message(std::move(message_))
    , error(std::move(error_))
    , hasError(std::move(hasError_))
    {}
};

} }  // namespace nativium::domain
