// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/net/http/NTVHttpMethod.hpp"  // my header
#include <mutex>

namespace djinni_generated {

namespace {
    EM_JS(void, djinni_init_nativium_net_http_http_method_consts, (), {
        Module.HttpMethod =  {
            METHOD_GET : 0,
            METHOD_POST : 1,
            METHOD_HEAD : 2,
            METHOD_PUT : 3,
            METHOD_DELETE : 4,
            METHOD_PATCH : 5,
            METHOD_CONNECT : 6,
            METHOD_OPTIONS : 7,
            METHOD_TRACE : 8,
        }
    })
}

void NTVHttpMethod::staticInitializeConstants() {
    static std::once_flag initOnce;
    std::call_once(initOnce, [] {
        djinni_init_nativium_net_http_http_method_consts();
    });
}

EMSCRIPTEN_BINDINGS(nativium_net_http_http_method) {
    NTVHttpMethod::staticInitializeConstants();
}

}  // namespace djinni_generated
