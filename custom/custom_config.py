import os


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
            "path": "targets/wasm/config/target.py",
            "list": [
                {
                    "old": 'has_debug = True',
                    "new": 'has_debug = False',
                },
            ],
        },
        {
            "type": "replace-text",
            "path": "targets/wasm/cmake/target.cmake",
            "list": [
                {
                    "old": 'set(NATIVIUM_WASM_C_FLAGS "")',
                    "new": 'set(NATIVIUM_WASM_C_FLAGS "-fwasm-exceptions")',
                },
                {
                    "old": 'set(NATIVIUM_WASM_CXX_FLAGS "")',
                    "new": 'set(NATIVIUM_WASM_CXX_FLAGS "-fwasm-exceptions")',
                },
                {
                    "old": '"--bind -s MALLOC=emmalloc -s WASM_BIGINT=1"',
                    "new": "\"--bind -s MALLOC=emmalloc -s WASM_BIGINT=1 -fwasm-exceptions -sMODULARIZE -s EXPORT_ES6=1 -s EXPORTED_RUNTIME_METHODS=['FS']\"",
                },
            ],
        },
    ]
