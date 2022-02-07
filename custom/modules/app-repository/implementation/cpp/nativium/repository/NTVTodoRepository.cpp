#include "nativium/repository/NTVTodoRepository.hpp"
#include "nativium/core/ApplicationCore.hpp"
#include "nativium/core/ApplicationCoreImpl.hpp"
#include "nativium/helper/DatabaseHelper.hpp"
#include "nativium/helper/MapHelper.hpp"
#include "nativium/helper/SimpleStringHelper.hpp"
#include "nativium/helper/TodoHelper.hpp"
#include "nativium/time/DateTime.hpp"

#include <string>

namespace nativium
{
namespace repository
{

using namespace nativium::helper;
using namespace nativium::domain;
using namespace nativium::time;
using namespace nativium::core;

Todo NTVTodoRepository::bindFromRow(SQLite::Statement &row)
{
    auto todo = TodoHelper::create();

    todo.id = row.getColumn("id").getInt64();
    todo.title = row.getColumn("title").getString();
    todo.body = row.getColumn("body").getString();
    todo.data = MapHelper::fromJsonString(row.getColumn("data"));
    todo.createdAt = DateTime::getDateTimeFromString(row.getColumn("created_at").getString());
    todo.updatedAt = DateTime::getDateTimeFromString(row.getColumn("updated_at").getString());

    if (row.getColumn("done").getInt() == 1)
    {
        todo.done = true;
    }
    else
    {
        todo.done = false;
    }

    return todo;
}

void TodoRepository::truncate()
{
    auto sql = "DELETE FROM todo; VACUUM;";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.exec();
}

int64_t TodoRepository::insert(const Todo &todo)
{
    auto sql =
        "INSERT INTO todo (title, body, data, done, created_at, updated_at) "
        "VALUES (:title, :body, :data, :done, :created_at, :updated_at)";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":title", todo.title);
    query.bind(":body", todo.body);
    query.bind(":data", MapHelper::toJsonString(todo.data));
    query.bind(":done", todo.done);
    query.bind(":created_at", DateTime::getStringFromDateTime(todo.createdAt));
    query.bind(":updated_at", DateTime::getStringFromDateTime(todo.updatedAt));
    query.exec();

    return db->getLastInsertRowid();
}

int64_t TodoRepository::update(int64_t id, const Todo &todo)
{
    auto sql =
        "UPDATE todo SET "
        "title = :title, "
        "body = :body, "
        "data = :data, "
        "done = :done, "
        "updated_at = :updated_at "
        "WHERE id = :id";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":id", id);
    query.bind(":title", todo.title);
    query.bind(":body", todo.body);
    query.bind(":data", MapHelper::toJsonString(todo.data));
    query.bind(":done", todo.done);
    query.bind(":updated_at", DateTime::getStringFromDateTime(todo.updatedAt));
    query.exec();

    return DatabaseHelper::getChanges(db);
}

int64_t TodoRepository::add(const Todo &todo)
{
    auto found = findById(todo.id);

    if (found.id > 0)
    {
        return update(found.id, todo);
    }
    else
    {
        return insert(todo);
    }
}

bool TodoRepository::removeById(int64_t id)
{
    auto sql = "DELETE FROM todo WHERE id = :id";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":id", id);
    query.exec();

    auto rows = DatabaseHelper::getChanges(db);

    return (rows > 0);
}

std::vector<Todo> TodoRepository::findAllOrderByCreatedAtDesc()
{
    auto sql = "SELECT * FROM todo ORDER BY created_at DESC";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    auto list = std::vector<Todo>{};

    while (query.executeStep())
    {
        auto todo = NTVTodoRepository::bindFromRow(query);
        list.push_back(todo);
    }

    return list;
}

std::vector<Todo> TodoRepository::findByTitle(const std::string &title)
{
    auto hasTitle = false;

    auto sql = std::string("SELECT * FROM todo WHERE 1=1");

    if (title.length() > 0)
    {
        sql = sql + " AND title LIKE :todo_title ";
        hasTitle = true;
    }

    sql = sql + " ORDER BY created_at DESC ";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    if (hasTitle)
    {
        query.bind(":todo_title", SimpleStringHelper::format("%%%s%%", title.c_str()));
    }

    auto list = std::vector<Todo>{};

    while (query.executeStep())
    {
        auto todo = NTVTodoRepository::bindFromRow(query);
        list.push_back(todo);
    }

    return list;
}

bool TodoRepository::setDoneById(int64_t id, bool done)
{
    auto sql = "UPDATE todo SET done = :done, updated_at = :updated_at WHERE id = :id";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":id", id);
    query.bind(":done", done);
    query.bind(":updated_at", DateTime::getStringFromDateTime(DateTime::getCurrentDateTime()));
    query.exec();

    auto rows = DatabaseHelper::getChanges(db);

    return (rows > 0);
}

int64_t TodoRepository::count()
{
    auto sql = "SELECT COUNT(*) AS qty FROM todo";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    while (query.executeStep())
    {
        return query.getColumn("qty").getInt();
    }

    return 0;
}

Todo TodoRepository::findById(int64_t id)
{
    auto sql = "SELECT * FROM todo WHERE id = :id LIMIT 1";

    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());
    auto db = application->getDB();

    SQLite::Statement query(*db, sql);

    query.bind(":id", id);

    while (query.executeStep())
    {
        auto todo = NTVTodoRepository::bindFromRow(query);
        return todo;
    }

    return TodoHelper::create();
}

} // namespace repository
} // namespace nativium
