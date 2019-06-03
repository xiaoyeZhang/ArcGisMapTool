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

@class AGSPointBarrier;
@class AGSPolylineBarrier;
@class AGSPolygonBarrier;
@class AGSRoute;

/** @file AGSRouteResult.h */ //Required for Globals API doc

/** @brief Result returned by `AGSRouteTask`
 
 Instances of this class represent the result of `AGSRouteTask#solveRouteWithParameters:completion:`.
 The result is a collection of computed routes, barriers used in the computation, and messages generated during the process.

 @since 100
 */
@interface AGSRouteResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The language used when computing directions. For example, en, fr, pt-BR, zh-Hans, etc. The list of languages supported is available in `AGSRouteTaskInfo#supportedLanguages`
 @since 100
 @see `AGSRouteParameters#directionsLanguage` to specify which language to use
 */
@property (nonatomic, copy, readonly) NSString *directionsLanguage;

/** Informational messages that were generated while computing routes.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *messages;

/** Point barriers used in the route computation. Only available if `AGSRouteParameters#returnPointBarriers` was enabled.
 @since 100
 @see `AGSRouteParameters#setPointBarriers:` or `AGSRouteParameters#setPointBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPointBarrier*> *pointBarriers;

/** Polygon barriers used in the route computation. Only available if `AGSRouteParameters#returnPolygonBarriers` was enabled.
 @since 100
 @see `AGSRouteParameters#setPolygonBarriers:` or `AGSRouteParameters#setPolygonBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPolygonBarrier*> *polygonBarriers;

/** Polyline barriers used in the route computation. Only available if `AGSRouteParameters#returnPolylineBarriers` was enabled.
 @since 100
 @see `AGSRouteParameters#setPolylineBarriers:` or `AGSRouteParameters#setPolylineBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPolylineBarrier*> *polylineBarriers;

/** Each elements represents an indepdendent route with its own driving directions. Stops are grouped into diffrent routes based on `AGSStop#routeName`.
 Only available if `AGSRouteParameters#returnRoutes` was enabled.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSRoute*> *routes;

NS_ASSUME_NONNULL_END
@end
