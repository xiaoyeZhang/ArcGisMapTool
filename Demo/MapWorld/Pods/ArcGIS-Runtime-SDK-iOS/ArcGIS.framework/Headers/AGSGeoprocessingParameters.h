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
@class AGSSpatialReference;

/** @file AGSGeoprocessingParameters.h */ //Required for Globals API doc

/** @brief Input parameters for a geoprocessing job
 
 Instances of this class serve as input parameters for creating a new geoprocessing job.
 
 @see `AGSGeoprocessingTask#createJobWithParameters:` to create a geoprocessing job
 @since 100
 */
@interface AGSGeoprocessingParameters : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a new instance of geoprocessing parameters to use as inputs for creating a new geoprocessing job.
 @param executionType specifying whether the job should be submitted to the server in a manner suitable for long-running processes so that the client can close the connection to the service and then periodically check for status to decide when to retrieve results, or if the job should be executed as an asynchronous operation suitable for short-running operations where the client keeps the connection open and waits for the operation to complete.
 @since 100
 */
-(instancetype)initWithExecutionType:(AGSGeoprocessingExecutionType)executionType;

/** Initialize a new instance of geoprocessing parameters to use as inputs for creating a new geoprocessing job.
 @param executionType specifying whether the job should be submitted to the server in a manner suitable for long-running processes so that the client can close the connection to the service and then periodically check for status to decide when to retrieve results, or if the job should be executed as an asynchronous operation suitable for short-running operations where the client keeps the connection open and waits for the operation to complete.
 @since 100
 */
+(instancetype)geoprocessingParametersWithExecutionType:(AGSGeoprocessingExecutionType)executionType;

#pragma mark -
#pragma mark properties

/** Mode specifying whether the job should be submitted to the server in a manner suitable for long-running processes so that the client can close the connection to the service and then periodically check for status to decide when to retrieve results, or if the job should be executed as an asynchronous operation suitable for short-running operations where the client keeps the connection open and waits for the operation to complete.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSGeoprocessingExecutionType executionType;

/** The collection of inputs for the job.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSDictionary<NSString*,AGSGeoprocessingParameter*> *inputs;

/** The spatial reference of the result geometries. If not specified, the result geometries are in the same spatial reference as the input geometries. If `#processSpatialReference` is specified and `outputSpatialReference` is not specified, the result geometries will be returned in `processSpatialReference`.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *outputSpatialReference;

/** The intermediate spatial reference that the geoprocessing task will use to perform geometric operations. If `processSpatialReference` is specified and `#outputSpatialReference` is not specified, the result geometries will be returned in `processSpatialReference`.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *processSpatialReference;

/** Specifies whether the result geometries should contain M (measure) values.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnM;

/** Specifies whether the result geometries should contain Z (elevation) values.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnZ;

NS_ASSUME_NONNULL_END
@end
