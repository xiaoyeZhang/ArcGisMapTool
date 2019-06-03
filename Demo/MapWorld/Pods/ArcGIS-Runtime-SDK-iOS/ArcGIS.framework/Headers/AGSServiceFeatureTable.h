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
#import "AGSArcGISFeatureTable.h"
#import "AGSRemoteResource.h"

@class AGSFeatureEditResult;
@class AGSRelationshipInfo;
@class AGSItem;

/** @file AGSServiceFeatureTable.h */ //Required for Globals API doc

/** @brief A dataset from an individual layer or table in ArcGIS Map or Feature service
 
 Instances of this class represent datasets in an individual layer or table of an ArcGIS Map or Feature service. The service may be hosted in the cloud on ArcGIS Online, or on-premises on an ArcGIS Server. The data is retrieved
 from the service as needed and stored in a temporary geodatabase on disk. How data is retrieved depends upon the `#featureRequestMode`.
 
 
 
 When using a Feature service, you can potentially create, delete, and update the data depending upon whether the service allows those operations, who owns the data, and what ownership-based access control policies are in place. Refer to the @c #editCapabilities, @c #canUpdateFeature:, @c #canDeleteFeature:, for information on what's permitted.
 
 Edits can be performed through `#addFeature:completion`,`#addFeatures:completion:`, `#deleteFeature:completion:`, `#deleteFeatures:completion:`, `#updateFeature:completion:`, `#updateFeatures:completion:`. However, these edits only affect the temporary geodatabase and must be committed to the service through `#applyEditsWithCompletion:`
 
 If the service supports attachments (@c #hasAttachments), you can also view and potentially edit the attachments.
 
 You can also query the data based on SQL expressions and/or spatial relationships.
 
 This class is typically used in conjunction with @c AGSFeatureLayer to display feature data on a map. It can handle temporary network outages while still allowing you to work with the data that
 has already been retrieved from the service. Your edits are immediately peristed to the local geodatabase and can be applied to the service later when network connectivity is restored.
 
 Service feature table adopts the loadable pattern; many of its properties are initialized asynchronously after connecting to the service. See `AGSLoadable` for more information.
 
 
 @see @c AGSFeatureLayer to visualize features from this dataset on a map.
 @since 100
 */
@interface AGSServiceFeatureTable : AGSArcGISFeatureTable <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the table with the given URL
 @param url The URL of an individual layer or table in ArcGIS Map or Feature service whose data needs to be accessed or edited
 @since 100
 */
-(instancetype)initWithURL:(NSURL *)url;

/** Convenience method to initialize this table to be the one that participates in the specified relationship with the provided table
 @param table that this table is related to through the specified relationship
 @param relationshipInfo specifying the relationship that this table participates in with the provided `table`
 @since 100.1
 */
 -(instancetype)initWithTable:(AGSServiceFeatureTable *)table
            relationshipInfo:(AGSRelationshipInfo *)relationshipInfo;

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the layer with the provided information
 @param item representing an ArcGIS Feature Serivce. The item's type must be `AGSPortalItemTypeFeatureService`
 @param layerID ID of an individual layer in the ArcGIS Feature service represented by the `item`
 @return Initialized layer
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item layerID:(NSInteger)layerID;

/** Initialize the table with the given URL
 @param URL The URL of an individual layer or table in ArcGIS Map or Feature service whose data needs to be accessed or edited
 @since 100
 */
+(instancetype)serviceFeatureTableWithURL:(NSURL*)URL;

/** Convenience method to initialize this table to be the one that participates in the specified relationship with the provided table
 @param table that this table is related to through the specified relationship
 @param relationshipInfo specifying the relationship that this table participates in with the provided `table`
 @since 100.1
 */
+(instancetype)serviceFeatureTableWithTable:(AGSServiceFeatureTable *)table
                           relationshipInfo:(AGSRelationshipInfo *)relationshipInfo;

/** Initialize the layer with the provided information
 @param item representing an ArcGIS Feature Serivce. The item's type must be `AGSPortalItemTypeFeatureService`
 @param layerID ID of an individual layer in the ArcGIS Feature service represented by the `item`
 @return Initialized layer
 @since 100
 */
+(instancetype)serviceFeatureTableWithItem:(AGSItem*)item layerID:(NSInteger)layerID;

#pragma mark -
#pragma mark properties

/** This factor determines the size of the buffer around the map's current extent for which data is retrieved from the service. Data is not retrieved again until either it expires or the map extent changes and is
 no longer in the buffered extent. Buffer factor can be up to 10. If it is set to 0 or 1,
 every time the map extent is changed data for that extent will be requested from the service. 
 Default value is 2
 @since 100
 @note Only applies to `AGSFeatureRequestModeOnInteractionCache`
 */
@property (nonatomic, assign, readwrite) double bufferFactor;

/** The definition expression in the syntax of a SQL where clause used for filtering features queried in this table.
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSString *definitionExpression;

/** Specifies how data should be retrieved from the service. Default is AGSFeatureRequestModeOnInteractionCache.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSFeatureRequestMode featureRequestMode;

/** The geodatabase version.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *geodatabaseVersion;

/** Item representing an ArcGIS Feature Serivce. Only available if the table was instantiated with an item to begin with.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

#pragma mark -
#pragma mark methods

/** Apply the temporary edits in the local geodatabase to the service. Includes edits to a feature's attributes, geometry, and attachments.
 @param completion block that is executed when the operation finishes. The `error` argument will be populated if a problem is encountered with the entire `applyEdits` operation, for example, due to network disruption. Otherwise, the `result` array will contain `AGSFeatureEditResult` objects representing the result of each individual edit to a feature or an attachment. 
 @return operation which can be canceled.
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)applyEditsWithCompletion:(nullable void(^)(NSArray<AGSFeatureEditResult*> *__nullable result, NSError *__nullable error))completion;

/** Clear all the data in the table, including any temporary edits.
 @since 100
 */
-(void)clearCacheWithKeepLocalEdits:(BOOL)keepLocalEdits;

/** Request data from the service based on the specified query parameters and add it to the table. Especially important for non-geographic data or when `#featureRequestMode` is `AGSFeatureRequestModeManualCache` because the data is not requested automatically based on the map's extent. 
 @param parameters defining which data should be requsted from the service and added to the table
 @param clearCache If true, existing data will cleared before adding the new data
 @param outFields A list of field names specifying which attribute values (columns) should be included in the table.
 @param completion block that is invoked when the operation finishes. The `result` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100
*/
-(id<AGSCancelable>)populateFromServiceWithParameters:(AGSQueryParameters *)parameters
                                           clearCache:(BOOL)clearCache
                                            outFields:(NSArray<NSString*> *)outFields
                                           completion:(nullable void(^)(AGSFeatureQueryResult *__nullable result, NSError *__nullable error))completion;

/**
 Query the dataset to find specific features or records.
 @param parameters representing the query criteria
 @param queryFeatureFields specifying which attribute fields should be included in the result
 @param completion block that is invoked when the operation finishes. The `result` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100.1
 */
-(id<AGSCancelable>)queryFeaturesWithParameters:(AGSQueryParameters *)parameters
                             queryFeatureFields:(AGSQueryFeatureFields)queryFeatureFields
                                     completion:(nullable void(^)(AGSFeatureQueryResult *__nullable result, NSError *__nullable error))completion;

/** Returns features (spatial or non-spatial) that are related to the specified feature based on the provided parameters. The related features must belong to a feature table that is related to this feature table. Also, the related tables must be part of either the map's operational layers collection (`AGSMap#operationalLayers`) through a feature layer if they are spatial, or the map's tables collection (`AGSMap#tables`) directly if they are non-spatial.
 @param feature for which to find related features (spatial and non-spatial)
 @param parameters specifying which related features to query
 @param queryFeatureFields specifying which attribute fields should be included in the result
 @param completion block that is invoked when the operation finishes. The `result` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100.1
 */
-(id<AGSCancelable>)queryRelatedFeaturesForFeature:(AGSArcGISFeature *)feature
                                        parameters:(AGSRelatedQueryParameters *)parameters
                                queryFeatureFields:(AGSQueryFeatureFields)queryFeatureFields
                                        completion:(void(^)(NSArray<AGSRelatedFeatureQueryResult*> *__nullable result, NSError *__nullable error))completion;

/** Undoes any local edits to features and attachments since the last time edits were succesfully applied to the server. You can use `#addedFeaturesWithCompletion:`, `#deletedFeaturesWithCompletion:`, and `#updatedFeaturesWithCompletion:` to find out which features have local edits that will be reverted. If you are holding on to an instance of a feature whose local edit is reverted, you will need to discard that instance and retrieve a new instance by querying the table.
 @param completion block that is invoked when the operation finishes. The `error` parameter is populated if the operation encounters an error.
 @since 100.3
 */
-(id<AGSCancelable>)undoLocalEditsWithCompletion:(nullable void(^)(NSError *__nullable error))completion;


/** Loads attributes and geometry for features if they have not been loaded or refreshes information for loaded features and updates attributes and geometry with the latest values from the server. Note, feature attachments are not loaded or updated. Any feature requested, but not returned by the server, will have its Object ID cleared (set to an invalid negative value) to indicate it is no longer associated with the service feature table. After calling this method, any local edits (i.e not applied to the server) to the provided features will be lost.
 @param features that need to be loaded or refreshed. When the operation completes, the attributes and geometry of these features is updated.
 @param completion block that is invoked when the operation finishes. The `error` parameter is populated if the operation encounters an error.
 @since 100.3
 */
-(id<AGSCancelable>)loadOrRefreshFeatures:(NSArray<AGSArcGISFeature*> *)features completion:(nullable void(^)(NSError *__nullable error))completion;

NS_ASSUME_NONNULL_END

@end
