// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/repository/TodoRepository.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NTVRepositoryTodoRepository;

namespace djinni_generated {

class TodoRepository
{
public:
    using CppType = std::shared_ptr<::nativium::repository::TodoRepository>;
    using CppOptType = std::shared_ptr<::nativium::repository::TodoRepository>;
    using ObjcType = NTVRepositoryTodoRepository*;

    using Boxed = TodoRepository;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

