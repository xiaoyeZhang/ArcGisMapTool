//
//  MapTypeView.m
//  WuxiAgriculture
//
//  Created by zhangxiaoye on 2019/2/25.
//  Copyright © 2019年 zhangxiaoye. All rights reserved.
//

#import "MapTypeView.h"
#import <Masonry/Masonry.h>

@implementation MapTypeView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        
        [self addImageView];
        
        [self addMapTypeBtn];
    }
    return self;
}

- (void)addImageView{
    
    UIImageView *imageView = [[UIImageView alloc]init];
    imageView.image = [UIImage imageNamed:@"矩形 6"];
    
    [self addSubview:imageView];
    
    [imageView mas_makeConstraints:^(MASConstraintMaker *make) {
       
        make.edges.equalTo(self);
    }];
    
}

- (void)addMapTypeBtn{

    UIButton *yingxiangBtn = [[UIButton alloc]init];
    UIButton *biaozhunBtn = [[UIButton alloc]init];
    yingxiangBtn.tag = 1;
    biaozhunBtn.tag = 0;
    [yingxiangBtn setImage:[UIImage imageNamed:@"yingxiang"] forState:UIControlStateNormal];
    [biaozhunBtn setImage:[UIImage imageNamed:@"biaozhun"] forState:UIControlStateNormal];
    
    [yingxiangBtn addTarget:self action:@selector(BtnIsClick:) forControlEvents:UIControlEventTouchUpInside];
    [biaozhunBtn addTarget:self action:@selector(BtnIsClick:) forControlEvents:UIControlEventTouchUpInside];

    [self addSubview:biaozhunBtn];
    [self addSubview:yingxiangBtn];

    [yingxiangBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.left.equalTo(self).offset(8);
        make.top.equalTo(self).offset(7);
        make.bottom.equalTo(self).offset(-7);
        make.width.equalTo(@(28));
        
    }];
    
    [biaozhunBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.right.equalTo(self).offset(-8);
        make.top.equalTo(self).offset(7);
        make.bottom.equalTo(self).offset(-7);
        make.width.equalTo(@(28));

    }];
    
}

- (void)BtnIsClick:(UIButton *)sender{
    
    if (self.MapTypeBtnBlock) {
        self.MapTypeBtnBlock(sender.tag);
    }
}


@end
