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

#import "AGSObject.h"
#import "AGSEnumerations.h"
#import "AGSPopupSource.h"

@class AGSEnvelope;
@class AGSRenderer;
@class AGSGraphic;
@class AGSPopupDefinition;
@class AGSLayerSceneProperties;
@class AGSLabelDefinition;

/** @file AGSGraphicsOverlay.h */ //Required for Globals API doc

/** @brief An overlay to display graphics on the map.
 
 Instances of this class represent a graphics overlay that can display graphics on top of a map. Graphics may represent temporary data in your application, such as the results of a query or an analysis, or may be used to highlight existing content in the map.
 
 
 Each graphic contains a geometry describing the location and the shape of the
 graphic. A graphics overlay typically contains @p graphics based on a single
 geometry type (Point, Multipoint, Polyline, or Polygon).  Each graphic can be
 associated with an @c AGSSymbol which controls how the graphic looks.
 Alternatively, the overlay can be associated with an @c AGSRenderer which manages
 the appearance of all graphics in the layer.
 
 @since 100
 */
@interface AGSGraphicsOverlay : AGSObject <AGSPopupSource>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initializes an AGSGraphicsOverlay.
 @since 100
 */
+(instancetype)graphicsOverlay;

#pragma mark -
#pragma mark properties

/** The extent of the graphics overlay.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSEnvelope *extent;

/** The list of graphics in the graphics overlay.
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSGraphic*> *graphics;

/** The maximum scale at which this overlay is visible. If the map or scene is zoomed in beyond this scale, the overlay will not be visible. A value of 0 means there is no maximum scale threshold and the overlay will be visible at the smallest scale available for the map or scene.
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxScale;

/** The minimum scale at which this overlay is visible. If the map or scene is zoomed out beyond this scale, the overlay will not be visible. A value of 0 means there is no minimum scale threshold and the overlay will be visible at the largest scale available for the map or scene.
 @since 100
 */
@property (nonatomic, assign, readwrite) double minScale;

/** The opacity of content in this overlay.
 Default value is 1 (fully opaque). Permitted values are between 0-1 (inclusive)
 @since 100
 */
@property (nonatomic, assign, readwrite) float opacity;

/** Identifier for this overlay. Defaults to an empty string. Does not need to be unique.
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSString *overlayID;

/** The renderer assigned to the overaly which is responsible for symbolizing the
 graphics. It is optional as each graphic may have it's own symbol. If a graphic
 has a symbol, that will be used for drawing the graphic instead of the renderer.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSRenderer *renderer;

/** The rendering mode of the graphics. Default is AGSGraphicsRenderingModeDynamic
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSGraphicsRenderingMode renderingMode;

/** The color to use for drawing a halo around selected graphics. Default is cyan.
 @since 100
 @deprecated 100.4 Use `color` property exposed through `AGSGeoView#selectionProperties`
 */
@property (nullable, nonatomic, strong, readwrite) AGSColor *selectionColor __deprecated_msg("Please use 'color' property exposed through 'selectionProperties' property in AGSGeoView");

/** Indicates whether this overlay is visible on the map or not.
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

/** Indicates whether or not graphics in this overlay will be labelled.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL labelsEnabled;

/** Defines how labels should be displayed.
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSLabelDefinition*> *labelDefinitions;

/** Properties to apply only when rendering data in 3D scenes using `AGSSceneView`
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSLayerSceneProperties *sceneProperties;

#pragma mark -
#pragma mark methods

/** Clears selection on all graphics
 @since 100
 */
-(void)clearSelection;

/** An array of @c AGSGraphic objects representing graphics that have selection enabled
 Graphics with selection enabled will be drawn using #selectionColor.
 @since 100
 */
-(NSArray<AGSGraphic*>*)selectedGraphics;

/** Select the specified graphics. The map or scene will be updated to render the graphics with `#selectionColor`
 @param graphics to select
 @since 100
 */
-(void)selectGraphics:(NSArray<AGSGraphic*> *)graphics;

/** Disable selection on the specified graphics. The map or scene will be redrawn to reflect the change.
 @param graphics to unselect
 @since 100
 */
-(void)unselectGraphics:(NSArray<AGSGraphic*> *)graphics;

NS_ASSUME_NONNULL_END
@end
