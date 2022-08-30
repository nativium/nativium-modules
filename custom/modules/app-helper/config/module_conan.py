from conans import ConanFile


# -----------------------------------------------------------------------------
def configure(params={}):
    pass


# -----------------------------------------------------------------------------
def requirements(params={}):
    conanfile: ConanFile = params["conanfile"]

    conanfile.requires("nlohmann_json/3.11.2")
    conanfile.requires("openssl/1.1.1q")
