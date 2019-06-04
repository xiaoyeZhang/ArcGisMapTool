/*
 COPYRIGHT 2017 ESRI
 
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

#import "AGSLineOfSight.h"

@protocol AGSGeoElement;

/** @file AGSGeoElementLineOfSight.h */ //Required for Globals API doc

/** @brief Analysis of visibility along a line between two geo-elements
 
 Instances of this class represent an analysis object that evaluates visibility along a line defined by observer and target geo-element objects.
 
 The result of the analysis is a line between the observer and the target geo-element (each using Point geometry). Visible and obstructed portions of the line are displayed with unique colors (green and red by default). The observer and/or target may be moving, in which case visibility will be dynamically updated.
 
 @note The geo-elements must have a point geometry

 @license{Standard}
 @ingroup licensing
 @since 100.2
 */
@interface AGSGeoElementLineOfSight : AGSLineOfSight
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Intialize the analysis with the provided observer and target geo-elements. As a result of the analysis, a line is rendered between the observer and target elements with distinct colors representing visible and obstructed segments.
 @note The geo-elements must have a point geometry
 @param observerGeoElement defining the observer's location
 @param targetGeoElement defining the target's location
 @return Initialized line of sight analysis
 @since 100.2
 */
-(instancetype)initWithObserverGeoElement:(id<AGSGeoElement>)observerGeoElement targetGeoElement:(id<AGSGeoElement>)targetGeoElement;

/** Intialize the analysis with the provided observer and target geo-elements. As a result of the analysis, a line is rendered between the observer and target elements with distinct colors representing visible and obstructed segments.
 @note The geo-elements must have a point geometry
 @param observerGeoElement defining the observer's location
 @param targetGeoElement defining the target's location
 @return Initialized line of sight analysis
 @since 100.2
 */
+(instancetype)lineOfSightWithObserverGeoElement:(id<AGSGeoElement>)observerGeoElement targetGeoElement:(id<AGSGeoElement>)targetGeoElement;

#pragma mark -
#pragma mark properties

/** Geo-element defining the observer's location. The observer location is determined by the location of the geo-element plus any defined offsets (in X, Y, or Z). The offset position of the observer relative to the geo-element is always maintained, even when the geo-element moves.
 @note The geo-element must have a point geometry
 @since 100.2
 */
@property (nonatomic, strong, readonly) id<AGSGeoElement> observerGeoElement;

/** The offset along the X axis relative to the observer geo-element's point location.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double observerOffsetX;

/** The offset along the Y axis relative to the observer geo-element's point location.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double observerOffsetY;

/** The offset along the Z axis relative to the observer geo-element's point location.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double observerOffsetZ;

/** Geo-element defining the target's location. The target location is determined by the location of the geo-element plus any defined offsets (in X, Y, or Z). The offset position of the target relative to the geo-element is always maintained, even when the geo-element moves.
 @note The geo-element must have a point geometry
 @since 100.2
 */
@property (nonatomic, strong, readonly) id<AGSGeoElement> targetGeoElement;

/** The offset along the X axis relative to the target geo-element's point location.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double targetOffsetX;

/** The offset along the Y axis relative to the target geo-element's point location.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double targetOffsetY;

/** The offset along the Z axis relative to the target geo-element's point location.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double targetOffsetZ;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
