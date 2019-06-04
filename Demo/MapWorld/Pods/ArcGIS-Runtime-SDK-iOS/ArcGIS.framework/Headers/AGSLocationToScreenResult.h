/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSLocationToScreenResult.h */ //Required for Globals API doc

/** @brief Result of a location-to-screen operation on `AGSSceneView`
 
 Instances of this class represent the result of `AGSSceneView#locationToScreen:`
 
 @since 100
 */
@interface AGSLocationToScreenResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Screen coordinates for the `mapPoint` passed into `AGSSceneView#locationToScreen:`
 @since 100
 */
@property (nonatomic, assign, readonly) CGPoint screenPoint;

/** Visibility of the `#screenPoint`
 @since 100
 */
@property (nonatomic, assign, readonly) AGSScreenLocationVisibility visibility;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
