// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/helper/NTVHelperEnvironmentHelper.hpp"  // my header

namespace djinni_generated {

em::val NTVHelperEnvironmentHelper::cppProxyMethods() {
    static const em::val methods = em::val::array(std::vector<std::string> {
    });
    return methods;
}

std::string NTVHelperEnvironmentHelper::getSecretKey() {
    try {
        auto r = ::nativium::helper::EnvironmentHelper::getSecretKey();
        return ::djinni::String::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni::String>::handleNativeException(e);
    }
}

EMSCRIPTEN_BINDINGS(nativium_helper_environment_helper) {
    em::class_<::nativium::helper::EnvironmentHelper>("EnvironmentHelper")
        .smart_ptr<std::shared_ptr<::nativium::helper::EnvironmentHelper>>("EnvironmentHelper")
        .function("nativeDestroy", &NTVHelperEnvironmentHelper::nativeDestroy)
        .class_function("getSecretKey", NTVHelperEnvironmentHelper::getSecretKey)
        ;
}

}  // namespace djinni_generated