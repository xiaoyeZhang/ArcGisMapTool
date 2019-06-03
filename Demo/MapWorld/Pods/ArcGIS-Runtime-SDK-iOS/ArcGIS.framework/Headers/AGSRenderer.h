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

@class AGSSymbol;
@class AGSFeature;
@class AGSGraphic;
@class AGSRendererSceneProperties;

/** @file AGSRenderer.h */ //Required for Globals API doc

/** @brief An abstract base class for renderers.
 
 Instances of this class represent renderers. Renderers symbolize geo-elements (graphics in
 a graphics overlay or features in a feature layer) based on a scheme. This is easier than symbolizing
 each graphic or feature individually.

 @since 100
*/
@interface AGSRenderer : AGSObject <AGSJSONSerializable, NSCopying>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Constant value or an expression that specifies the angle of rotation based on a feature's attribute value. When an attribute name is specified in rotationExpression, it's enclosed in square brackets, for example, [Rotation].
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *rotationExpression;

/** Controls the origin and direction of rotation. If the rotationType is defined as `AGSSymbolRotationTypeArithmetic`, the symbol is rotated from East in a counter-clockwise direction where East is the 0° axis. If the rotationType is defined as `AGSSymbolRotationTypeGeographic`, the symbol is rotated from North in a clockwise direction where North is the 0° axis.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSymbolRotationType rotationType;

/** Properties to apply only when rendering data in 3D scenes using `AGSSceneView`
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSRendererSceneProperties *sceneProperties;

#pragma mark -
#pragma mark methods

/** Compares two renderers for equality
 @param other renderer to compare this one to
 @return equal or not
 @since 100
 */
-(BOOL)isEqualToRenderer:(AGSRenderer*)other;


/** Return a symbol for the feature based on the scheme used by this renderer.
 @param feature The feature to determine the symbol for.
 @return Symbol for feature.
 @since 100
 */
-(AGSSymbol*)symbolForFeature:(AGSFeature*)feature;


/** Return a symbol for the graphic based on the scheme used by this renderer.
 @param graphic The graphic to determine the symbol for.
 @return Symbol for graphic.
 @since 100
 */
-(AGSSymbol*)symbolForGraphic:(AGSGraphic*)graphic;

NS_ASSUME_NONNULL_END
@end
