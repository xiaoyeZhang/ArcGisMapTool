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

#import "AGSLayer.h"

/** @file AGSImageAdjustmentLayer.h */ //Required for Globals API doc

/** @brief A base class for layers that allow color adjustments.
 
 A base class for layers that allow color adjustments.
 
 @since 100
 */
@interface AGSImageAdjustmentLayer : AGSLayer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The brightness of the layer's map image.
 Default value is 0.  Values in the range -100.0 to 100.0 are valid.
 Values outside that range are ignored.
 @since 100
 */
@property (nonatomic, assign, readwrite) float brightness;

/** The contrast of the layer's map image.
 Default value is 0.  Values in the range -100.0 to 100.0 are valid.
 Values outside that range are ignored.
 @since 100
 */
@property (nonatomic, assign, readwrite) float contrast;

/** The gamma of the layer's map image.
 Default value is 0.  Values in the range -100.0 to 100.0 are valid.
 Values outside that range are ignored.
 @since 100
 */
@property (nonatomic, assign, readwrite) float gamma;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
