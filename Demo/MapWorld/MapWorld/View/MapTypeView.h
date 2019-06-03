//
//  MapTypeView.h
//  WuxiAgriculture
//
//  Created by zhangxiaoye on 2019/2/25.
//  Copyright © 2019年 zhangxiaoye. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MapTypeView : UIView

@property (copy, nonatomic) void(^MapTypeBtnBlock)(NSInteger selsecTag);

@end

NS_ASSUME_NONNULL_END
