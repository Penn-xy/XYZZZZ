//
//  XYKeyboardManager.h
//  XYZZZZ
//
//  Created by xu on 16/6/21.
//  Copyright © 2016年 Yupeng. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct {
    BOOL fromVisible;
    BOOL toVisible;
    CGRect fromFrame;
    CGRect toFrame;
    NSTimeInterval animationDuration;
    UIViewAnimationCurve animationCurve;
    UIViewAnimationOptions animationOption;
} XYKeyboardTransition;

@protocol XYKeyboardObserver <NSObject>
@optional
- (void)keyboardChangedWithTransition:(XYKeyboardTransition)transition;
@end


@interface XYKeyboardManager : NSObject

- (instancetype)init  UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

+ (instancetype)defaultManager;

@property (nullable, nonatomic, readonly) UIWindow *keyboardWindow;

@property (nullable, nonatomic, readonly) UIView *keyboardView;

@property (nonatomic, readonly, getter=isKeyboardVisible) BOOL keyboardVisible;

@property (nonatomic, readonly) CGRect keyboardFrame;

- (void)addObserver:(id<XYKeyboardObserver>)observer;

- (void)removeObserver:(id<XYKeyboardObserver>)observer;

- (CGRect)convertRect:(CGRect)rect toView:(nullable UIView *)view;

@end


NS_ASSUME_NONNULL_END