from conan import ConanFile


# -----------------------------------------------------------------------------
def configure(params={}):
    pass


# -----------------------------------------------------------------------------
def requirements(params={}):
    conanfile: ConanFile = params["conanfile"]

    conanfile.requires("nlohmann_json/3.12.0")
    conanfile.requires("openssl/1.1.1w")
