/*
 COPYRIGHT 2012 ESRI
 
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

/** @file AGSMapViewCommon.h */

#import "AGSGeoView.h"

@class AGSMap;
@class AGSViewLabelProperties;
@class AGSPolygon;
@class AGSEnvelope;
@class AGSPoint;
@class AGSLocationDisplay;
@class AGSBackgroundGrid;
@class AGSGrid;
@class AGSMapViewInteractionOptions;
@protocol AGSGeoViewTouchDelegate;

/*@file AGSMapViewCommon.h */

/** @brief A base class for AGSMapView
 
 A base class for `AGSMapView` to facilitate code reuse between iOS and Mac platforms.
 
 @since 100
 */

@interface AGSMapViewCommon : AGSGeoView
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers
#pragma mark -

#pragma mark -
#pragma mark properties
#pragma mark -

/** The map to be displayed by this mapview. The mapview loads the map and all of its layers in order to display their content on screen.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSMap *map;

/** The coordinate system grid to display on top of the map.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSGrid *grid;

/** The view's background grid. The map contents are displayed on top of this background grid.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSBackgroundGrid *backgroundGrid;

/** Specifies how contents of the map should be labelled
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSViewLabelProperties *labeling;

/**The rotation angle (in degrees). The map is rotated in a counter-clockwise direction by the amount specified. To specify a new angle, see `#setViewpointRotation:completion:` or `#setViewpoint:`.
 @since 100
 */
@property (nonatomic, assign, readonly) double rotation;

/** The current scale of the map. Will return 0 if it cannot be calculated. To change the scale see `#setViewpointCenter:scale:completion:` or `#setViewpoint:`.
 @since 100
 */
@property (nonatomic, assign, readonly) double mapScale;

/** The map's current resolution (map units per Point).
 @since 100
 */
@property (nonatomic, assign, readonly) double unitsPerPoint;

/** A polygon representing the map's visible area, taking into account any `#contentInset` that has been specified to return only the unobscured portion of the map.
 The polygon always contains 1 ring with 4 vertices, each representing a corner of the map.
 
 This is a polygon and not an envelope because the map may be rotated and each corner of the map may contain unique x-y coordinates, where as an envelope only permits 2 unique x coordinates (xmin, xmax) and 2 unique y coordinates (ymin, ymax). If the map has no rotation the polygon has the same coordinates as an envelope.
 
 @note Starting from version 100.3, the visible area excludes the portion of the map obscured by the map view's attribution bar. As a result of this change, the edges and center of the visible area may not coincide with the bounds and center of the view.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPolygon *visibleArea;

/** Displays device location on the map from a datasource such as a gps sensor.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSLocationDisplay *locationDisplay;

/** A sketch editor that allows users to interactively sketch geometries on the view.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSketchEditor *sketchEditor;

#pragma mark - behavioral

/** Options to configure user interactions with the view.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSMapViewInteractionOptions *interactionOptions;

/** Indicates whether the map should wrap around the dateline.
 Defaults to `AGSWrapAroundModeEnabledWhenSupported`
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSWrapAroundMode wrapAroundMode;

/** Defines the edges where the `AGSMapView` is obscured by some other UI.
 This is important so that callouts display correctly, the location display is anchored appropriately, and setting a new viewpoint adjusts the map contents to correctly display in the unobscured part of the view.
 Setting this will affect the @c visibleArea that is reported by the `AGSMapView`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSEdgeInsets contentInset;

/** The insets derived from the content inset, the height of the attribution bar, and (on iOS) the safe area insets.
 For iOS, the @c insetsContentInsetFromSafeArea property determines whether the safe area insets are included in the adjustment.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSEdgeInsets adjustedContentInset;

#if TARGET_OS_IPHONE
/** Indicates whether the content inset is relative to the safe area.
 When @c YES, the content inset is interpreted as a value relative to the safe area.
 When @c NO, the content inset is interpreted as a value from the edge of bounds.
 Defaults to @c YES.
 @since 100.4
 */
@property (nonatomic, assign, readwrite) BOOL insetsContentInsetFromSafeArea;
#endif

#pragma mark -
#pragma mark methods

#pragma mark -
#pragma mark conversion methods

/** Converts the specified location in map units to a point in screen units.
 @param mapLocation to convert
 @return screen point
 @since 100
 */
-(CGPoint)locationToScreen:(AGSPoint *)mapLocation;

/** Converts the specified screen point to a map location
 @param screen point to convert
 @return map location
 @since 100
 */
-(AGSPoint*)screenToLocation:(CGPoint)screen;

#pragma mark navigation methods

/** Zoom or pan the map with animation to the specified viewpoint.
 @param viewpoint to zoom/pan to
 @param duration for the zoom/pan animation
 @param curve Type of animation
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @return operation which can be canceled
 @note Any prior `setViewpoint...` animation will be canceled upon calling this method. If you want to chain together mulitple animations, wait for the prior animation to complete before calling this method.
 @since 100
 */
-(id<AGSCancelable>)setViewpoint:(AGSViewpoint*)viewpoint duration:(double)duration curve:(AGSAnimationCurve)curve completion:(nullable void(^)(BOOL finished))completion;

/** Zoom or pan the map with animation to the specified location.
 @param center Location on which the map should be centered
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @return operation which can be canceled
 @note Any prior `setViewpoint...` animation will be canceled upon calling this method. If you want to chain together mulitple animations, wait for the prior animation to complete before calling this method.
 @since 100
 */
-(id<AGSCancelable>)setViewpointCenter:(AGSPoint*)center completion:(nullable void(^)(BOOL finished))completion;

/** Zoom or pan the map with animation to the specified location.
 @param center Location on which the map should be centered
 @param scale to which the map should be zoomed to
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @return operation which can be canceled
 @note Any prior `setViewpoint...` animation will be canceled upon calling this method. If you want to chain together mulitple animations, wait for the prior animation to complete before calling this method.
@since 100
 */
-(id<AGSCancelable>)setViewpointCenter:(AGSPoint*)center scale:(double)scale completion:(nullable void(^)(BOOL finished))completion;

/** Zoom the map with animation to the specified scale around its current center.
 @param scale to which the map should be zoomed to
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @return operation which can be canceled
 @note Any prior `setViewpoint...` animation will be canceled upon calling this method. If you want to chain together mulitple animations, wait for the prior animation to complete before calling this method.
 @since 100
 */
-(id<AGSCancelable>)setViewpointScale:(double)scale completion:(nullable void(^)(BOOL finished))completion;

/** Rotate the map with animation to the specified angle
 @param angle in degress to rotate to (in counter-clockwise direction)
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @return operation which can be canceled
 @note Any prior `setViewpoint...` animation will be canceled upon calling this method. If you want to chain together mulitple animations, wait for the prior animation to complete before calling this method.
 @since 100
 */
-(id<AGSCancelable>)setViewpointRotation:(double)angle completion:(nullable void(^)(BOOL finished))completion;

/** Zoom or pan the map with animation such that the given geometry fits the bounds of the map.
 @param geometry to fit to the bounds of the map
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @return operation which can be canceled
 @note Any prior `setViewpoint...` animation will be canceled upon calling this method. If you want to chain together mulitple animations, wait for the prior animation to complete before calling this method.
 @since 100
 */
-(id<AGSCancelable>)setViewpointGeometry:(AGSGeometry*)geometry completion:(nullable void(^)(BOOL finished))completion;

/** Zoom or pan the map with animation such that the given geometry fits the bounds of the map.
 @param geometry to fit to the bounds of the map
 @param paddingInScreenPoints to pad in each direction while fitting the geometry
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @return operation which can be canceled
 @note Any prior `setViewpoint...` animation will be canceled upon calling this method. If you want to chain together mulitple animations, wait for the prior animation to complete before calling this method.
 @since 100
 */
-(id<AGSCancelable>)setViewpointGeometry:(AGSGeometry*)geometry padding:(double)paddingInScreenPoints completion:(nullable void(^)(BOOL finished))completion;

NS_ASSUME_NONNULL_END
@end
