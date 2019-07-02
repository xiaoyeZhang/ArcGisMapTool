/*
 COPYRIGHT 2011 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

@class AGSPopupFieldFormat;

NS_ASSUME_NONNULL_BEGIN

/** @file AGSPopupField.h */ //Required for Globals API doc

/** @brief Information about a field in a popup.
 
 Instances of this class represent how a geo-element's attribute should be displayed as a field in a popup.
 @since 100
 */
@interface AGSPopupField : AGSObject

#pragma mark -
#pragma mark initializers

+(instancetype)popupField;

#pragma mark -
#pragma mark properties

/** The name of the field.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *fieldName;

/** The label that is shown for this field in the popup.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *label;

/** The tool tip that is shown for this field in the popup.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *tooltip;

/** Whether or not the field is editable.
 @since 100
 */
@property (nonatomic, assign, getter=isEditable) BOOL editable;

/** Whether or not the field is visible.
 @since 100
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;

/** Specifies how the field value should be formatted for display
 @since 100
 */
@property (nullable, nonatomic, strong) AGSPopupFieldFormat *format;

/** Specifies how the text field should be displayed
 @since 100
 */
@property (nonatomic, assign) AGSPopupStringFieldOption stringFieldOption;

@end

NS_ASSUME_NONNULL_END
