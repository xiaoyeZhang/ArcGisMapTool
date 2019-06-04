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

#import "AGSAnalysis.h"

/** @file AGSViewshed.h */ //Required for Globals API doc

/** @brief Base class for all viewshed analysis
 
 Base class for viewshed analysis. Viewsheds can be calculated to show areas where observed objects, such as towers and turbines, can be seen, or, conversely, to show areas that can be seen from specified objects, such as steeples or observation decks.
 
 Visible and non-visible areas are determined for an area defined by an observer location, horizontal and vertical view angles, and a minimum/maximum distance range. These properties define a frustum (3D solid) inside of which visibility is calculated.
 
 @license{Standard}
 @ingroup licensing
 @since 100.2
 */
@interface AGSViewshed : AGSAnalysis
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Indicates whether or not the viewshed frustum should be visible
 @since 100.2
 */
@property (nonatomic, assign, readwrite, getter=isFrustumOutlineVisible) BOOL frustumOutlineVisible;

/** The horizontal angle (in degrees) of the observer's field of vision.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double horizontalAngle;

/** The vertical angle (in degrees) of the observer's field of vision.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double verticalAngle;

/** The maximum distance (in meters) from the observer at which visibility will be evaluated. This can be used to model factors that restrict the visible distance.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double maxDistance;

/** The minimum distance (in meters) from the observer at which visibility will be evaluated. This allows you to exclude obstacles close to the observer (the corner of a building, for example). Since terrain and other obstacles between the observer and the specified minimum distance are completely excluded from the analysis, this value should be relatively small.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double minDistance;

#pragma mark -
#pragma mark methods


/** The color used to render the frustum outline. This setting is applied to all viewshed analyses in the view.
 @since 100.2
 */
+(AGSColor *)frustumOutlineColor;

/** The color with which non-visible areas of all viewsheds will be rendered. This setting is applied to all viewshed analyses in the view.
 @since 100.2
 */
+(AGSColor *)obstructedColor;

/** The color with which visible areas of all viewsheds will be rendered. This setting is applied to all viewshed analyses in the view.
 @since 100.2
 */
+(AGSColor *)visibleColor;

/** Sets the color used to render the frustum outline. This setting is applied to all viewshed analyses in the view.
 @param frustumOutlineColor color of the viewshed frustum's outline
 @since 100.2
 */
+(void)setFrustumOutlineColor:(AGSColor *)frustumOutlineColor;
    
/** Sets the color with which non-visible areas of all viewsheds will be rendered. This setting is applied to all viewshed analyses in the view.
 @param obstructedColor used to render areas that are not visible
 @since 100.2
 */
+(void)setObstructedColor:(AGSColor *)obstructedColor;

/** Sets the color with which visible areas of all viewsheds will be rendered. This setting is applied to all viewshed analyses in the view.
 @param visibleColor used to render areas that are visible
 @since 100.2
 */
+(void)setVisibleColor:(AGSColor *)visibleColor;

NS_ASSUME_NONNULL_END
@end
