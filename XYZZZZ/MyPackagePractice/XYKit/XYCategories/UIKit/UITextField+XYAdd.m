//
//  UITextField+XYAdd.m
//  XYKit
//
//  Created by Yupeng on 16/6/4.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import "UITextField+XYAdd.h"
#import "XYCategoriesMacro.h"

XYSYNTH_DUMMY_CLASS(UITextField_XYAdd)


@implementation UITextField (XYAdd)


- (void)selectAllText {
    UITextRange *range = [self textRangeFromPosition:self.beginningOfDocument toPosition:self.endOfDocument];
    [self setSelectedTextRange:range];
}

- (void)setSelectedRange:(NSRange)range {
    UITextPosition *beginning = self.beginningOfDocument;
    UITextPosition *startPosition = [self positionFromPosition:beginning offset:range.location];
    UITextPosition *endPosition = [self positionFromPosition:beginning offset:NSMaxRange(range)];
    UITextRange *selectionRange = [self textRangeFromPosition:startPosition toPosition:endPosition];
    [self setSelectedTextRange:selectionRange];
}



@end
