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

@class AGSSpatialReference;
@class AGSCostAttribute;
@class AGSRestrictionAttribute;
@class AGSTravelMode;

/** @file AGSRouteTaskInfo.h */ //Required for Globals API doc

/** @brief Metadata about the network analyst service or dataset used by `AGSRouteTask`
 
 Instances of this class represent metadata about the network analyst service or dataset used by `AGSRouteTask`. It provides default values for the parameters created through `AGSRouteTask#defaultRouteParametersWithCompletion:`
 
 @since 100
 */
@interface AGSRouteTaskInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** A list of network attributes that can be accumulated and returned as part of the route. You might want to perform the analysis using a distance-based impedance attribute and accumulate a time-based cost attribute. The results of this kind of analysis are based on distance, but they also specify how long it would take to reach a portion of the service area.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *accumulateAttributeNames;

/** A list of cost attributes that can be used as a travel mode impedance (`AGSTravelMode#impedanceAttributeName`) to optimize the route. The _key_ in the dictionary represents the name of the cost attribute.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,AGSCostAttribute*> *costAttributes;

/** The name of travel mode that is used by default
 @since 100
 @see `#travelModes`
 */
@property (nonatomic, copy, readonly) NSString *defaultTravelModeName;

/** The linear units used while providing distances for turn-by-turn directions.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSUnitSystem directionsDistanceUnits;

/** The language used when computing directions. For example, en, fr, pt-BR, zh-Hans etc.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *directionsLanguage;

/** The style used for providing directions.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSDirectionsStyle directionsStyle;

/** Specifies whether or not to optimize the order of the stops in the route.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL findBestSequence;

/** The time the route begins. If not specified, defaults to the time the task is executed.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *startTime;

/** Name of the underlying transportation network dataset
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *networkName;

/** The spatial reference in which the result geometries are returned, unless `AGSRouteParameters#outputSpatialReference` is specified.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *outputSpatialReference;

/** If `YES`, keeps the first stop fixed in the sequence even when `#findBestSequence` is enabled.
 Only applicable if `#findBestSequence` is enabled.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL preserveFirstStop;

/** If `YES`, keeps the last stop fixed in the sequence even when `#findBestSequence` is enabled.
 Only applicable if `#findBestSequence` is enabled.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL preserveLastStop;

/** The list of supported restrictions for constraining the route. The _key_ in the dictionary represents the name of the restriction attribute.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,AGSRestrictionAttribute*> *restrictionAttributes;

/** Specifies the type of route geometry to return in the result `AGSRoute#routeGeometry`
 @since 100
 */
@property (nonatomic, assign, readonly) AGSRouteShapeType routeShapeType;

/** The list of languages supported for generating turn-by-turn driving directions.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *supportedLanguages;

/** The list of supported restriction parameter values.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *supportedRestrictionUsageParameterValues;

/** Specifies the available travel modes that can be used to customize the route.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSTravelMode*> *travelModes;

NS_ASSUME_NONNULL_END
@end
