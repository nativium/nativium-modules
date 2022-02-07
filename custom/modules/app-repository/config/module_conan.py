from conans import ConanFile

from core import const as c


# -----------------------------------------------------------------------------
def configure(params={}):
    conanfile: ConanFile = params["conanfile"]

    if conanfile.settings.os in c.APPLE_MOBILE_OS_LIST:
        conanfile.options["sqlite3"].omit_load_extension = True
    else:
        conanfile.options["sqlite3"].omit_load_extension = False

    conanfile.options["sqlite3"].threadsafe = 1
    conanfile.options["sqlite3"].build_executable = False
    conanfile.options["sqlite3"].omit_load_extension = False


# -----------------------------------------------------------------------------
def requirements(params={}):
    conanfile: ConanFile = params["conanfile"]

    conanfile.requires("sqlite3/3.37.1")
    conanfile.requires("sqlitecpp/3.1.1")
