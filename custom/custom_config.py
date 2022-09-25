import os
import textwrap


# -----------------------------------------------------------------------------
def run(params):
    return [
        {
            "type": "remove-dir",
            "path": os.path.join("modules", "tests"),
        },
        {
            "type": "remove-dir",
            "path": os.path.join("modules", "app-core"),
        },
        {
            "type": "remove-dir",
            "path": os.path.join("modules", "app-main"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "app-main"),
            "target": os.path.join("modules", "app-main"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "app-core"),
            "target": os.path.join("modules", "app-core"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "app-domain"),
            "target": os.path.join("modules", "app-domain"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "app-enumerator"),
            "target": os.path.join("modules", "app-enumerator"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "app-helper"),
            "target": os.path.join("modules", "app-helper"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "app-repository"),
            "target": os.path.join("modules", "app-repository"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "app-system-service"),
            "target": os.path.join("modules", "app-system-service"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "datetime"),
            "target": os.path.join("modules", "datetime"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "file-helper"),
            "target": os.path.join("modules", "file-helper"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "http-client"),
            "target": os.path.join("modules", "http-client"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "http-server"),
            "target": os.path.join("modules", "http-server"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "json"),
            "target": os.path.join("modules", "json"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "logger"),
            "target": os.path.join("modules", "logger"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "shared-data"),
            "target": os.path.join("modules", "shared-data"),
        },
        {
            "type": "symlink",
            "source": os.path.join("modules", "string-helper"),
            "target": os.path.join("modules", "string-helper"),
        },
        {
            "type": "copy-file",
            "source": "cmake/dependencies.cmake",
            "target": "cmake/dependencies.cmake",
        },
        {
            "type": "replace-text",
            "path": "core/const.py",
            "list": [
                {
                    "old": 'BUCKET_NAME = "nativium"',
                    "new": 'BUCKET_NAME = "nativium-modules"',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "config/gluecode.py",
            "list": [
                {
                    "old": '"order": []',
                    "new": '"order": ["app-enumerator", "app-domain", "app-helper", "app-repository", "app-system-service", "app-core"]',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "CMakeLists.txt",
            "list": [
                {
                    "old": 'set(NATIVIUM_C_FLAGS "-Wall" CACHE STRING "Custom C Flags")',
                    "new": textwrap.dedent("""\
                    if(NATIVIUM_TARGET STREQUAL "wasm")
                        set(NATIVIUM_C_FLAGS "-Wall -fwasm-exceptions" CACHE STRING "Custom C Flags")
                    else()
                        set(NATIVIUM_C_FLAGS "-Wall" CACHE STRING "Custom C Flags")
                    endif()
                    """)
                },
                {
                    "old": 'set(NATIVIUM_CXX_FLAGS "-Wall" CACHE STRING "Custom CXX Flags")',
                    "new": textwrap.dedent("""\
                    if(NATIVIUM_TARGET STREQUAL "wasm")
                        set(NATIVIUM_CXX_FLAGS "-Wall -fwasm-exceptions" CACHE STRING "Custom CXX Flags")
                    else()
                        set(NATIVIUM_CXX_FLAGS "-Wall" CACHE STRING "Custom CXX Flags")
                    endif()
                    """)
                },
                {
                    "old": 'set(NATIVIUM_WASM_LINK_FLAGS "--bind -s MALLOC=emmalloc -s WASM_BIGINT=1")',
                    "new": textwrap.dedent("""\
                    set(NATIVIUM_WASM_LINK_FLAGS "--bind -s MALLOC=emmalloc -s WASM_BIGINT=1 -fwasm-exceptions -sMODULARIZE -s EXPORT_ES6=1 -s EXPORTED_RUNTIME_METHODS=['FS']")"""),
                },
            ],
        },
    ]
