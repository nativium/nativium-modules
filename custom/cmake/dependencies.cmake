# dependencies for tests
include(${NATIVIUM_ROOT_PATH}/cmake/dependencies-tests.cmake)

# openssl
find_package(OpenSSL CONFIG REQUIRED)
target_link_libraries(${NATIVIUM_PROJECT_NAME} PRIVATE OpenSSL::SSL)

# nlohmann json
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(${NATIVIUM_PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

# sqlite3
find_package(SQLite3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)

# sqlitecpp
find_package(SQLiteCpp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SQLiteCpp)

# date
find_package(date CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE date::date)

# poco
if(NOT NATIVIUM_TARGET STREQUAL "wasm")
    find_package(Poco CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE Poco::Poco)
endif()
