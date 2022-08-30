#pragma once

#include "nativium/domain/Response.hpp"
#include "nativium/domain/ResponseError.hpp"
#include "nativium/net/http/HttpResponse.hpp"

namespace nativium
{
namespace helper
{

using namespace nativium::domain;
using namespace nativium::net::http;

class ResponseHelper
{
public:
    virtual ~ResponseHelper() {}
    static Response fromHttpResponse(const HttpResponse httpResponse);
    static ResponseError createResponseError();
    static Response create();
    static Response create(const HttpResponse httpResponse);
};

} // namespace helper
} // namespace nativium
