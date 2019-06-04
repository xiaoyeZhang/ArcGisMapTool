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
@class AGSLocatorAttribute;

/** @file AGSLocatorInfo.h */ //Required for Globals API doc

/** @brief Metadata about the locator service or dataset used by `AGSLocatorTask`
 
 Instances of this class represent metadata about the locator service or dataset used by `AGSLocatorTask`.
 
 @since 100
 */
@interface AGSLocatorInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Name of the locator service or dataset.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Description of the locator service or dataset.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *locatorDescription;

/** The attribute fields that can be returned in the results of geocode or reverse geocode operations when searching for street intersections.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSLocatorAttribute*> *intersectionResultAttributes;

/** The locator properties. For example, MinimumCandidateScore, SideOffsetUnits, SpellingSensitivity, MinimumMatchScore and so on.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString *, NSString *> *properties;

/** The attribute fields that can be returned in the results of geocode or reverse geocode operations when searching for addresses or places.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSLocatorAttribute*> *resultAttributes;

/** The search attributes that can be used as inputs to multi-line geocode operations.
 Each attribute represents an individual address component in a multi-line address.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSLocatorAttribute*> *searchAttributes;

/** The default spatial reference in which result geometries are returned, unless overriden in 
 `AGSGeocodeParameters` or `AGSReverseGeocodeParameters`.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Indicates whether geocoding points of interest is supported.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsPOI;

/** Indicates whether geocoding addresses is supported. If supported, these can be specified as x/y coordinate pairs in the search text for geocode operations, where the spatial reference of the coordinates is WGS84. For example, "-115.172783,36.114789".
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsAddresses;

/** Indicates whether geocoding street intersections is supported.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsIntersections;

/** Indicates whether getting suggestions for geocode operations is supported.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsSuggestions;

/** Version of the locator service or dataset.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *version;

NS_ASSUME_NONNULL_END
@end
