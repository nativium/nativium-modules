# module config
set(MODULE_NAME "file-helper")

# files
nativium_add_header_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp/nativium/io/FileHelper*.hpp" GLOB)
nativium_add_header_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/io/FileHelper*.hpp" GLOB)

nativium_add_source_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp/nativium/io/FileHelper*.cpp" GLOB)
nativium_add_source_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/io/FileHelper*.cpp" GLOB)

# search paths
nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp")
nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp")

# platform data
if(NATIVIUM_TARGET STREQUAL "android")
    # files
    nativium_add_header_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/jni/*.hpp" RECURSIVE)
    nativium_add_source_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/jni/*.cpp" RECURSIVE)

    # search paths
    nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/jni")
elseif(NATIVIUM_TARGET STREQUAL "ios")
    # files
    nativium_add_header_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/objc/*.h" RECURSIVE INSTALL INSTALL_FILTER "Private.h")
    nativium_add_header_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/objc/nativium/io/*.h" GLOB INSTALL INSTALL_FILTER "Private.h")
    nativium_add_source_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/objc/*.mm" RECURSIVE)
    nativium_add_source_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/objc/nativium/io/*.m" GLOB)

    # search paths
    nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/objc")
elseif(NATIVIUM_TARGET STREQUAL "wasm")
    # files
    nativium_add_header_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/wasm/*.hpp" RECURSIVE)
    nativium_add_source_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/wasm/*.cpp" RECURSIVE)

    nativium_add_header_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/io/Simple*.hpp" GLOB)
    nativium_add_source_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/io/Simple*.cpp" GLOB)

    # search paths
    nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/wasm")
elseif("${NATIVIUM_TARGET}" MATCHES "^(linux|macos|windows)$")
    # files
    nativium_add_header_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/io/Simple*.hpp" GLOB)
    nativium_add_source_files("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/io/Simple*.cpp" GLOB)
endif()
