// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import <Foundation/Foundation.h>

@interface NTVDomainTodo : NSObject
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
- (nonnull instancetype)initWithId:(int64_t)id
                             title:(nonnull NSString *)title
                              body:(nonnull NSString *)body
                              data:(nonnull NSDictionary<NSString *, NSString *> *)data
                              done:(BOOL)done
                         createdAt:(nonnull NSDate *)createdAt
                         updatedAt:(nonnull NSDate *)updatedAt NS_DESIGNATED_INITIALIZER;
+ (nonnull instancetype)todoWithId:(int64_t)id
                             title:(nonnull NSString *)title
                              body:(nonnull NSString *)body
                              data:(nonnull NSDictionary<NSString *, NSString *> *)data
                              done:(BOOL)done
                         createdAt:(nonnull NSDate *)createdAt
                         updatedAt:(nonnull NSDate *)updatedAt;

@property (nonatomic, readonly) int64_t id;

@property (nonatomic, readonly, nonnull) NSString * title;

@property (nonatomic, readonly, nonnull) NSString * body;

@property (nonatomic, readonly, nonnull) NSDictionary<NSString *, NSString *> * data;

@property (nonatomic, readonly) BOOL done;

@property (nonatomic, readonly, nonnull) NSDate * createdAt;

@property (nonatomic, readonly, nonnull) NSDate * updatedAt;

@end