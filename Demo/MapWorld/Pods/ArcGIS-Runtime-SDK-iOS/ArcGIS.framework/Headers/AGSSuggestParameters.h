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

@class AGSPoint;
@class AGSGeometry;

/** @file AGSSuggestParameters.h */ //Required for Globals API doc

/** @brief Input parameters for a suggest operation on `AGSLocatorTask`
 
 Instances of this class represent input parameters for `AGSLocatorTask#suggestWithSearchText:parameters:completion:`
 
 @since 100
 */
@interface AGSSuggestParameters : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)suggestParameters;

#pragma mark -
#pragma mark properties

/** Categories by which to filter suggestions. Categories represent address and place types, for example "city", "school", "Ski Resort". By default no category filtering is applied.
 @since 100
 @see https://developers.arcgis.com/rest/geocode/api-reference/geocoding-category-filtering.htm
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *categories;

/** Country by which to filter suggestions. This can speed up the operation.
 Acceptable values include the full country name in English or the official language of the country, the ISO 3166-1 2-digit country code, or the ISO 3166-1 3-digit country code.
 @since 100
 @see https://developers.arcgis.com/rest/geocode/api-reference/geocode-coverage.htm
 */
@property (nonatomic, copy, readwrite) NSString *countryCode;

/** The maximum number of suggestions required.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger maxResults;

/** The location by which to prioritize/order suggestions. Suggestions that fall within a 50 KM buffer of this location are boosted in rank so that they show up higher in the list, but others further away are still included. To exclude suggestions based on a region, use `#searchArea` instead. The preferred search location is only intended to influence the sort order so that the most locationally-relevant candidates are returned first.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSPoint *preferredSearchLocation;

/** The search area used to spatially filter the suggestions. Only suggestions that lie within this area are included.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *searchArea;

NS_ASSUME_NONNULL_END
@end
