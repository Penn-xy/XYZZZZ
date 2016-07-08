//
//  XYAsyncLayer.h
//  XYZZZZ
//
//  Created by xu on 16/6/23.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#if __has_include(<XYAsyncLayer/XYAsyncLayer.h>)
FOUNDATION_EXPORT double XYAsyncLayerVersionNumber;
FOUNDATION_EXPORT const unsigned char XYAsyncLayerVersionString[];
#import <XYAsyncLayer/XYSentinel.h>
#import <XYAsyncLayer/XYTransaction.h>
#else
#import "XYSentinel.h"
#import "XYTransaction.h"
#endif

@class XYAsyncLayerDisplayTask;

NS_ASSUME_NONNULL_BEGIN

@interface XYAsyncLayer : CALayer

@property BOOL displaysAsynchronously;

@end

@protocol XYAsyncLayerDelegate <NSObject>

@required
- (XYAsyncLayerDisplayTask *)newAsyncDisplayTask;
@end

@interface XYAsyncLayerDisplayTask : NSObject

@property (nullable, nonatomic, copy) void (^willDisplay)(CALayer *layer);

@property (nullable, nonatomic, copy) void (^display)(CGContextRef context, CGSize size, BOOL(^isCancelled)(void));

@property (nullable, nonatomic, copy) void (^didDisplay)(CALayer *layer, BOOL finished);

@end

NS_ASSUME_NONNULL_END
