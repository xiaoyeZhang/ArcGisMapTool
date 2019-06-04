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

@class AGSPopupRelatedFeaturesSortOrder;

/** @file AGSPopupRelatedFeaturesDefinition.h */ //Required for Globals API doc

/** @brief Definition for handling related features in popups.
 
 Instances of this class represent a definition for handling related features in popups.
 
 @since 100.2
 */
@interface AGSPopupRelatedFeaturesDefinition : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)popupRelatedFeaturesDefinition;

#pragma mark -
#pragma mark properties

/** Indicates whether or not to show related features in a popup
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL showRelatedFeatures;

/** Specifies how to sort related features for display in a popup
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSArray<AGSPopupRelatedFeaturesSortOrder*> *sortOrder;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

