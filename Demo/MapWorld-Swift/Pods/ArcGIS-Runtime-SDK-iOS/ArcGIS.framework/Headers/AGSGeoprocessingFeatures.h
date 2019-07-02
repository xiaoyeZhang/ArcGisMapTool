/*
 COPYRIGHT 2016 ESRI
 
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

#import "AGSGeoprocessingParameter.h"
#import "AGSFeatureSet.h"
#import "AGSRemoteResource.h"

/** @file AGSGeoprocessingFeatures.h */ //Required for Globals API doc

/** @brief A geoprocessing parameter for feature data
 
 Instances of this class represent a parameter for feature data that can be used as input to a geoprocessing job or returned as the result of the job.
 
 @since 100
 */
@interface AGSGeoprocessingFeatures : AGSGeoprocessingParameter
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)geoprocessingFeatures;


/** Initialize the parameter with given url
 @param URL to an ArcGIS Feature service containing the feature data for this parameter
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize the parameter with given url
 @param URL to an ArcGIS Feature service containing the feature data for this parameter
 @since 100
 */
+(instancetype)geoprocessingFeaturesWithURL:(NSURL*)URL;

/** Initialize the parameter with given features
 @param featureSet containing the feature data for this parameter
 @since 100
 */
-(instancetype)initWithFeatureSet:(id<AGSFeatureSet>)featureSet;

/** Initialize the parameter with given features
 @param featureSet containing the feature data for this parameter
 @since 100
 */
+(instancetype)geoprocessingFeaturesWithFeatureSet:(id<AGSFeatureSet>)featureSet;

#pragma mark -
#pragma mark properties

/** URL to an ArcGIS Feature service contianing the feature data for this parameter. Only applicable if this parameter was initialized with a URL.
 @since 100
 @see `#fetchOutputFeaturesWithCompletion:` to fetch the features from the service
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *URL;

/** Indicates whether this parameter represents feature data in an ArcGIS feature service that can be fetched using `#fetchOutputFeaturesWithCompletion:`
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canFetchOutputFeatures;

/** The feature data for this parameter
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) id<AGSFeatureSet> features;

#pragma mark -
#pragma mark methods

/** Fetches features from the ArcGIS Feature service at `#URL`. This can be used to fetch features if #features is nil. It is not necessary to call this if #features is already populated.
 @param completion block that is invoked with the features if the operation succeeds, or with an error if the operation fails.
 @since 100
 */
-(id<AGSCancelable>)fetchOutputFeaturesWithCompletion:(void(^)(id<AGSFeatureSet> __nullable features, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
