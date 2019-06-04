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

#import "AGSLoadableBase.h"

@class AGSElevationSource;
@class AGSPoint;
@class AGSBackgroundGrid;

/** @file AGSSurface.h */ //Required for Globals API doc

/** @brief A surface providing elevation context for a scene
 
 Instance of this class represent a surface which provides an elevation context for a scene's basemap and operational layers. The surface is defined by a mesh of elevation points. Z values for geographic data can then be interpreted as Relative/Draped (placed using a specific Surface) or Absolute (not using any Surface).
 
 @since 100
 */
@interface AGSSurface : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)surface;

#pragma mark -
#pragma mark properties

/** The background grid used with the surface.
 @since 100.1
 */
@property (nonatomic, strong, readwrite) AGSBackgroundGrid *backgroundGrid;

/** The exaggeration for the surface. The altitude values of the surface data are multiplied by the exaggeration value. Default is 1.0.
 @since 100
 */
@property (nonatomic, assign, readwrite) float elevationExaggeration;

/** The list of elevation sources in the surface. Values from all sources are combined to arrive at final elevation values for the surface.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSElevationSource*> *elevationSources;

/** Indicates whether the surface is enabled or not.
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isEnabled) BOOL enabled;

/** Name of the surface.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *name;

#pragma mark -
#pragma mark methods

/** Elevation (in meters) at the given location on the surface
 @param point on the surface
 @param completion block that will be invoked when the operation completes. 
 @since 100
 */
-(id<AGSCancelable>)elevationForPoint:(AGSPoint*)point completion:(void(^)(double elevation, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end
