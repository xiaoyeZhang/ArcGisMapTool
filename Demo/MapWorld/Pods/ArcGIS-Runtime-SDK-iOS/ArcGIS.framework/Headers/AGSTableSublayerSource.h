/*
 COPYRIGHT 2017 ESRI
 
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

#import "AGSSublayerSource.h"

/** @file AGSTableSublayerSource.h */ //Required for Globals API doc

/** @brief A source for `AGSArcGISMapImageSublayer` based on a dataset in a registered workspace
 
 Instances of this class represent a source for `AGSArcGISMapImageSublayer` based on a dataset, such as non-spatial table, feature class, or raster, that resides in a registered workspace of the ArcGIS Map Service. The workspace can be either a folder or geodatabase.
 
 @since 100.1
 @see `AGSArcGISMapImageSublayer#initWithID:source:`
 */
@interface AGSTableSublayerSource : AGSSublayerSource

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the source with the provided parameters.
 @param workspaceID ID of a registered workspace for the ArcGIS Map Service. The workspace can be either a folder or geodatabase.
 @param dataSourceName Name of a dataset (non-spatial table, feature class, or raster) in the workspace
 @since 100.1
 @return A new initialized source
 */
-(instancetype)initWithWorkspaceID:(NSString *)workspaceID
                    dataSourceName:(NSString *)dataSourceName;

/** Initialize the source with the provided parameters.
 @param workspaceID ID of a registered workspace for the ArcGIS Map Service. The workspace can be either a folder or geodatabase.
 @param dataSourceName Name of a dataset (non-spatial table, feature class, or raster) in the workspace
 @since 100.1
 @return A new initialized source
 */
+(instancetype)tableSublayerSourceWithWorkspaceID:(NSString *)workspaceID
                                   dataSourceName:(NSString *)dataSourceName;

#pragma mark -
#pragma mark properties

/** Name of a dataset (non-spatial table, feature class, or raster) in a registered workspace of the ArcGIS Map Service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *dataSourceName;

/** The geodatabase version to use.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *geodatabaseVersion;

/** ID of a registered workspace for the ArcGIS Map Service. The workspace can be either a folder or geodatabase.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *workspaceID;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

