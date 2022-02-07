#import "nativium/util/NTVLoggerPlatformService.h"
#import <Foundation/Foundation.h>

__attribute__((visibility("default")))
@interface NTVLoggerPlatformServiceImpl : NSObject<NTVLoggerPlatformService>

//
// An class method to provide an instance of the NTVLoggerPlatformServiceImpl
// class.
//
+ (instancetype)proxy;

@end
