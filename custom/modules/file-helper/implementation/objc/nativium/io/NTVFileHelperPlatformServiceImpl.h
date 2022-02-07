#import "nativium/io/NTVFileHelperPlatformService.h"
#import <Foundation/Foundation.h>

__attribute__((visibility("default")))
@interface NTVFileHelperPlatformServiceImpl : NSObject<NTVFileHelperPlatformService>

//
// An class method to provide an instance of the NTVFileHelperPlatformServiceImpl
// class.
//
+ (instancetype)proxy;

@end
