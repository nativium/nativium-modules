// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/net/http/NTVHttpServer.hpp"  // my header
#include "nativium/net/http/NTVHttpServerConfig.hpp"

namespace djinni_generated {

em::val NTVHttpServer::cppProxyMethods() {
    static const em::val methods = em::val::array(std::vector<std::string> {
        "initialize",
        "getConfig",
        "start",
        "stop",
        "waitForTermination",
        "getSocketPort",
        "getSocketHost",
        "getSocketAddress",
        "isSocketSecure",
        "isRunning",
    });
    return methods;
}

em::val NTVHttpServer::shared() {
    try {
        auto r = ::nativium::net::http::HttpServer::shared();
        return ::djinni_generated::NTVHttpServer::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni_generated::NTVHttpServer>::handleNativeException(e);
    }
}
void NTVHttpServer::initialize(const CppType& self, const em::val& w_config) {
    try {
        self->initialize(::djinni_generated::NTVHttpServerConfig::toCpp(w_config));
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<void>::handleNativeException(e);
    }
}
em::val NTVHttpServer::getConfig(const CppType& self) {
    try {
        auto r = self->getConfig();
        return ::djinni_generated::NTVHttpServerConfig::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni_generated::NTVHttpServerConfig>::handleNativeException(e);
    }
}
void NTVHttpServer::start(const CppType& self) {
    try {
        self->start();
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<void>::handleNativeException(e);
    }
}
void NTVHttpServer::stop(const CppType& self) {
    try {
        self->stop();
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<void>::handleNativeException(e);
    }
}
void NTVHttpServer::waitForTermination(const CppType& self) {
    try {
        self->waitForTermination();
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<void>::handleNativeException(e);
    }
}
int32_t NTVHttpServer::getSocketPort(const CppType& self) {
    try {
        auto r = self->getSocketPort();
        return ::djinni::I32::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni::I32>::handleNativeException(e);
    }
}
std::string NTVHttpServer::getSocketHost(const CppType& self) {
    try {
        auto r = self->getSocketHost();
        return ::djinni::String::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni::String>::handleNativeException(e);
    }
}
std::string NTVHttpServer::getSocketAddress(const CppType& self) {
    try {
        auto r = self->getSocketAddress();
        return ::djinni::String::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni::String>::handleNativeException(e);
    }
}
bool NTVHttpServer::isSocketSecure(const CppType& self) {
    try {
        auto r = self->isSocketSecure();
        return ::djinni::Bool::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni::Bool>::handleNativeException(e);
    }
}
bool NTVHttpServer::isRunning(const CppType& self) {
    try {
        auto r = self->isRunning();
        return ::djinni::Bool::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni::Bool>::handleNativeException(e);
    }
}

EMSCRIPTEN_BINDINGS(nativium_net_http_http_server) {
    em::class_<::nativium::net::http::HttpServer>("HttpServer")
        .smart_ptr<std::shared_ptr<::nativium::net::http::HttpServer>>("HttpServer")
        .function("nativeDestroy", &NTVHttpServer::nativeDestroy)
        .class_function("shared", NTVHttpServer::shared)
        .function("initialize", NTVHttpServer::initialize)
        .function("getConfig", NTVHttpServer::getConfig)
        .function("start", NTVHttpServer::start)
        .function("stop", NTVHttpServer::stop)
        .function("waitForTermination", NTVHttpServer::waitForTermination)
        .function("getSocketPort", NTVHttpServer::getSocketPort)
        .function("getSocketHost", NTVHttpServer::getSocketHost)
        .function("getSocketAddress", NTVHttpServer::getSocketAddress)
        .function("isSocketSecure", NTVHttpServer::isSocketSecure)
        .function("isRunning", NTVHttpServer::isRunning)
        ;
}

}  // namespace djinni_generated
