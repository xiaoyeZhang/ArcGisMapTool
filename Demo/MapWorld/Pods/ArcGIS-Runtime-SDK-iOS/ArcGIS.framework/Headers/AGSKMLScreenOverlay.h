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

#import "AGSKMLNode.h"

/** @file AGSKMLScreenOverlay.h */ //Required for Globals API doc

/** @brief A KML Screen Overlay element
 
 An instance of this class represents a KML `<ScreenOverlay>` element which
 draws an image overlay at a fixed screen location.
 Screen overlays may be used for compasses, logos and heads-up displays.
 
 @since 100.4
 */
@interface AGSKMLScreenOverlay : AGSKMLNode

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** A color mask that is used to blend the image associated with screen overlay.
 @note Pixels in the overlay image are multiplied by this color channel-by-channel.
 @note At version 100.4, only the alpha (opacity) channel is multiplied; all others are left as-is.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSColor *color;

/** The KML screen overlay's draw order. It defines the stacking order for the images in overlapping overlays.
 Overlays with higher drawOrder values are drawn on top of overlays with lower drawOrder values.
 @since 100.4
 */
@property (nonatomic, assign, readonly) NSInteger drawOrder;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

