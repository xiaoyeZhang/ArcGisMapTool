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

@class AGSGeometry;

/** @file AGSSymbol.h */ //Required for Globals API doc

/** @brief A symbol used to display a graphic or a feature
 
 An abstract base class to represent symbols.  Symbols describe how graphics and features look on the map.
 Different symbols are used with different geometry types. Marker
 symbols are used for point and multipoint geometries, Fill symbols are used for
 polygon geometries, and Line symbols are used for polyline geometries.
 
 @since 100
 */
@interface AGSSymbol : AGSObject <AGSJSONSerializable, NSCopying>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

/** Creates swatch with provided background color. This method uses main screen's scale to determine the size of the image.
 @param completion block that is invoked when operation completes.
 @since 100
 */
-(id<AGSCancelable>)createSwatchWithCompletion:(void(^)(AGSImage * __nullable swatch, NSError * __nullable error))completion;


/** Creates swatch with provided background color.
 @param backgroundColor Desired background color of the image
 @param screen Screen that the swatch will be rendered for. If you specify nil then the main screen will be used.
 @param completion block that is invoked when operation completes.
 @since 100
 */
#if TARGET_OS_IPHONE
-(id<AGSCancelable>)createSwatchWithBackgroundColor:(nullable AGSColor*)backgroundColor
                                              screen:(nullable UIScreen*)screen
                                          completion:(void(^)(AGSImage * __nullable swatch, NSError * __nullable error))completion;
#elif TARGET_OS_MAC && !TARGET_OS_IPHONE
-(id<AGSCancelable>)createSwatchWithBackgroundColor:(nullable AGSColor*)backgroundColor
                                              screen:(nullable NSScreen*)screen
                                          completion:(void(^)(AGSImage * __nullable swatch, NSError * __nullable error))completion;
#endif

/** Creates swatch using provided geometry and other parameters. This is the most configurable of the methods to create swatches. You can pass the pixels per inch that you would like the image to be rendered at. This will determine how many pixels are used to render symbols of sizes that are specified in Points.
 @param geometry Geometry of the symbol to be drawn in the swatch image. The coordinates of the specified geometry are in pixels, with the point (0,0) located at the centerpoint of the swatch image. The x-axis increases towards the right-hand side of the swatch image. The y-axis increases towards the top of the swatch image. For example: when creating a swatch for a #AGSSimpleMarkerSymbol, specifying a geometry of (10,10) will draw the marker 10 pixels up and to the right of the center of the swatch. The geometry (#AGSPoint, #AGSPolyline, #AGSPolygon) correspond to the symbol (#AGSSimpleMarkerSymbol, #AGSSimpleLineSymbol, #AGSSimpleFillSymbol). The geometry's spatial reference is ignored.
 @param width Desired width of the image in pixels
 @param height Desired height of the image in pixels
 @param screen Screen that the swatch will be rendered for. If you specify nil then the main screen will be used.
 @param backgroundColor Desired background color of the image
 @param completion block that is invoked when operation completes.
 @since 100
 */
#if TARGET_OS_IPHONE
-(id<AGSCancelable>)createSwatchWithGeometry:(AGSGeometry*)geometry
                                        width:(NSInteger)width
                                       height:(NSInteger)height
                                       screen:(nullable UIScreen*)screen
                              backgroundColor:(nullable AGSColor*)backgroundColor
                                   completion:(void(^)(AGSImage * __nullable swatch, NSError * __nullable error))completion;
#elif TARGET_OS_MAC && !TARGET_OS_IPHONE
-(id<AGSCancelable>)createSwatchWithGeometry:(AGSGeometry*)geometry
                                        width:(NSInteger)width
                                       height:(NSInteger)height
                                       screen:(nullable NSScreen*)screen
                              backgroundColor:(nullable AGSColor*)backgroundColor
                                   completion:(void(^)(AGSImage * __nullable swatch, NSError * __nullable error))completion;
#endif

#if TARGET_OS_IPHONE
-(nullable id<AGSCancelable>)createSwatchWithWidth:(NSInteger)width
                                   height:(NSInteger)height
                                   screen:(nullable UIScreen*)screen
                          backgroundColor:(nullable AGSColor*)backgroundColor
                               completion:(void(^)(AGSImage * __nullable swatch, NSError * __nullable error))completion;
#elif TARGET_OS_MAC && !TARGET_OS_IPHONE
-(nullable id<AGSCancelable>)createSwatchWithWidth:(NSInteger)width
                                   height:(NSInteger)height
                                   screen:(nullable NSScreen*)screen
                          backgroundColor:(nullable AGSColor*)backgroundColor
                               completion:(void(^)(AGSImage * __nullable swatch, NSError * __nullable error))completion;
#endif

/** Compares this symbol to another for equality
 @param other symbol to compare this one to
 @return whether the two symbols are equal or not
 @since 100
 */
-(BOOL)isEqualToSymbol:(AGSSymbol*)other;

NS_ASSUME_NONNULL_END
@end
