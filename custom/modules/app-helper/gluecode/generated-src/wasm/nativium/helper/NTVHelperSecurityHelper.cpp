// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/helper/NTVHelperSecurityHelper.hpp"  // my header

namespace djinni_generated {

em::val NTVHelperSecurityHelper::cppProxyMethods() {
    static const em::val methods = em::val::array(std::vector<std::string> {
    });
    return methods;
}

std::string NTVHelperSecurityHelper::generateUuidV4() {
    try {
        auto r = ::nativium::helper::SecurityHelper::generateUuidV4();
        return ::djinni::String::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni::String>::handleNativeException(e);
    }
}

EMSCRIPTEN_BINDINGS(nativium_helper_security_helper) {
    em::class_<::nativium::helper::SecurityHelper>("SecurityHelper")
        .smart_ptr<std::shared_ptr<::nativium::helper::SecurityHelper>>("SecurityHelper")
        .function("nativeDestroy", &NTVHelperSecurityHelper::nativeDestroy)
        .class_function("generateUuidV4", NTVHelperSecurityHelper::generateUuidV4)
        ;
}

}  // namespace djinni_generated