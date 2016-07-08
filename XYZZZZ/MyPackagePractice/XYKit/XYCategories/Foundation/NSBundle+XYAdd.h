//
//  NSBundle+XYAdd.h
//  XYKit
//
//  Created by Yupeng on 16/6/4.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (XYAdd)

+ (NSArray<NSNumber *> *)preferredScales;

+ (nullable NSString *)pathForScaledResource:(NSString *)name
                                      ofType:(nullable nullable NSString *)ext
                                 inDirectory:(NSString *)bundlePath;

- (nullable NSString *)pathForScaledResource:(NSString *)name ofType:(nullable NSString *)ext;

- (nullable NSString *)pathForScaledResource:(NSString *)name
                                      ofType:(nullable NSString *)ext
                                 inDirectory:(nullable NSString *)subpath;



@end



NS_ASSUME_NONNULL_END
