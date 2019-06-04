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

/*@file AGSLayerViewState.h */


/** @brief The view state of a layer
 
 Instances of this class represent the view state of a layer as it is being displayed on screen. 
 
 @since 100
 */

@interface AGSLayerViewState : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The error, if any, preventing the layer from being displayed on screen
 @since 100
 */
@property (nullable, nonatomic, assign, readonly) NSError *error;

/** The status of how the layer is being displayed on screen
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLayerViewStatus status;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
