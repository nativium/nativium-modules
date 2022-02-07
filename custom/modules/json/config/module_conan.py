from conans import ConanFile


# -----------------------------------------------------------------------------
def configure(params={}):
    pass


# -----------------------------------------------------------------------------
def requirements(params={}):
    conanfile: ConanFile = params["conanfile"]

    conanfile.requires("nlohmann_json/3.9.1")
