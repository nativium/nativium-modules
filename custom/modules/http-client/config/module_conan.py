from conan import ConanFile


# -----------------------------------------------------------------------------
def configure(params={}):
    conanfile: ConanFile = params["conanfile"]

    conanfile.options["poco"].enable_apacheconnector = False
    conanfile.options["poco"].enable_cppparser = False
    conanfile.options["poco"].enable_crypto = True
    conanfile.options["poco"].enable_data = False
    conanfile.options["poco"].enable_data_mysql = False
    conanfile.options["poco"].enable_data_postgresql = False
    conanfile.options["poco"].enable_data_sqlite = False
    conanfile.options["poco"].enable_data_odbc = False
    conanfile.options["poco"].enable_encodings = False
    conanfile.options["poco"].enable_json = True
    conanfile.options["poco"].enable_jwt = True
    conanfile.options["poco"].enable_mongodb = False
    conanfile.options["poco"].enable_net = True
    conanfile.options["poco"].enable_pdf = False
    conanfile.options["poco"].enable_pagecompiler = False
    conanfile.options["poco"].enable_pagecompiler_file2page = False
    conanfile.options["poco"].enable_pocodoc = False
    conanfile.options["poco"].enable_redis = False
    conanfile.options["poco"].enable_sevenzip = False
    conanfile.options["poco"].enable_util = True
    conanfile.options["poco"].enable_xml = True
    conanfile.options["poco"].enable_zip = False
    conanfile.options["poco"].enable_activerecord = False

    if conanfile.settings.os == "Windows":
        conanfile.options["poco"].enable_netssl = False
        conanfile.options["poco"].enable_netssl_win = True
    else:
        conanfile.options["poco"].enable_netssl = True

    if conanfile.settings.os == "tvOS":
        conanfile.options["poco"].enable_fork = False
        conanfile.options["pcre2"].grep_support_callout_fork = False
    elif conanfile.settings.os == "watchOS":
        conanfile.options["poco"].enable_fork = False
        conanfile.options["pcre2"].grep_support_callout_fork = False


# -----------------------------------------------------------------------------
def requirements(params={}):
    conanfile: ConanFile = params["conanfile"]

    conanfile.requires("nlohmann_json/3.11.2")

    if conanfile.settings.os != "Emscripten":
        conanfile.requires("openssl/1.1.1s")
        conanfile.requires("poco/1.12.2")
