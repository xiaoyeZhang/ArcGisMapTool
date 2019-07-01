//
//  ZXYButton.swift
//  MapWorld-Swift
//
//  Created by zhangxiaoye on 2019/6/27.
//  Copyright © 2019 zhangxiaoye. All rights reserved.
//

import UIKit

enum ZXYBtnOperationType : String{
    case ZXYMapViewOperationTypeLine = "Line"
    case ZXYMapViewOperationTypeArea = "Area"
    case ZXYMapViewOperationTypeAnalysis = "Analysis"
    case ZXYMapViewOperationTypeData = "Data"
    case ZXYMapViewOperationTypeAdress = "Adress"
    case ZXYMapViewOperationTypeDivision = "Division"
    case ZXYMapViewOperationTypeInterestPoint = "InterestPoint"
}

/** 操作类型画线，画多边形操作等 */
var OperationTypeKey: NSString = ""

/** 所属群组 */
var OperationGroupKey: Any = ""

/** Button样式：只有内容，只有图片，有图片和内容 */
var ButtonTypeKey: Any = ""

/** 选中状态下的图片 */
var ImageName_checkedKey: NSString = ""

/** 未选中状态下的图片 */
var ImageName_uncheckedKey: NSString = ""

/** 是否自定义方法 */
var isDIYSelectorKey: Bool!

/** Button 的 tag */
var BtnTagKey: NSString = ""

extension UIButton {

    
    open var OperationType: NSString{
        get {
            
            return objc_getAssociatedObject(self, &OperationTypeKey) as! NSString
        }
        set{
            objc_setAssociatedObject(self, &OperationTypeKey, newValue, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    
    
    open var OperationGroup: Any{
        get {
            
            return objc_getAssociatedObject(self, &OperationGroupKey) ?? (Any).self
        }
        set{
            objc_setAssociatedObject(self, &OperationGroupKey, newValue, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    
    
    open var ButtonType: Any{
        get {
            
            return objc_getAssociatedObject(self, &ButtonTypeKey) ?? (Any).self
        }
        set{
            objc_setAssociatedObject(self, &ButtonTypeKey, newValue, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    
    
    open var ImageName_checked: NSString{
        get {
            
            return objc_getAssociatedObject(self, &ImageName_checkedKey) as! NSString
        }
        set{
            objc_setAssociatedObject(self, &ImageName_checkedKey, newValue, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    
    open var ImageName_unchecked: NSString{
        get {
            
            return objc_getAssociatedObject(self, &ImageName_uncheckedKey) as! NSString
        }
        set{
            objc_setAssociatedObject(self, &ImageName_uncheckedKey, newValue, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    
    
    open var isDIYSelector: Bool{
        get {
            
            return objc_getAssociatedObject(self, &isDIYSelectorKey) as! Bool
        }
        set{
            objc_setAssociatedObject(self, &isDIYSelectorKey, newValue, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    
    open var BtnTag: NSString{
        get {
            
            return objc_getAssociatedObject(self, &BtnTagKey) as! NSString
        }
        set{
            objc_setAssociatedObject(self, &BtnTagKey, newValue, .OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    
    
}
