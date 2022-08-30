// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "nativium/domain/Todo.hpp"
#include <cstdint>
#include <string>
#include <vector>

namespace nativium { namespace repository {

class TodoRepository {
public:
    virtual ~TodoRepository() = default;

    static void truncate();

    static ::nativium::domain::Todo findById(int64_t id);

    static std::vector<::nativium::domain::Todo> findAllOrderByCreatedAtDesc();

    static std::vector<::nativium::domain::Todo> findByTitle(const std::string & title);

    static bool removeById(int64_t id);

    static int64_t update(int64_t id, const ::nativium::domain::Todo & todo);

    static int64_t insert(const ::nativium::domain::Todo & todo);

    static int64_t add(const ::nativium::domain::Todo & todo);

    static bool setDoneById(int64_t id, bool done);

    static int64_t count();
};

} }  // namespace nativium::repository