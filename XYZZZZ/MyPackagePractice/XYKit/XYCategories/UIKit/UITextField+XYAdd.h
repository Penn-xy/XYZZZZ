//
//  UITextField+XYAdd.h
//  XYKit
//
//  Created by Yupeng on 16/6/4.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (XYAdd)

/**
 Set all text selected.
 */
- (void)selectAllText;

/**
 Set text in range selected.
 
 @param range  The range of selected text in a document.
 */
- (void)setSelectedRange:(NSRange)range;

@end
