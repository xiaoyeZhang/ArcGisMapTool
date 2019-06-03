//
//  UIButton+ZXYButton.h
//  FirstMap
//
//  Created by zhangxiaoye on 2018/5/30.
//  Copyright © 2018年 zhangxiaoye. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString *const ZXYMapViewOperationTypeLine;//画线
extern NSString *const ZXYMapViewOperationTypeArea;//画多边形
extern NSString *const ZXYMapViewOperationTypeAnalysis;//分析
extern NSString *const ZXYMapViewOperationTypeData;//数据
extern NSString *const ZXYMapViewOperationTypeAdress;//地点
extern NSString *const ZXYMapViewOperationTypeDivision; // 行政区划
extern NSString *const ZXYMapViewOperationTypeInterestPoint; // 兴趣点

//extern NSString *const ZXYMapViewOperationTypeArea;

@interface UIButton (ZXYButton)

/** 操作类型画线，画多边形操作等 */
@property (copy, nonatomic) NSString *OperationType;

/** 所属群组 */
@property (strong, nonatomic) id OperationGroup;

/** Button样式：只有内容，只有图片，有图片和内容 */
@property (strong, nonatomic) id ButtonType;

/** 选中状态下的图片 */
@property (copy, nonatomic) NSString *ImageName_checked;

/** 未选中状态下的图片 */
@property (copy, nonatomic) NSString *ImageName_unchecked;

/** 是否自定义方法 */
@property(nonatomic,assign) BOOL isDIYSelector;

/** Button 的 tag */
@property(copy, nonatomic) NSString *BtnTag;

@end
