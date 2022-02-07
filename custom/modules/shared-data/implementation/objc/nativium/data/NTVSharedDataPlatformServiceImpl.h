#import "nativium/data/NTVSharedDataPlatformService.h"
#import <Foundation/Foundation.h>

__attribute__((visibility("default")))
@interface NTVSharedDataPlatformServiceImpl : NSObject<NTVSharedDataPlatformService>

//
// An class method to provide an instance of the NTVSharedDataPlatformServiceImpl
// class.
//
+ (instancetype)proxy;

@end
