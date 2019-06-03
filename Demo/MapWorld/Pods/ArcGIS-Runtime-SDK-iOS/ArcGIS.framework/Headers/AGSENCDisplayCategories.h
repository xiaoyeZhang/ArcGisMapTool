/*
 COPYRIGHT 2017 ESRI
 
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

#import "AGSObject.h"

/** @file AGSENCDisplayCategories.h */ //Required for Globals API doc

/** @brief Display categories for ENC data
 
 Display categories for ENC data.  The S52 standard allows for toggling three display categories.
 @note Changes are applied to the display of all ENC layers in a map
 @since 100.2
 */
@interface AGSENCDisplayCategories : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether the S52 "displaybase" display category is enabled.
 @note "displaybase" category contains a subset of the objects in "standard".
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL displayBase;

/** Indicates whether the S52 "other" display category is enabled.
 @note The "other" category contains all objects that are not enabled by default in "Standard Display".
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL otherDisplay;

/** Indicates whether the S52 "standard" display category is enabled.
 @note Once an object has been added to or removed from display, the display is no longer showing the "Standard Display". This will not be reflected by this property.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL standardDisplay;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

