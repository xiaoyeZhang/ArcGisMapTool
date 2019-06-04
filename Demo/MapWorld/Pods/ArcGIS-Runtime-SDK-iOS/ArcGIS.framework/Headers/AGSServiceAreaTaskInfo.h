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

@class AGSCostAttribute;
@class AGSRestrictionAttribute;
@class AGSTravelMode;

/** @file AGSServiceAreaTaskInfo.h */ //Required for Globals API doc

/** @brief Metadata about the network analyst service or dataset used by `AGSServiceAreaTask`
 
 Instances of this class represent metadata about the network analyst service or dataset used by `AGSServiceAreaTask`. It provides default values for the parameters created through `AGSServiceAreaTask#defaultServiceAreaParametersWithCompletion:`
 
 @since 100.1
 */
@interface AGSServiceAreaTaskInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties
/** A list of network attributes that can be accumulated and returned as part of the analysis result. You might want to perform the analysis using a distance-based impedance attribute and accumulate a time-based cost attribute. The results of this kind of analysis are based on distance, but they also specify how long it would take to reach a portion of the service area.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *accumulateAttributeNames;

/** A list of cost attributes that can be used as a travel mode impedance (`AGSTravelMode#impedanceAttributeName`) to optimize the route. The _key_ in the dictionary represents the name of the cost attribute.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,AGSCostAttribute*> *costAttributes;

/** Specifies the default cutoff beyond which the service area won't be computed. The cutoff is a measure of the attribute specified by `AGSTravelMode#impedanceAttributeName`. Cutoffs specify the quantity of the impedance to apply. They constrain the extent of the service area to be calculated. For example, if you apply breaks of 5, 10, and 15 when the impedance is set to Time, the service area will include those streets than can be reached within 5, 10, and 15 minutes.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *defaultImpedanceCutoffs;

/** The name of the travel mode that is used by default
 @since 100.1
 @see `#travelModes`
 */
@property (nonatomic, copy, readonly) NSString *defaultTravelModeName;

/** The type of service area geometries to generate at each cutoff when multiple cutoff values are specified. This parameter does not apply to line output.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSServiceAreaPolygonCutoffGeometry geometryAtCutoff;

/** Options available for generating polygons or lines for multiple facilities in relation to one another.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSServiceAreaOverlapGeometry geometryAtOverlap;

/** Name of the underlying transportation network dataset
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *networkName;

/** The spatial reference in which the result geometries are returned
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *outputSpatialReference;

/** Amount by which to buffer the output service area polygons. Specified in units of the `#outputSpatialReference`. The buffer refers to the distance from the road the service area polygon should extend when no other reachable roads are nearby, similar to a line buffer size. This is useful if the network is very sparse and you don't want the service area to cover large areas where there are no features.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double polygonBufferDistance;

/** The level of detail for output service area polygons
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSServiceAreaPolygonDetail polygonDetail;

/** The list of supported restrictions for constraining the analysis. The _key_ in the dictionary represents the name of the restriction attribute.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*, AGSRestrictionAttribute*> *restrictionAttributes;

/** Specifies whether to return the service area result geometries as polygons. Default is true.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL returnPolygons;

/** Specifies whether to return the service area result geometries as polylines. Default if false.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL returnPolylines;

/** Specifies when the service area starts from or finishes at the facility. If not specified, defaults to the time the task is executed.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSDate *startTime;

/** The list of supported restriction parameter values.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *supportedRestrictionUsageParameterValues;

/** Specifies the direction of travel for the service area computation.
 The direction you should choose depends on the nature of your service area analysis. The service area for a pizza delivery store, for example, should be created away from the facility since pizzas are delivered from the store to the customer. Alternatively, a hospital should choose the opposite direction since the urgent part of the trip for an incoming patient is going to the hospital, not returning home afterwards.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSTravelDirection travelDirection;

/** Specifies the available travel modes that can be used to customize the route.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSTravelMode*> *travelModes;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

