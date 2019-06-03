//
//  UIButton+ZXYButton.m
//  FirstMap
//
//  Created by zhangxiaoye on 2018/5/30.
//  Copyright © 2018年 zhangxiaoye. All rights reserved.
//

#import "UIButton+ZXYButton.h"
#import <objc/runtime.h>


NSString *const ZXYMapViewOperationTypeLine = @"Line";
NSString *const ZXYMapViewOperationTypeArea = @"Area";
NSString *const ZXYMapViewOperationTypeAnalysis = @"Analysis";
NSString *const ZXYMapViewOperationTypeData = @"Data";
NSString *const ZXYMapViewOperationTypeAdress = @"Adress";
NSString *const ZXYMapViewOperationTypeDivision = @"Division";
NSString *const ZXYMapViewOperationTypeInterestPoint = @"InterestPoint";

@implementation UIButton (ZXYButton)

- (BOOL)isDIYSelector{
 
    return objc_getAssociatedObject(self, @selector(isDIYSelector));
}

- (void)setIsDIYSelector:(BOOL)isDIYSelector{
    
    objc_setAssociatedObject(self, @selector(isDIYSelector), @(isDIYSelector), OBJC_ASSOCIATION_COPY_NONATOMIC);
}

- (NSString *)OperationType{
    
    return objc_getAssociatedObject(self, @selector(OperationType));
}

- (void)setOperationType:(id)OperationType{
    
    objc_setAssociatedObject(self, @selector(OperationType), OperationType, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (id)OperationGroup{
    
    return objc_getAssociatedObject(self, @selector(OperationGroup));

}
- (void)setOperationGroup:(id)OperationGroup{
    
    objc_setAssociatedObject(self, @selector(OperationGroup), OperationGroup, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

}

- (id)ButtonType{
    
    return objc_getAssociatedObject(self, @selector(ButtonType));
}

- (void)setButtonType:(id)ButtonType{
    
    objc_setAssociatedObject(self, @selector(ButtonType), ButtonType, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSString *)ImageName_checked{
    return objc_getAssociatedObject(self, @selector(ImageName_checked));
}

- (void)setImageName_checked:(NSString *)ImageName_checked{
    
    objc_setAssociatedObject(self, @selector(ImageName_checked), ImageName_checked, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

}

- (NSString *)ImageName_unchecked{
    return objc_getAssociatedObject(self, @selector(ImageName_unchecked));
}

- (void)setImageName_unchecked:(NSString *)ImageName_unchecked{
    
    objc_setAssociatedObject(self, @selector(ImageName_unchecked), ImageName_unchecked, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
}

- (NSString *)BtnTag{
    
    return objc_getAssociatedObject(self, @selector(BtnTag));
}

- (void)setBtnTag:(NSString *)BtnTag{
    
    objc_setAssociatedObject(self, @selector(BtnTag), BtnTag, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end
