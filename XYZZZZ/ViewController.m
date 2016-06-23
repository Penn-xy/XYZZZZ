//
//  ViewController.m
//  XYZZZZ
//
//  Created by Yupeng on 16/6/21.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import "ViewController.h"
#import "UIButton+CountDown.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (IBAction)actionDoSomething:(UIButton *)sender {
    
    [sender countDownFromTime:5 unitTitle:@"秒" completion:^(UIButton *countDownButton) {
        NSLog(@"😄");
    }];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
