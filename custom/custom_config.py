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
            "type": "remove-dir",
            "path": os.path.join("modules", "app-wasm"),
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
            "source": os.path.join("modules", "app-main"),
            "target": os.path.join("modules", "app-main"),
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
    ]
