# module config
set(MODULE_NAME "json")

# files
nativium_add_header_files_g("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp/nativium/json/*.hpp")

# search paths
nativium_add_search_path("${NATIVIUM_MODULES_PATH}/${MODULE_NAME}/implementation/cpp")
