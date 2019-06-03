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

#import "AGSSymbol.h"

/** @file AGSMarkerSymbol.h */ //Required for Globals API doc

/** @brief An abstract base class for marker symbols.
 
 Subclasses represent marker symbols. Symbols describe how graphics and features
 look on a map. Different symbols are used with different geometry
 types.  Marker symbols are used to display those graphics and features which are based on
 point or multipoint geometries.
 
 @since 100
 */

@interface AGSMarkerSymbol : AGSSymbol
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The rotation angle (in degrees) of the symbol. See `#rotationType` for how rotation is applied.
 @since 100
 */
@property (nonatomic, assign, readwrite) float angle;

/** Specifies whether the symbol should rotate with the map/scene or stay at the same angle with regards to the screen. Default is `AGSMarkerSymbolAngleAlignmentScreen` which keeps it aligned with the screen.
 Only supported for graphics overlays when `AGSGraphicsOverlay#renderingMode` is @c AGSGraphicsRenderingModeDynamic, and for feature layers when `AGSFeatureLayer#renderingMode` is @c AGSFeatureRenderingModeDynamic
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSMarkerSymbolAngleAlignment angleAlignment;


/** Specifies how to position a callout's leader in relation to the symbol (for example, when a user taps on the map to display a callout for the feature or graphic).  Default value is 0 and the callout's leader is positioned at the horizontal center of the symbol. The values specified here are interpreted in
 a cartesian coordinate system and in points (not pixels). Thus, a value of -5 will offset the callout's leader left on the x-axis by 5 points
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat leaderOffsetX;

/** Specifies how to position a callout's leader in relation to the symbol (for example, when a user taps on the map to display a callout for the feature or graphic).  Default value is 0 and the callout's leader is positioned at the vertical center of the symbol. The values specified here are interpreted in
 a cartesian coordinate system and in points (not pixels). Thus, a value of -5 will offset the callout's leader down on the y-axis by 5 points
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat leaderOffsetY;

/** Specifies how to position the symbol in relation to the graphic or feature's point geometry. This is useful when the marker needs to be offset to properly coincide with a
 location on the map. 
 
 Default value is 0 and the symbol is centered horizontally on the point geometry.
 The values specified are interpreted in a cartesian coordinate system.
 Thus, a value of -5 will shift the marker left by 5 points on the x-axis.
 
 For example, consider an @c AGSPictureMarkerSymbol using the image of a pushpin.
 By default, the center of the image will be used as the anchor to center the
 image at the map location. However, if you wanted the needle of the pushpin to
 end at the map location, you would need to offset the image appropriately to make the needle's end coincide with the map location.
 
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat offsetX;

/** Specifies how to position the symbol in relation to the graphic or feature's point geometry. This is useful when the marker needs to be offset to properly coincide with a
 location on the map.
 
 Default value is 0 and the symbol is centered vertically on the point geometry.
 The values specified are interpreted in a cartesian coordinate system.
 Thus, a value of -5 will shift the marker down by 5 points on the y-axis.
 
 For example, consider an @c AGSPictureMarkerSymbol using the image of a pushpin.
 By default, the center of the image will be used as the anchor to center the
 image at the map location. However, if you wanted the needle of the pushpin to
 end at the map location, you would need to offset the image appropriately to make the needle's end coincide with the map location.
 
 @since 100
 */

@property (nonatomic, assign, readwrite) CGFloat offsetY;

/** Controls the origin and direction of rotation. Defaults to `AGSSymbolRotationTypeArithmetic`
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSymbolRotationType rotationType;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
