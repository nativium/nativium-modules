// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/domain/NTVDomainCustomer.h"
#include "nativium/domain/Customer.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NTVDomainCustomer;

namespace djinni_generated {

struct Customer
{
    using CppType = ::nativium::domain::Customer;
    using ObjcType = NTVDomainCustomer*;

    using Boxed = Customer;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated