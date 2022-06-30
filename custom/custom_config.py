import os


# -----------------------------------------------------------------------------
def run(params):
    return [
        {
            "type": "remove-dir",
            "path": "modules",
        },
        {
            "type": "symlink",
            "source": "modules",
            "target": "modules",
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
