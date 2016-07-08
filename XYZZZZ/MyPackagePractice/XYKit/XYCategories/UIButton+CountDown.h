//
//  UIButton+CountDown.h
//  XYZZZZ
//
//  Created by Yupeng on 16/6/23.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^Completion)(UIButton *countDownButton);

@interface UIButton (CountDown)

- (void)countDownFromTime:(NSInteger)startTime unitTitle:(NSString *)untiTitle completion:(Completion)completion;

@end
