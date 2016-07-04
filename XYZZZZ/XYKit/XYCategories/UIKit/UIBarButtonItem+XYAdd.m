//
//  UIBarButtonItem+XYAdd.m
//  XYKit
//
//  Created by Yupeng on 16/6/4.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import "UIBarButtonItem+XYAdd.h"
#import "XYCategoriesMacro.h"
#import <objc/runtime.h>

//XYSYNTH_DUMMY_CLASS(UIBarButtonItem_XYAdd)

static const int block_key;


@interface _XYUIBarButtonItemBlockTarget : NSObject

@property (nonatomic, copy) void (^block)(id sender);

- (id)initWithBlock:(void (^)(id sender))block;
- (void)invoke:(id)sender;

@end

@implementation _XYUIBarButtonItemBlockTarget

- (id)initWithBlock:(void (^)(id sender))block{
    self = [super init];
    if (self) {
        _block = [block copy];
    }
    return self;
}

- (void)invoke:(id)sender {
    if (self.block) self.block(sender);
}

@end



@implementation UIBarButtonItem (XYAdd)


- (void)setActionBlock:(void (^)(id sender))block {
    _XYUIBarButtonItemBlockTarget *target = [[_XYUIBarButtonItemBlockTarget alloc] initWithBlock:block];
    objc_setAssociatedObject(self, &block_key, target, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    [self setTarget:target];
    [self setAction:@selector(invoke:)];
}

- (void (^)(id)) actionBlock {
    _XYUIBarButtonItemBlockTarget *target = objc_getAssociatedObject(self, &block_key);
    return target.block;
}



@end
