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

@class AGSGeoprocessingParameterInfo;

/** @file AGSGeoprocessingTaskInfo.h */ //Required for Globals API doc

/** @brief Information about a Geoprocessing Task
 
 Instances of this class represent information about a Geoprocessing Task such as its name, description, execution type and descriptions of all the task's parameters.
 
 @since 100.1
 */
@interface AGSGeoprocessingTaskInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The URL to the task on the remote Geoprocessing service
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** Category of the geoprocessing task
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *category;

/** Description of the geoprocessing task
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** User-friendly name of the geoprocessing task
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *displayName;

/** The type of execution supported by the geoprocessing task
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSGeoprocessingExecutionType executionType;

/** URL to the documentation for the geoprocessing task
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSURL *helpURL;

/** Name of the geoprocessing task
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Information about the input and output parameters of the geoprocessing task.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSGeoprocessingParameterInfo*> *parameterInfos;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
