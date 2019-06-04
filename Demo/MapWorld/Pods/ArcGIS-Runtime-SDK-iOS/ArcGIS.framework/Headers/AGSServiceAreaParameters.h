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
@class AGSArcGISFeatureTable;
@class AGSQueryParameters;
@class AGSPointBarrier;
@class AGSPolygonBarrier;
@class AGSPolylineBarrier;
@class AGSSpatialReference;
@class AGSTravelMode;

/** @file AGSServiceAreaParameters.h */ //Required for Globals API doc

/** @brief Input parameters for `AGSServiceAreaTask`
 
 Instances of this class represent input parameters for finding service areas using `AGSServiceAreaTask`.
 
 @note Consider using the convenience method `AGSServiceAreaTask#defaultServiceAreaParametersWithCompletion:` to get an instance of this class that is initialized with smart default values based on the task's metadata (`AGSServiceAreaTask#serviceAreaTaskInfo`)
 
 @since 100.1
 */
@interface AGSServiceAreaParameters : AGSObject <NSCopying>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** A list of network attributes to be accumulated and returned as part of the result. You might want to perform the analysis using a distance-based impedance attribute and accumulate a time-based cost attribute. The results of this kind of analysis are based on distance, but they also specify how long it would take to reach a portion of the service area.
 Available attributes are specified by `AGSServiceAreaTaskInfo#accumulateAttributeNames`. These attributes represent costs such as Drive Time, Distance, Toll expenses, etc.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *accumulateAttributeNames;

/** Specifies the default cutoffs for generating the service areas. Each facility can specify its own cutoff values, but if they don't, this default will be used. The cutoff is a measure of the attribute specified by `AGSTravelMode#impedanceAttributeName`. 

 Cutoffs specify the quantity of the impedance to apply. They constrain the extent of the service area to be calculated. For example, if you apply breaks of 5, 10, and 15 when the impedance is set to Time, the service area will include those streets than can be reached within 5, 10, and 15 minutes.
 @see `AGSFacility#impedanceCutoff`
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSArray<NSNumber*> *defaultImpedanceCutoffs;

/** The type of service area geometries to generate at each cutoff when multiple cutoff values are specified. This parameter does not apply to line output.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSServiceAreaPolygonCutoffGeometry geometryAtCutoff;

/** Options available for generating polygons or lines for multiple facilities in relation to one another.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSServiceAreaOverlapGeometry geometryAtOverlap;

/** The spatial reference in which the result geometries should be returned.
 If nil, the results will be returned in the spatial reference specified by `AGSServiceAreaTaskInfo#outputSpatialReference`.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *outputSpatialReference;


/** Amount by which to buffer the output service area polygons. Specified in units of the `#outputSpatialReference`. The buffer refers to the distance from the road the service area polygon should extend when no other reachable roads are nearby, similar to a line buffer size. This is useful if the network is very sparse and you don't want the service area to cover large areas where there are no features.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double polygonBufferDistance;

/** The level of detail for output service area polygons
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSServiceAreaPolygonDetail polygonDetail;

/** Specifies whether to return the point barriers used while computing the result.
 The barriers will be returned in  `AGSServiceAreaResult#pointBarriers`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnPointBarriers;

/** Specifies whether to return the polygon barriers used while computing the result.
 The barriers will be returned in  `AGSServiceAreaResult#polygonBarriers`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnPolygonBarriers;

/** Specifies whether to return the service area result geometries as polygons. Default is true.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnPolygons;

/** Specifies whether to return the polyline barriers used while computing the result.
 The barriers will be returned in  `AGSServiceAreaResult#polylineBarriers`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnPolylineBarriers;

/** Specifies whether to return the service area result geometries as polylines. Default if false.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnPolylines;

/** Specifies when the service area starts from or finishes at the facility. If not specified, defaults to the time the task is executed.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) NSDate *startTime;

/** Specifies the direction of travel for the service area computation.
The direction you should choose depends on the nature of your service area analysis. The service area for a pizza delivery store, for example, should be created away from the facility since pizzas are delivered from the store to the customer. Alternatively, a hospital should choose the opposite direction since the urgent part of the trip for an incoming patient is going to the hospital, not returning home afterwards.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSTravelDirection travelDirection;

/** Specifies the travel mode to use when computing the service areas. A travel mode represents a collection of network settings, such as travel restrictions and U-turn policies, that determine how a pedestrian, car, truck, or other medium of transportation moves through the network.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSTravelMode *travelMode;

#pragma mark -
#pragma mark methods

/** Clear any facilities that may have been set earlier
 @since 100.1
 */
-(void)clearFacilities;

/** Clear any point barriers that may have been set earlier
 @since 100.1
 */
-(void)clearPointBarriers;

/** Clear any polygon barriers that may have been set earlier
 @since 100.1
 */
-(void)clearPolygonBarriers;

/** Clear any polyline barriers that may have been set earlier
 @since 100.1
 */
-(void)clearPolylineBarriers;

/** Set the facilities to use in the analysis
 @param facilities to use
 @since 100.1
 */
-(void)setFacilities:(NSArray<AGSServiceAreaFacility*>*)facilities;

/** Set the facilities to use in the analysis
 @param featureTable containing point features to use as facilities
 @param queryParameters to filter which features to use
 @since 100.1
 */
-(void)setFacilitiesWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Set point barriers to avoid while computing the service area
 @param pointBarriers barriers to avoid
 @since 100.1
 */
-(void)setPointBarriers:(NSArray<AGSPointBarrier*>*)pointBarriers;

/** Set point barriers to avoid while computing the service area
 @param featureTable containing point features to use as barriers
 @param queryParameters to filter which features to use
 @since 100.1
 */
-(void)setPointBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Set polygon barriers to avoid while computing the service area
 @param polygonBarriers barriers to avoid
 @since 100.1
 */
-(void)setPolygonBarriers:(NSArray<AGSPolygonBarrier*>*)polygonBarriers;

/** Set polygon barriers to avoid while computing the service area
 @param featureTable containing polygon features to use as barriers
 @param queryParameters to filter which features to use
 @since 100.1
 */
-(void)setPolygonBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Set polyline barriers to avoid while computing the service area
 @param lineBarriers barriers to avoid
 @since 100.1
 */
-(void)setPolylineBarriers:(NSArray<AGSPolylineBarrier*>*)lineBarriers;

/** Set polyline barriers to avoid while computing the service area
 @param featureTable containing polyline features to use as barriers
 @param queryParameters to filter which features to use
 @since 100.1
 */
-(void)setPolylineBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;


NS_ASSUME_NONNULL_END

@end
