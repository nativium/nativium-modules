// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

namespace nativium { namespace net { namespace http {

struct HttpRequest;
struct HttpResponse;

class HttpClientPlatformService {
public:
    virtual ~HttpClientPlatformService() = default;

    virtual HttpResponse doRequest(const HttpRequest & request) = 0;
};

} } }  // namespace nativium::net::http