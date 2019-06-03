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

#import "AGSLoadableBase.h"

@class AGSGeodatabaseFeatureTable;
@class AGSEnvelope;


/** @file AGSGeodatabase.h */ //Required for Globals API doc

/** @brief A geodatabase on disk
 
 Instances of this class represent a local geodatabase (.geodatabase file) containing geographic datasets. 
 The geodatabase is based on the SQLite database engine.
 
 @since 100
 @see `AGSGeodatabaseSyncTask` to generate and synchronize a geodatabase with a supporting ArcGIS Feature service.
 */
@interface AGSGeodatabase : AGSLoadableBase
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Instantiates an existing geodatabase at the given path.
 @param fileURL to existing geodatabase (including .geodatabase file extension)
 @since 100
 @return A new geodatabase
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of an existing geodatabase (.geodatabase file), excluding the ".geodatabase" extension,
 within the application bundle or shared documents directory.
 @param name of the geodatabase (excluding the .geodatabase extension)
 @return A new geodatabase object
 @since 100
 */
-(instancetype)initWithName:(NSString *)name;

/** Instantiates an existing geodatabase at the given path.
 @param fileURL to existing geodatabase (including .geodatabase file extension)
 @since 100
 @return A new geodatabase
 */
+(instancetype)geodatabaseWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of an existing geodatabase (.geodatabase file), excluding the ".geodatabase" extension,
 within the application bundle or shared documents directory.
 @param name of the geodatabase (excluding the .geodatabase extension)
 @return A new geodatabase object
 @since 100
 */
+(instancetype)geodatabaseWithName:(NSString *)name;

#pragma mark -
#pragma mark properties

/** The extent used to generate the geodatabase.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *generateGeodatabaseExtent;

/** The geodatabase feature tables representing the geographic datasets in this geodatabase.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSGeodatabaseFeatureTable*> *geodatabaseFeatureTables;

/** Indicates whether or not a transaction is active in the geodatabase.
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL inTransaction;

/** The file URL of the geodatabase.
 @since 100
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** The geodatabase service URL.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *serviceURL;

/** The sync model defining how datasets within this geodatabase can be synchronized with the originating source. Only applicable if this geodatabase was originally downloaded from a sync-enabled ArGIS feature service (`#syncEnabled`).
 @since 100
 */
@property (nonatomic, assign, readonly) AGSSyncModel syncModel;

/** Indicates whether this geodatabase was originally downloaded from a sync-enabled ArGIS feature service. If `YES`, its data can be snychronized with the service.
 @return whether sync is enabled for the geodatabase or not.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isSyncEnabled) BOOL syncEnabled;

/** The sync ID of the geodatabase. Only available if the geodatabase is `#syncEnabled`.
 The sync ID is the same as the replica ID described in the REST documentation. This is used by the service that created the geodatabase to uniquely identify it when carrying out sync operations. It can also be used when unregistering the geodatabase after it has already been deleted locally using `AGSGeodatabaseSyncTask#unregisterGeodatabaseWithSyncID:completion:`
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) NSUUID *syncID;

#pragma mark -
#pragma mark methods

/** Retrieve the dataset that corresponds to the specified name.
 If the geodatabase was generated from an ArcGIS Feature service, the name corresponds to a layer in the ArcGIS Feature service (`AGSArcGISFeatureLayerInfo#serviceLayerName`)
 @param tableName Name of the dataset that is needed.
 @since 100
 */
-(nullable AGSGeodatabaseFeatureTable *)geodatabaseFeatureTableWithName:(NSString *)tableName;

/** Retrieve the dataset that corresponds to a particular layer ID in the ArcGIS Feature Service from which this geodatabase was generated.
 The ID must match `AGSArcGISFeatureLayerInfo#serviceLayerID`
 @param serviceLayerID ID of the layer for which the dataset is needed.
 @since 100
 */
-(nullable AGSGeodatabaseFeatureTable *)geodatabaseFeatureTableByServiceLayerID:(NSInteger)serviceLayerID;

/** Indicates whether the geodatabase has local edits.
 @return whether the geodatabase has local edits or not
 @since 100
 @note This method could take a long time to complete for geodatabase containing very large number of features (~50,000+). Do not invoke it on the main thread as it may degrade the responsiveness of your application.
 */
-(BOOL)hasLocalEdits;

/** Close connection to the geodatabase.
 All use of a geodatabase should cease before closing it. For example: terminate geodatabase synchronization, remove feature layers from maps, and release feature tables. Any attempt to access a geodatabase after it is closed will fail, resulting in an error. After closing a geodatabase, the geodatabase file can be deleted.
 @since 100.1
 */
-(void)close;

/** Starts a new transaction on the geodatabase. An error will be provided if another transaction is already active on the geodatabase. A geodatabase cannot be synchronized while a transaction is active.
 @note Nested transactions are not supported.
 @since 100.2
 */
-(BOOL)beginTransaction:(NSError **)error;

/** Commits changes in the current transaction to the geodatabase. This will also end the transaction. An error will be provided if a transaction has not been started on the geodatabase.
 @since 100.2
 */
-(BOOL)commitTransaction:(NSError **)error;

/** Discard changes in the current transaction from the geodatabase. This will also end the transaction. An error will be provided if a transaction has not been started on the geodatabase.
 @since 100.2
 */
-(BOOL)rollbackTransaction:(NSError **)error;

NS_ASSUME_NONNULL_END
@end
