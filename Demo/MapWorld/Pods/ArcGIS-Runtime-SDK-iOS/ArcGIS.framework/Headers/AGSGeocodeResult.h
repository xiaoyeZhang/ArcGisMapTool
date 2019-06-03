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
@class AGSEnvelope;

/** @file AGSGeocodeResult.h */ //Required for Globals API doc

/** @brief Result of a geocode/reverse-geocode operation on `AGSLocatorTask`
 
 Instances of this class represent a result of a geocode/reverse-geocode operation on `AGSLocatorTask`
 
 @since 100
 */
@interface AGSGeocodeResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Attributes containing additional information about the result as requested by `AGSGeocodeParameters#resultAttributeNames` or `AGSReverseGeocodeParameters#resultAttributeNames`.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,id> *attributes;

/** Location of the result suitable to display on a map. For example, this may provide a more precise rooftop location of a house, whereas `#routeLocation` will provide the nearest street location.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *displayLocation;

/** The extent to zoom the map to for this result.
 @since 100
 @see `AGSGeoView#setViewpoint:`
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** Location provided as input to `AGSLocatorTask#reverseGeocodeWithLocation:completion:`.
 Only applicable for results of revere-geocode operations.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *inputLocation;

/** The user-friendly text to display for this result.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *label;

/** Location of the result to use if you want to generate a route to it.
 For example `#displayLocation` may provide a more precise rooftop location of a house, whereas `#routeLocation` will provide the nearest street location
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *routeLocation;

/** Numeric score between 0 and 100 for the result. A score of 100 means a perfect match, and 0 means no match.
 @since 100
 */
@property (nonatomic, assign, readonly) double score;

NS_ASSUME_NONNULL_END
@end
