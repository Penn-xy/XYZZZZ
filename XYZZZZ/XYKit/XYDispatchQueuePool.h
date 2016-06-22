//
//  XYDispatchQueuePool.h
//  XYZZZZ
//
//  Created by xu on 16/6/22.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <Foundation/Foundation.h>


#ifndef XYDisPatchQueuePool_h
#define YYDispatchQueuePool_h

NS_ASSUME_NONNULL_BEGIN

@interface XYDispatchQueuePool : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (instancetype)initWithName:(nullable NSString *)name queueCount:(NSUInteger)queueCount qos:(NSQualityOfService)qos;

@property (nullable, nonatomic, readonly) NSString *name;

- (dispatch_queue_t)queue;

+ (instancetype)defaultPoolForQOS:(NSQualityOfService)qos;

@end

extern dispatch_queue_t XYDispatchQueueGetForQOS(NSQualityOfService qos);

NS_ASSUME_NONNULL_END

#endif