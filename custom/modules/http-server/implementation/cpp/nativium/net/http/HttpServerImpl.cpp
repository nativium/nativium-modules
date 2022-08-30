#include "nativium/net/http/HttpServerImpl.hpp"

#include "nativium/core/ApplicationCore.hpp"
#include "nativium/io/FileHelper.hpp"
#include "nativium/util/Logger.hpp"

namespace nativium
{
namespace net
{

namespace http
{

using namespace nativium::net::http;
using namespace nativium::util;
using namespace nativium::core;
using namespace nativium::io;

std::shared_ptr<HttpServerImpl> HttpServerImpl::instance = nullptr;

HttpServerImpl::HttpServerImpl()
{
    running = false;
}

std::shared_ptr<HttpServer> HttpServer::shared()
{
    return HttpServerImpl::internalSharedInstance();
}

std::shared_ptr<HttpServerImpl> HttpServerImpl::internalSharedInstance()
{
    if (instance == nullptr)
    {
        instance = std::make_shared<HttpServerImpl>();
    }

    return instance;
}

void HttpServerImpl::initialize(const HttpServerConfig &config)
{
    serverConfig = std::make_shared<HttpServerConfig>(config);

    if (serverConfig->staticPath.empty())
    {
        // empty static path will be defined to application + webapp
        serverConfig->staticPath = FileHelper::join(ApplicationCore::shared()->getInitializationData().basePath, "webapp");
    }

    server = SimpleHttpServer::create(serverConfig);

    Logger::i("[HttpServerImpl : initialize] Server was initialized on port \"" + std::to_string(serverConfig->port) + "\" and static path \"" + serverConfig->staticPath + "\"");
}

std::shared_ptr<SimpleHttpServer> HttpServerImpl::getServer()
{
    return server;
}

HttpServerConfig HttpServerImpl::getConfig()
{
    return *serverConfig;
}

void HttpServerImpl::start()
{
    server->start();
    running = true;
}

void HttpServerImpl::stop()
{
    server->stop();
    running = false;
}

void HttpServerImpl::waitForTermination()
{
    server->waitForTermination();
}

int32_t HttpServerImpl::getSocketPort()
{
    return server->getSocketPort();
}

std::string HttpServerImpl::getSocketHost()
{
    return server->getSocketHost();
}

std::string HttpServerImpl::getSocketAddress()
{
    std::string prefix = isSocketSecure() ? "https" : "http";

    return prefix + "://" + getSocketHost() + ":" + std::to_string(getSocketPort());
}

bool HttpServerImpl::isSocketSecure()
{
    return server->isSocketSecure();
}

bool HttpServerImpl::isRunning()
{
    return running;
}

} // namespace http
} // namespace net
} // namespace nativium
