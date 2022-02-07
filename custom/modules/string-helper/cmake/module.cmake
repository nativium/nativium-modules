# module config
set(MODULE_NAME "string-helper")

# files
nativium_add_header_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp/nativium/helper/StringHelper*.hpp")
nativium_add_header_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/helper/StringHelper*.hpp")

nativium_add_source_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp/nativium/helper/StringHelper*.cpp")
nativium_add_source_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/helper/StringHelper*.cpp")

# search paths
nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/gluecode/generated-src/cpp")
nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp")
