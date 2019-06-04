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

@class AGSENCMarinerSettings;
@class AGSENCTextGroupVisibilitySettings;
@class AGSENCViewingGroupSettings;

/** @file AGSENCDisplaySettings.h */ //Required for Globals API doc

/** @brief Display settings for ENC data
 
 Display settings for ENC data.
 
 @since 100.2
 */
@interface AGSENCDisplaySettings : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Mariner settings
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSENCMarinerSettings *marinerSettings;

/** Text group visibility settings
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSENCTextGroupVisibilitySettings *textGroupVisibilitySettings;

/** Viewing group settings
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSENCViewingGroupSettings *viewingGroupSettings;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

