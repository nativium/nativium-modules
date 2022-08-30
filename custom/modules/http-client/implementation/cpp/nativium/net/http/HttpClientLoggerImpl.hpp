#pragma once

#include "nativium/net/http/HttpClientLogger.hpp"

namespace nativium
{
namespace net
{
namespace http
{

class HttpClientLoggerImpl : public HttpClientLogger
{
public:
    void onRequest(const HttpRequest &request) override;
    void onResponse(const HttpRequest &request, const HttpResponse &response) override;
};

} // namespace http
} // namespace net
} // namespace nativium
