//
//  UIImage+CreatImage.m
//  XYZZZZ
//
//  Created by Yupeng on 16/6/23.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import "UIImage+CreatImage.h"

@implementation UIImage (CreatImage)

+ (UIImage *)createImageWithColor:(UIColor *)color {
    
    CGRect rect = CGRectMake(0.0, 0.0, 1.0, 1.0);
    
    UIGraphicsBeginImageContext(rect.size);
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextSetFillColorWithColor(context, [color CGColor]);
    
    CGContextFillRect(context, rect);
    
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return theImage;
    
}


@end
