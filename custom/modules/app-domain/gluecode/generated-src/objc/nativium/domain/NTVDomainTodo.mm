// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/domain/NTVDomainTodo.h"


@implementation NTVDomainTodo

- (nonnull instancetype)initWithId:(int64_t)id
                             title:(nonnull NSString *)title
                              body:(nonnull NSString *)body
                              data:(nonnull NSDictionary<NSString *, NSString *> *)data
                              done:(BOOL)done
                         createdAt:(nonnull NSDate *)createdAt
                         updatedAt:(nonnull NSDate *)updatedAt
{
    if (self = [super init]) {
        _id = id;
        _title = [title copy];
        _body = [body copy];
        _data = [data copy];
        _done = done;
        _createdAt = createdAt;
        _updatedAt = updatedAt;
    }
    return self;
}

+ (nonnull instancetype)todoWithId:(int64_t)id
                             title:(nonnull NSString *)title
                              body:(nonnull NSString *)body
                              data:(nonnull NSDictionary<NSString *, NSString *> *)data
                              done:(BOOL)done
                         createdAt:(nonnull NSDate *)createdAt
                         updatedAt:(nonnull NSDate *)updatedAt
{
    return [[self alloc] initWithId:id
                              title:title
                               body:body
                               data:data
                               done:done
                          createdAt:createdAt
                          updatedAt:updatedAt];
}

#ifndef DJINNI_DISABLE_DESCRIPTION_METHODS
- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p id:%@ title:%@ body:%@ data:%@ done:%@ createdAt:%@ updatedAt:%@>", self.class, (void *)self, @(self.id), self.title, self.body, self.data, @(self.done), self.createdAt, self.updatedAt];
}

#endif
@end
