/*
 COPYRIGHT 2018 ESRI
 
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

#import "AGSKMLNode.h"

@class AGSEnvelope;

/** @file AGSKMLGroundOverlay.h */ //Required for Globals API doc

/** @brief A KML Ground Overlay element
 
 An instance of this class represents a KML `<GroundOverlay>` element which draws an image draped onto the terrain.
 
 @since 100.4
 */
@interface AGSKMLGroundOverlay : AGSKMLNode

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The KML ground overlay's altitude in meters. Interpreted in terms of `#altitudeMode`.
 @since 100.4
 */
@property (nonatomic, assign, readonly) double altitude;

/** Specifies how the `#altitude` value is interpreted.
 Ground overlays support Absolute and ClampToGround.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLAltitudeMode altitudeMode;

/** A color mask that is used to blend the image associated with ground overlay.
 Pixels in the overlay image are multiplied by this color channel-by-channel.
 At version 100.4, only the alpha (opacity) channel is multiplied; all others are left as-is.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSColor *color;

/** The KML ground overlay's draw order. It defines the stacking order for the images in overlapping overlays.
 Overlays with higher drawOrder values are drawn on top of overlays with lower drawOrder values.
 @since 100.4
 */
@property (nonatomic, assign, readonly) NSInteger drawOrder;

/** Specifies the geographic location for the ground overlay.
 @since 100.4
 */
@property (nonatomic, strong, readonly) AGSGeometry *geometry;


/** The rotation angle (in degrees) of the KML ground overlay about its center. Ranges from -180 to +180 degrees.
 The default is 0 (North). Rotations are specified in a counterclockwise direction.
 @since 100.4
 */
@property (nonatomic, assign, readonly) double rotation;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
