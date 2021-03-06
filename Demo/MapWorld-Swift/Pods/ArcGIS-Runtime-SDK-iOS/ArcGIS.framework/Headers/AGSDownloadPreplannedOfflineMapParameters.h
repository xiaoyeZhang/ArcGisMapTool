
/*
 COPYRIGHT 2018 ESRI
 
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

@class AGSPreplannedMapArea;

/** @file AGSDownloadPreplannedOfflineMapParameters.h */ //Required for Globals API doc

/** @brief Parameters used with `AGSOfflineMapTask` to take a preplanned map area offline
 
 Instances of this class represent parameters that are used with `AGSOfflineMapTask#downloadPreplannedOfflineMapJobWithArea:downloadDirectory:` to create a job that can take a preplanned map area offline.
 
 @since 100.4
 */
@interface AGSDownloadPreplannedOfflineMapParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a download preplanned offline map parameters object with the given preplanned map area
 @param preplannedMapArea preplanned map area representing area to be downloaded for offline use
 @return initialized parameters
 @since 100.4
 */
-(instancetype)initWithPreplannedMapArea:(AGSPreplannedMapArea *)preplannedMapArea;

/** Initialize a download preplanned offline map parameters object
 @return initialized parameters
 @since 100.4
 */
+(instancetype)preplannedOfflineMapParameters;

/** Initialize a download preplanned offline map parameters object with the given preplanned map area
 @param preplannedMapArea preplanned map area representing area to be downloaded for offline use
 @return initialized parameters
 @since 100.4
 */
+(instancetype)preplannedOfflineMapParametersWithPreplannedOfflineMapArea:(AGSPreplannedMapArea *)preplannedMapArea;

#pragma mark -
#pragma mark properties

/** Indicates whether or not the job should continue running in the event of a failure
 to take a layer offline.
 If this property is true, failure to take a layer or table offline will not fail the job, the failure will be
 exposed in the job result. If this property is false, failure to take a layer or table offline will fail the job
 and no more layers or tables will be taken offline. The layer or table's error will be available as the job's error.
 Default value is `true`
 @since 100.4
 */
@property (nonatomic, assign, readwrite) BOOL continueOnErrors;

/** Indicates whether or not the basemap will be included in the offline map to be downloaded.
 Default value is `true`.
 @since 100.4
 */
@property (nonatomic, assign, readwrite) BOOL includeBasemap;

/** The preplanned map area that will be downloaded for offline use.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readwrite) AGSPreplannedMapArea *preplannedMapArea;

/** The path to a directory on the device where the local basemap file is located.
 This property should be set (along with `AGSDownloadPreplannedOfflineMapParameters#referenceBasemapFilename`) in order to use a basemap which is already on the device, rather than downloading.
 This property supports any directory specified as either an absolute path or a path relative to the parent directory of the mobile map package.
 If the directory does not exist, or does not contain the specified basemap filename, the `AGSDownloadPreplannedOfflineMapJob` will fail.
 Note that this property is ignored if `AGSDownloadPreplannedOfflineMapParameters#includeBasemap` is `false`.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *referenceBasemapDirectory;

/**  The name of a local basemap file on the device which can be used rather than downloading an online basemap.
 The local basemap filename must end with .tpk, .tpkx or .vtpk since these are the supported file formats. This property can be read directly from settings applied by the author of the online web map (see `AGSOfflineSettings`) or set by user code to a file known to be on the device. This property will be populated from online settings when created with `AGSOfflineMapTask#defaultDownloadPreplannedOfflineMapParametersWithArea:completion`.
 If you wish to use the specified local basemap rather than downloading, you must also set `AGSDownloadPreplannedOfflineMapParameters#referenceBasemapDirectory`.
 If the directory does not exist, or does not contain the specified basemap filename, the `AGSDownloadPreplannedOfflineMapJob` will fail.
 The spatial reference of the reference basemap is used for the offline map when it is different to the online map's spatial reference.
 Note that this property is ignored if `AGSDownloadPreplannedOfflineMapParameters#includeBasemap` is `false`.
 @since 100.5
 */
@property (nonatomic, copy, readwrite) NSString *referenceBasemapFilename;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
