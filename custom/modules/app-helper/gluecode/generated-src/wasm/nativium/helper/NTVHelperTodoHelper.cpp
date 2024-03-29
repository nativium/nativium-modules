// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/helper/NTVHelperTodoHelper.hpp"  // my header
#include "nativium/domain/NTVDomainTodo.hpp"

namespace djinni_generated {

em::val NTVHelperTodoHelper::cppProxyMethods() {
    static const em::val methods = em::val::array(std::vector<std::string> {
    });
    return methods;
}

em::val NTVHelperTodoHelper::create() {
    try {
        auto r = ::nativium::helper::TodoHelper::create();
        return ::djinni_generated::NTVDomainTodo::fromCpp(r);
    }
    catch(const std::exception& e) {
        return djinni::ExceptionHandlingTraits<::djinni_generated::NTVDomainTodo>::handleNativeException(e);
    }
}

EMSCRIPTEN_BINDINGS(nativium_helper_todo_helper) {
    em::class_<::nativium::helper::TodoHelper>("TodoHelper")
        .smart_ptr<std::shared_ptr<::nativium::helper::TodoHelper>>("TodoHelper")
        .function("nativeDestroy", &NTVHelperTodoHelper::nativeDestroy)
        .class_function("create", NTVHelperTodoHelper::create)
        ;
}

}  // namespace djinni_generated
