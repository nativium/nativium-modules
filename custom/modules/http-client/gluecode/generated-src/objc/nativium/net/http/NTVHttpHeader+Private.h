// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/net/http/NTVHttpHeader.h"
#include "nativium/net/http/HttpHeader.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NTVHttpHeader;

namespace djinni_generated {

struct HttpHeader
{
    using CppType = ::nativium::net::http::HttpHeader;
    using ObjcType = NTVHttpHeader*;

    using Boxed = HttpHeader;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated
