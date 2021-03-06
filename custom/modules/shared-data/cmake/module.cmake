# module config
set(MODULE_NAME "shared-data")

# files
nativium_add_header_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp/nativium/data/SharedData*.hpp")
nativium_add_header_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/data/SharedData*.hpp")

nativium_add_source_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp/nativium/data/SharedData*.cpp")
nativium_add_source_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/data/SharedData*.cpp")

# search paths
nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp")
nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp")

# platform data
if(NATIVIUM_TARGET STREQUAL "android")
    # files
    nativium_add_header_files_gr("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/jni/*.hpp")
    nativium_add_source_files_gr("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/jni/*.cpp")

    # search paths
    nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/jni")
elseif(NATIVIUM_TARGET STREQUAL "ios")
    # files
    nativium_add_header_files_gr("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/objc/*.h")
    nativium_add_header_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/objc/nativium/data/*.h")
    nativium_add_source_files_gr("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/objc/*.mm")
    nativium_add_source_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/objc/nativium/data/*.m")

    # search paths
    nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/objc")
elseif(NATIVIUM_TARGET STREQUAL "wasm")
    # files
    nativium_add_header_files_gr("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/wasm/*.hpp")
    nativium_add_source_files_gr("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/wasm/*.cpp")

    # search paths
    nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/wasm")
elseif("${NATIVIUM_TARGET}" MATCHES "^(linux|macos|windows)$")
    # files
    nativium_add_header_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/data/Simple*.hpp")
    nativium_add_source_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/data/Simple*.cpp")
endif()
