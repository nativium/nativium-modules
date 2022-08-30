// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "nativium/domain/Customer.hpp"
#include "nativium/domain/Response.hpp"
#include <utility>

namespace nativium { namespace systemservice {

struct CustomerSystemServiceLoginData final {
    ::nativium::domain::Response response;
    ::nativium::domain::Customer customer;

    CustomerSystemServiceLoginData(::nativium::domain::Response response_,
                                   ::nativium::domain::Customer customer_)
    : response(std::move(response_))
    , customer(std::move(customer_))
    {}
};

} }  // namespace nativium::systemservice
