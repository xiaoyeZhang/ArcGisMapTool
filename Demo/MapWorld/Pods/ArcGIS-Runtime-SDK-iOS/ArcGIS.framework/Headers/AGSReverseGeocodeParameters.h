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

/** @file AGSReverseGeocodeParameters.h */ //Required for Globals API doc

/** @brief Parameters to refine reverse-gecoding results returned by `AGSLocatorTask`
 
 Instances of this class represent input parameters to refine results of reverse-geocode operations on `AGSLocatorTask`
 
 @since 100
 @see `AGSLocatorInfo` for metadata about the locator service or dataset used by `AGSLocatorTask`. The metadata contains information that can be used to set up these parameters.
 */
@interface AGSReverseGeocodeParameters : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)reverseGeocodeParameters;

#pragma mark -
#pragma mark properties

/** List of attributes to be returned for each geocoded result.
 The attributes available are specified by `AGSLocatorInfo#resultAttributes` and `AGSLocatorInfo#intersectionResultAttributes`. Use "*" to return all attributes.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *resultAttributeNames;

/** Feature types used to filter the results of the reverse geocode operation.
 @note Currently only one feature type has any effect - specifying "intersection" causes the nearest street intersection to be returned.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *featureTypes;

/** Specifies whether the results of the operation should be persisted. The default value is false, which indicates the results of the operation can't be stored, but they can be temporarily displayed on a map for instance. If you store the results in a database, for example, you need to set this parameter to true.
 
 Applications are contractually prohibited from storing the results of geocoding transactions unless they perform the operation as an authenticated user. ArcGIS Online service credits are deducted from the organization account for each geocode transaction that uses this capability.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL forStorage;

/** The maximum distance (in meters) from the given location within which a matching address will be searched. Defaults to 1000 meters.
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxDistance;

/** The maximum number of results desired.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger maxResults;

/** The spatial reference in which result geometries should be returned.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *outputSpatialReference;

/** The language in which results should be returned.
 Based on the 2-digit ISO 639-1 language code.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *outputLanguageCode;

NS_ASSUME_NONNULL_END
@end
