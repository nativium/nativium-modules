#pragma once

#include "Poco/Net/HTTPServer.h"
#include "Poco/Util/ServerApplication.h"
#include "nativium/net/http/HttpServerConfig.hpp"

#include <memory>
#include <string>

namespace nativium
{
namespace net
{
namespace http
{

class SimpleHttpServer : public Poco::Util::ServerApplication
{
public:
    SimpleHttpServer(const std::shared_ptr<HttpServerConfig> &config);
    virtual ~SimpleHttpServer();

    static std::shared_ptr<SimpleHttpServer> create(const std::shared_ptr<HttpServerConfig> &config);
    void start();
    void stop();
    void waitForTermination();
    int32_t getSocketPort();
    std::string getSocketHost();
    bool isSocketSecure();

private:
    std::shared_ptr<Poco::Net::HTTPServer> server;
};

} // namespace http
} // namespace net
} // namespace nativium
