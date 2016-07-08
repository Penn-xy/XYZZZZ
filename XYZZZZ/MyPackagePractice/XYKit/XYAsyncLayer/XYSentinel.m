//
//  XYSentinel.m
//  XYZZZZ
//
//  Created by xu on 16/6/23.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import "XYSentinel.h"
#import <libkern/OSAtomic.h>

@implementation XYSentinel {
    int32_t _value;
}

- (int32_t)value {
    return _value;
}

- (int32_t)increase {
    return OSAtomicIncrement32(&_value);
}



@end
