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

@class AGSGeoprocessingParameter;
@class AGSArcGISMapImageLayer;

/** @file AGSGeoprocessingResult.h */ //Required for Globals API doc

/** @brief Result of a geoprocessing job
 
 Instances of this class represent results of a geoprocessing job initiated by `AGSGeoprocessingJob#startWithStatusHandler:completion:`
 
 @since 100
 */
@interface AGSGeoprocessingResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Layer that can display the results of the geoprocessing job on a map or a scene. Only available if the service was configured to provide results as a layer. This is useful in cases where the result contains a large number of features such that it will be faster and easier for the client to receive a map rather than the raw feature data which will then need to be rendered on the device, or if the result of the job is a nontransportable dataset such as a TIN or CAD drawing and the only way to send geography to the client is with a map image.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISMapImageLayer *mapImageLayer;

/** The raw result values of the geoprocessing job.
 @since 100
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,AGSGeoprocessingParameter*> *outputs;

NS_ASSUME_NONNULL_END
@end
