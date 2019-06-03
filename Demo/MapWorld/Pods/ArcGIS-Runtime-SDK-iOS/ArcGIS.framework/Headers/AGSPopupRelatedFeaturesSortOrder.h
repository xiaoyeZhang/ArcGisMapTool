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

@class AGSOrderBy;

/** @file AGSPopupRelatedFeaturesSortOrder.h */ //Required for Globals API doc

/** @brief The order for displaying related features in a popup.
 
 Instances of this class define the order in which related features of a particular relationship are sorted for displaying in a popup
 
 @since 100.2
 */
@interface AGSPopupRelatedFeaturesSortOrder : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)popupRelatedFeaturesSortOrder;

#pragma mark -
#pragma mark properties

/** The field in the related table by which the related features should be sorted for displaying.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSOrderBy *orderByField;

/** The ID of the relationship specifying which related features the sort order applies to.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) NSInteger relationshipID;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

