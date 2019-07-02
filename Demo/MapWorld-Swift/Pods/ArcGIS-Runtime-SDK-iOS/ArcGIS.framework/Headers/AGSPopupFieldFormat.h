/*
 COPYRIGHT 2015 ESRI
 
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

NS_ASSUME_NONNULL_BEGIN

/** @file AGSPopupFieldFormat.h */ //Required for Globals API doc

/** @brief Display formatting for a popup field
 
 Instances of this class specify how a popup field value should be formatted for display.
 
 @since 100
 */
@interface AGSPopupFieldFormat : AGSObject

#pragma mark -
#pragma mark initializers

+(instancetype)popupFieldFormat;

#pragma mark -
#pragma mark properties

/** The format in which to display dates. Only applicable for date fields.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSPopupDateFormat dateFormat;

/** The number of decimal digits to display. Only applicable for numeric fields.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger decimalPlaces;

/** Whether numbers should be displayed with a locale-specific thousands separator.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL useThousandsSeparator;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
