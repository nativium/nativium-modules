#include "ApplicationCoreImpl.hpp"
#include "nativium/helper/CustomerHelper.hpp"
#include "nativium/helper/DatabaseHelper.hpp"
#include "nativium/helper/SharedDataHelper.hpp"
#include "nativium/net/http/HttpClient.hpp"
#include "nativium/net/http/HttpClientLoggerImpl.hpp"
#include "nativium/util/Logger.hpp"

#include "SQLiteCpp/SQLiteCpp.h"

#include <iostream>
#include <map>
#include <sstream>
#include <string>

namespace nativium
{
namespace core
{

using namespace nativium::domain;
using namespace nativium::util;
using namespace nativium::net::http;
using namespace nativium::helper;

std::shared_ptr<ApplicationCoreImpl> ApplicationCoreImpl::instance = nullptr;

ApplicationCoreImpl::ApplicationCoreImpl()
{
    initialized = false;
}

std::shared_ptr<ApplicationCore> ApplicationCore::shared()
{
    return ApplicationCoreImpl::internalSharedInstance();
}

std::shared_ptr<ApplicationCoreImpl> ApplicationCoreImpl::internalSharedInstance()
{
    if (instance == nullptr)
    {
        instance = std::make_shared<ApplicationCoreImpl>();
    }

    return instance;
}

void ApplicationCoreImpl::initialize(const InitializationData &initializationData, const DeviceData &deviceData)
{
    Logger::shared()->i("Application initializing...");

    Logger::shared()->i("App ID: " + initializationData.appId);
    Logger::shared()->i("Name: " + initializationData.name);
    Logger::shared()->i("Base path: " + initializationData.basePath);

    this->initializationData = std::make_shared<InitializationData>(initializationData);
    this->deviceData = std::make_shared<DeviceData>(deviceData);

    initializeHttpClient();
    initializeHttpLogger();
    initializeDB();
    initializeCustomer();

    Logger::shared()->i("Application initialized");

    initialized = true;
}

bool ApplicationCoreImpl::isInitialized()
{
    return initialized;
}

void ApplicationCoreImpl::initializeDB()
{
    db = DatabaseHelper::initializeDatabase(initializationData->basePath);
    DatabaseHelper::migrateDatabase(db);
    Logger::shared()->i("Database initialized and migrated");
}

void ApplicationCoreImpl::initializeCustomer()
{
    auto currentCustomer = SharedDataHelper::getCustomer();
    customer = std::make_shared<Customer>(currentCustomer);
    Logger::shared()->i("Customer initialized");
}

void ApplicationCoreImpl::initializeHttpLogger()
{
    if (HttpClient::shared()->getLogger() == nullptr)
    {
        auto loggerPS = std::make_shared<HttpClientLoggerImpl>();
        HttpClient::shared()->setLogger(loggerPS);
    }
}

void ApplicationCoreImpl::initializeHttpClient()
{
    if (HttpClient::shared()->getPlatformService() == nullptr)
    {
        Logger::shared()->i("HTTP client is not initialized");
    }
}

InitializationData ApplicationCoreImpl::getInitializationData()
{
    return *initializationData;
}

DeviceData ApplicationCoreImpl::getDeviceData()
{
    return *deviceData;
}

Customer ApplicationCoreImpl::getCustomer()
{
    if (customer)
    {
        return *customer;
    }

    return CustomerHelper::create();
}

void ApplicationCoreImpl::setCustomer(const Customer &customer)
{
    this->customer = std::make_shared<Customer>(customer);
}

std::vector<HttpRequestParam> ApplicationCoreImpl::getDefaultHttpRequestParams()
{
    std::vector<HttpRequestParam> params = std::vector<HttpRequestParam>{};
    return params;
}

std::vector<HttpHeader> ApplicationCoreImpl::getDefaultHttpRequestHeaders()
{
    std::vector<HttpHeader> headers = std::vector<HttpHeader>{};

#ifndef __EMSCRIPTEN__
    headers.push_back(HttpHeader{"User-Agent", "Nativium Http Client"});
#endif

    return headers;
}

std::shared_ptr<SQLite::Database> ApplicationCoreImpl::getDB()
{
    return db;
}

std::string ApplicationCoreImpl::getVersion()
{
#ifdef NATIVIUM_CONFIG_VERSION
#define NATIVIUM_CONFIG_VERSION_STR NATIVIUM_CONFIG_VERSION
#else
#define NATIVIUM_CONFIG_VERSION_STR "1.0.0"
#endif

    return NATIVIUM_CONFIG_VERSION_STR;
}

std::string ApplicationCoreImpl::getDbDriverVersion()
{
    return std::string(SQLite::VERSION);
}

} // namespace core
} // namespace nativium
