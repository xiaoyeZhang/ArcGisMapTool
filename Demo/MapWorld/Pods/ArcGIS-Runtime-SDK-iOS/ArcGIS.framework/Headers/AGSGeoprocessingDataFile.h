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
#import "AGSCancelable.h"
#import "AGSRemoteResource.h"

/** @file AGSGeoprocessingDataFile.h */ //Required for Globals API doc

/** @brief A geoprocessing parameter for files
 
 Instances of this class represent a parameter for files that can be used as input to a geoprocessing job or returned as the result of the job.
 The file can be on a remote server, or locally on disk. If the file is on a remote server and is intended to be used as an input to a geoprocessing job, make sure the geoprocessing service has access to the remote location.
 
 @since 100
 */
@interface AGSGeoprocessingDataFile : AGSGeoprocessingParameter
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers


/** Initialize the parameter with the given URL representing a file either on a remote server, or locally on disk. If the parameter is intended to be used as an input to a geoprocessing job, and if it is created with URL to a remote file, make sure the geoprocessing service has access to the remote location.
 @param URL value for the parameter
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

-(instancetype)initWithInputFileURL:(NSURL*)inputFileURL;

-(instancetype)initWithUploadID:(NSString*)uploadID;

+(instancetype)geoprocessingDataFile;

/** Initialize the parameter with the given URL representing a file either on a remote server, or locally on disk.  If the parameter is intended to be used as an input to a geoprocessing job, and if it is created with URL to a remote file, make sure the geoprocessing service has access to the remote location.
 @param URL  value for the parameter
 @since 100
 */
+(instancetype)geoprocessingDataFileWithURL:(NSURL*)URL;

+(instancetype)geoprocessingDataFileWithInputFileURL:(NSURL*)inputFileURL;

+(instancetype)geoprocessingDataFileWithUploadID:(NSString*)uploadID;

#pragma mark -
#pragma mark properties

/** Value of the parameter representing a local or remote file
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *URL;

@property (nullable, nonatomic, strong, readwrite) NSURL *inputFileURL;

@property (nonatomic, copy, readwrite) NSString *uploadID;

#pragma mark -
#pragma mark methods

/** Download the file to the specified location on disk. Only applicable when this parameter's `#URL` represents a remote file on a server.
 @param fileURL location on disk to where the remote file should be downloaded. If location is a directory, the file will be given the name of the file take from the end of `#URL`. Alternatively the location can be a destination filename within an existing directory. Note that any pre-existing file at that location with the same name will be deleted first.
 @param completion block that is invoked with the URL of where the file was downloaded to when the operation succeeds, or an error if it fails
 @since 100
 */
-(id<AGSCancelable>)downloadToFileURL:(NSURL*)fileURL completion:(void(^)(NSURL * __nullable fileURL, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
