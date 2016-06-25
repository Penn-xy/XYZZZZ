//
//  YYCategoriesMacro.m
//  XYKit
//
//  Created by Yupeng on 16/6/4.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <sys/time.h>
#import <pthread.h>

#ifndef XYCategoriesMacro_h
#define XYCategoriesMacro_h

#ifdef __cplusplus
#define XY_EXTERN_C_BEGIN  extern "C" {
#define XY_EXTERN_C_END  }
#else
#define XY_EXTERN_C_BEGIN
#define XY_EXTERN_C_END
#endif

XY_EXTERN_C_BEGIN

#ifndef XY_CLAMP // return the clamped value
#define XY_CLAMP(_x_, _low_, _high_)  (((_x_) > (_high_)) ? (_high_) : (((_x_) < (_low_)) ? (_low_) : (_x_)))
#endif

#ifndef XY_SWAP // swap two value
#define XY_SWAP(_a_, _b_)  do { __typeof__(_a_) _tmp_ = (_a_); (_a_) = (_b_); (_b_) = _tmp_; } while (0)
#endif


#define XYAssertNil(condition, description, ...) NSAssert(!(condition), (description), ##__VA_ARGS__)
#define XYCAssertNil(condition, description, ...) NSCAssert(!(condition), (description), ##__VA_ARGS__)

#define XYAssertNotNil(condition, description, ...) NSAssert((condition), (description), ##__VA_ARGS__)
#define XYCAssertNotNil(condition, description, ...) NSCAssert((condition), (description), ##__VA_ARGS__)

#define XYAssertMainThread() NSAssert([NSThread isMainThread], @"This method must be called on the main thread")
#define XYCAssertMainThread() NSCAssert([NSThread isMainThread], @"This method must be called on the main thread")



XY_EXTERN_C_END

