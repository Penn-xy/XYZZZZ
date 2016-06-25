//
//  XYSentinel.h
//  XYZZZZ
//
//  Created by xu on 16/6/23.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYSentinel : NSObject

@property (readonly) int32_t value;

- (int32_t)increase;

@end


NS_ASSUME_NONNULL_END