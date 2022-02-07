from conans import ConanFile


# -----------------------------------------------------------------------------
def configure(params={}):
    pass


# -----------------------------------------------------------------------------
def requirements(params={}):
    conanfile: ConanFile = params["conanfile"]

    conanfile.requires("rapidjson/1.1.0")
