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

#import "AGSObject.h"

@class AGSServiceAreaFacility;
@class AGSPointBarrier;
@class AGSPolylineBarrier;
@class AGSPolygonBarrier;
@class AGSServiceAreaPolygon;
@class AGSServiceAreaPolyline;

/** @file AGSServiceAreaResult.h */ //Required for Globals API doc

/** @brief Result returned by `AGSServiceAreaTask`
 
 Instances of this class represent the result of `AGSServiceAreaTask#solveServiceAreaWithParameters:completion:`.
 The result is a collection of computed service area geometries, barriers used in the computation, and messages generated during the process.
 
 @since 100.1
 */
@interface AGSServiceAreaResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Facilities used in the analysis
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSServiceAreaFacility*> *facilities;

/** Informational messages that were generated while computing results.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *messages;

/** Point barriers used in the service area computation. Only available if `AGSServiceAreaParameters#returnPointBarriers` was enabled.
 @since 100.1
 @see `AGSServiceAreaParameters#setPointBarriers:` or `AGSServiceAreaParameters#setPointBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPointBarrier*> *pointBarriers;

/** Polygon barriers used in the service area computation. Only available if `AGSServiceAreaParameters#returnPolygonBarriers` was enabled.
 @since 100.1
 @see `AGSServiceAreaParameters#setPolygonBarriers:` or `AGSServiceAreaParameters#setPolygonBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPolygonBarrier*> *polygonBarriers;

/** Polyline barriers used in the service area computation. Only available if `AGSServiceAreaParameters#returnPolylineBarriers` was enabled.
 @since 100.1
 @see `AGSServiceAreaParameters#setPolylineBarriers:` or `AGSServiceAreaParameters#setPolylineBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPolylineBarrier*> *polylineBarriers;

#pragma mark -
#pragma mark methods

/** Service area polygons for the specified facility. Available if `AGSServiceAreaParameters#returnPolygons` was set to true
 @param facilityIndex index of the desired facility in the `#facilities` collection
 @since 100.1
 */
-(nullable NSArray<AGSServiceAreaPolygon*> *)resultPolygonsAtFacilityIndex:(NSInteger)facilityIndex;

/** Service area polylines for the specified facility. Available if `AGSServiceAreaParameters#returnPolylines` was set to true
 @param facilityIndex index of the desired facility in the `#facilities` collection
 @since 100.1
 */
-(nullable NSArray<AGSServiceAreaPolyline*> *)resultPolylinesAtFacilityIndex:(NSInteger)facilityIndex;

NS_ASSUME_NONNULL_END

@end

