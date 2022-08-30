#include "nativium/net/http/controller/HttpServerTodoController.hpp"

#include "nativium/domain/ResponseJson.hpp"
#include "nativium/domain/Todo.hpp"
#include "nativium/domain/TodoJson.hpp"
#include "nativium/helper/JsonHelper.hpp"
#include "nativium/helper/ResponseHelper.hpp"
#include "nativium/net/http/helper/HttpServerHelper.hpp"
#include "nativium/util/Logger.hpp"

#include "nativium/repository/TodoRepository.hpp"

#include "Poco/URI.h"

using namespace nativium::time;
using namespace nativium::helper;
using namespace nativium::repository;
using namespace nativium::util;
using namespace nativium::net::http::helper;

namespace nativium
{
namespace net
{
namespace http
{
namespace controller
{

bool HttpServerTodoController::process(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    Poco::URI uri(request.getURI());

    if (uri.getPath() == "/todo/list" && request.getMethod() == "GET")
    {
        actionTodoList(request, response);
        return true;
    }
    else if (uri.getPath() == "/todo/create" && request.getMethod() == "POST")
    {
        actionTodoCreate(request, response);
        return true;
    }
    else if (uri.getPath() == "/todo/update" && request.getMethod() == "POST")
    {
        actionTodoUpdate(request, response);
        return true;
    }
    else if (uri.getPath() == "/todo/delete" && request.getMethod() == "POST")
    {
        actionTodoDelete(request, response);
        return true;
    }
    else if (uri.getPath() == "/todo/done-by-id" && request.getMethod() == "POST")
    {
        actionTodoDoneById(request, response);
        return true;
    }

    return false;
}

void HttpServerTodoController::actionTodoList(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");

    std::ostream &responseStream = response.send();

    auto resp = ResponseHelper::create();
    resp.success = true;
    resp.message = "list";

    auto list = TodoRepository::findAllOrderByCreatedAtDesc();

    nlohmann::json json = resp;
    json["data"]["list"] = list;

    responseStream << json;
}

void HttpServerTodoController::actionTodoCreate(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");

    std::ostream &responseStream = response.send();

    auto resp = ResponseHelper::create();

    try
    {
        // create
        auto json = nlohmann::json::parse(HttpServerHelper::getRequestContent(request));
        auto todo = json.get<Todo>();

        todo.createdAt = DateTime::getCurrentDateTime();
        todo.updatedAt = DateTime::getCurrentDateTime();

        // insert
        todo.id = TodoRepository::insert(todo);

        if (todo.id > 0)
        {
            todo = TodoRepository::findById(todo.id);

            resp.success = true;
            resp.message = "created";

            nlohmann::json json = resp;

            json["data"]["todo"] = todo;

            responseStream << json;

            return;
        }
    }
    catch (std::exception &e)
    {
        Logger::e("[HttpServerTodoController : actionTodoCreate] Error: " + std::string(e.what()));
    }

    nlohmann::json json = resp;
    responseStream << json;
}

void HttpServerTodoController::actionTodoUpdate(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");

    std::ostream &responseStream = response.send();

    auto resp = ResponseHelper::create();

    try
    {
        // create
        auto json = nlohmann::json::parse(HttpServerHelper::getRequestContent(request));
        auto todo = json.get<Todo>();

        todo.updatedAt = DateTime::getCurrentDateTime();

        // update
        auto rows = TodoRepository::update(todo.id, todo);

        if (rows > 0)
        {
            todo = TodoRepository::findById(todo.id);

            resp.success = true;
            resp.message = "updated";

            nlohmann::json json = resp;

            json["data"]["todo"] = todo;

            responseStream << json;

            return;
        }
    }
    catch (std::exception &e)
    {
        Logger::e("[HttpServerTodoController : actionTodoUpdate] Error: " + std::string(e.what()));
    }

    nlohmann::json json = resp;
    responseStream << json;
}

void HttpServerTodoController::actionTodoDelete(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");

    std::ostream &responseStream = response.send();

    auto resp = ResponseHelper::create();

    try
    {
        // create
        auto json = nlohmann::json::parse(HttpServerHelper::getRequestContent(request));
        auto paramId = JsonHelper::getInt64(json, "id");

        // delete
        auto result = TodoRepository::removeById(paramId);

        if (result)
        {
            resp.success = true;
            resp.message = "deleted";

            nlohmann::json json = resp;
            responseStream << json;

            return;
        }
    }
    catch (std::exception &e)
    {
        Logger::e("[HttpServerTodoController : actionTodoDelete] Error: " + std::string(e.what()));
    }

    nlohmann::json json = resp;
    responseStream << json;
}

void HttpServerTodoController::actionTodoDoneById(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");

    std::ostream &responseStream = response.send();

    auto resp = ResponseHelper::create();

    try
    {
        // create
        auto json = nlohmann::json::parse(HttpServerHelper::getRequestContent(request));

        auto paramId = JsonHelper::getInt64(json, "id");
        auto paramDone = JsonHelper::getBool(json, "done");

        // update
        auto result = TodoRepository::setDoneById(paramId, paramDone);

        if (result)
        {
            auto todo = TodoRepository::findById(paramId);

            resp.success = true;
            resp.message = "updated";

            nlohmann::json json = resp;

            json["data"]["todo"] = todo;

            responseStream << json;

            return;
        }
    }
    catch (std::exception &e)
    {
        Logger::e("[HttpServerTodoController : actionTodoDoneById] Error: " + std::string(e.what()));
    }

    nlohmann::json json = resp;
    responseStream << json;
}

} // namespace controller
} // namespace http
} // namespace net
} // namespace nativium
