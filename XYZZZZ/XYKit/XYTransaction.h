//
//  XYTransaction.h
//  XYZZZZ
//
//  Created by xu on 16/6/23.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYTransaction : NSObject

+ (XYTransaction *)transactionWithTarget:(id)target selector:(SEL)selector;

- (void)commit;

@end

NS_ASSUME_NONNULL_END
