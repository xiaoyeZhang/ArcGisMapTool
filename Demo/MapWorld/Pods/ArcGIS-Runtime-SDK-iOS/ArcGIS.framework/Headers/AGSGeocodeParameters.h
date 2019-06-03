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
@class AGSPoint;
@class AGSGeometry;

/** @file AGSGeocodeParameters.h */ //Required for Globals API doc

/** @brief Parameters to refine gecoding results returned by `AGSLocatorTask`
 
 Instances of this class represent input parameters to refine results of geocode operations on `AGSLocatorTask`
 
 @since 100
 @see `AGSLocatorInfo` for metadata about the locator service or dataset used by `AGSLocatorTask`. The metadata contains information that can be used to set up these parameters.
 */
@interface AGSGeocodeParameters : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)geocodeParameters;

#pragma mark -
#pragma mark properties

/** List of attributes to be returned for each geocoded result.
 The attributes available are specified by `AGSLocatorInfo#resultAttributes` and `AGSLocatorInfo#intersectionResultAttributes`. Use "*" to return all attributes.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *resultAttributeNames;

/** Categories by which to filter geocoded results. Categories represent address and place types, for example "city", "school", "Ski Resort". By default no category filtering is applied.
 @since 100
 @see https://developers.arcgis.com/rest/geocode/api-reference/geocoding-category-filtering.htm
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *categories;

/** Country by which to filter results. This can speed up the geocoding operation.
 Acceptable values include the full country name in English or the official language of the country, the ISO 3166-1 2-digit country code, or the ISO 3166-1 3-digit country code.
 @since 100
 @see https://developers.arcgis.com/rest/geocode/api-reference/geocode-coverage.htm
 */
@property (nonatomic, copy, readwrite) NSString *countryCode;

/** Specifies whether the results of the operation should be persisted. The default value is false, which indicates the results of the operation can't be stored, but they can be temporarily displayed on a map for instance. If you store the results in a database, for example, you need to set this parameter to true.
 
 Applications are contractually prohibited from storing the results of geocoding transactions unless they perform the operation as an authenticated user. ArcGIS Online service credits are deducted from the organization account for each geocode transaction that uses this capability.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL forStorage;

/** The maximum number of results desired.
 @note Only applies when using an ArcGIS Geocode service (i.e not geocoding locally on the device using a locator dataset). Please consult the service properties for information on the largest acceptable value for this parameter. 
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger maxResults;

/** Minimum match score of the results. Results which have a match score lower than this value will not be returned.
 @note Only applies when geocoding locally on the device using a locator dataset (i.e not using an ArcGIS Geocode service)
 @since 100
 */
@property (nonatomic, assign, readwrite) double minScore;

/** The language in which results should be returned.
 Based on the 2-digit ISO 639-1 language code.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *outputLanguageCode;

/** The spatial reference in which result geometries should be returned.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *outputSpatialReference;

/** The location by which to prioritize/order geocoded results. Results that fall within a 50 KM buffer of this location are boosted in rank so that they show up higher in the list of candidates, but results further away are still included. To exclude results based on a region, use `#searchArea` instead. The preferred search location is only intended to influence the sort order of results so that the most locationally-relevant candidates are returned first.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSPoint *preferredSearchLocation;

/** The search area used to spatially filter the geocoded results. Only results that lie within this area are included.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *searchArea;

NS_ASSUME_NONNULL_END
@end
