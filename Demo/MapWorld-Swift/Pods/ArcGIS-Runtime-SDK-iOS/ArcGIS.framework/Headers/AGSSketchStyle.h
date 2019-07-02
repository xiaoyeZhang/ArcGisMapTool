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

@class AGSSymbol;

NS_ASSUME_NONNULL_BEGIN


/** @file AGSSketchStyle.h */ //Required for Globals API doc

/** @brief Style for the visual appearance of `AGSSketchEditor`
 
 Instances of this class represents a style that controls the visual appearance of sketches created by `AGSSketchEditor` .
 
 @since 100
 */
@interface AGSSketchStyle : NSObject

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** If enabled, every vertex in the sketch is labeled with a number.
 @since 100
 */
@property (nonatomic, assign) BOOL showNumbersForVertices;

/** The color of selected components of the sketch.
 @since 100
 @deprecated 100.4 Use `color` property exposed through `AGSGeoView#selectionProperties`
 */
@property (nonatomic, strong, readwrite) AGSColor *selectionColor __deprecated_msg("Please use 'color' property exposed through 'selectionProperties' property in AGSGeoView");

/** Symbol used to display lines.  Use a symbol that can symbolize a line geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *lineSymbol;

/** Symbol used to fill polygons.  Use a symbol that can fill a polygon geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *fillSymbol;

/** Symbol used to display feedback when editing geometries.  Use a symbol that can symbolize a line geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *feedbackLineSymbol;

/** Symbol used to display feedback when editing geometries.  Use a symbol that can symbolize a polygon geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *feedbackFillSymbol;

/** Symbol used to display feedback when editing geometries.  Use a symbol that can symbolize a point geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *feedbackVertexSymbol;

/** Symbol used to display the selected vertex.  Use a symbol that can symbolize a point geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *selectedVertexSymbol;

/** Symbol used to display the selected mid vertex.  Use a symbol that can symbolize a point geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *selectedMidVertexSymbol;

/** Symbol used to display the vertices.  Use a symbol that can symbolize a point geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *vertexSymbol;

/** Symbol to display the mid vertices.  Use a symbol that can symbolize a point geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *midVertexSymbol;

/** Symbol to display the text over vertices when numbers are enabled for vertices.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *vertexTextSymbol;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END


