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

#import "AGSFeatureTable.h"
#import "AGSRemoteResource.h"

@class AGSWFSLayerInfo;
@class AGSSpatialReference;
@class AGSQueryParameters;
@class AGSFeatureQueryResult;

/** @file AGSWFSFeatureTable.h */ //Required for Globals API doc

/** @brief Represents a table in an OGC Web Feature Service.
 @remark Features from WFS feature tables can be visualized using feature layers. WFS feature table does not support editing.
 At 100.5, WFS feature table only supports manually requesting features and does not automatically request features when added to 
 a feature layer. Use @c populateFromServiceWithRequestXML or @c populateFromServiceWithParameters to populate the table.
 Use @c AGSWFSService to connect to a WFS service and discover available layers that can be opened using a WFS feature table 
 via @c initWithLayerInfo.
 @since 100.5
 */
@interface AGSWFSFeatureTable : AGSFeatureTable <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Creates a new WFS feature table.
 @param layerInfo A @c AGSWFSLayerInfo.
 @since 100.5
 */
-(instancetype)initWithLayerInfo:(AGSWFSLayerInfo*)layerInfo;

/** Creates a new WFS feature table.
 @param layerInfo A @c AGSWFSLayerInfo.
 @since 100.5
 */
+(instancetype)WFSFeatureTableWithLayerInfo:(AGSWFSLayerInfo*)layerInfo;

/** Creates a new WFS feature table.
 @param URL The URL of the WFS service to connect to.
 @param tableName The name of the WFS feature table object.
 @since 100.5
 */
-(instancetype)initWithURL:(NSURL*)URL tableName:(NSString*)tableName;

/** Creates a new WFS feature table.
 @param URL The URL of the WFS service to connect to.
 @param tableName The name of the WFS feature table object.
 @since 100.5
 */
+(instancetype)WFSFeatureTableWithURL:(NSURL*)URL tableName:(NSString*)tableName;

#pragma mark -
#pragma mark properties

/** The axis order, which defines how coordinates are interpreted (X,Y or Y,X).
 @remark Some WFS services return coordinates in (X,Y) order, while others use (Y,X). Setting this property to @c Swap will result in all
 coordinates in geometries being swapped from what was sent by the server. Setting to @c NoSwap will cause coordinates to be interpreted as-is. 
 Defaults to @c Auto. In this mode, Runtime will make its best guess using heuristics that are optimized for good results with most popular WFS services.
 Axis order may be changed on an already-loaded feature table, but the change will only affect future calls to @c populateFromService. Features that are
 already in the table will not be modified/swapped.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) AGSOGCAxisOrder axisOrder;

/** The mode defining when features are requested from the service.
 @remark At v100.5, WFS feature table only supports @c ManualCache but defaults to @c OnInteractionCache. Set the feature request mode to @c Manual
 before attempting to populate the table with @c populateFromServiceWithParameters or @c populateFromServiceWithRequestXML.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) AGSFeatureRequestMode featureRequestMode;

/** The filter axis order, which determines how coordinates are ordered when sent to the server as part of spatial queries (those that specify a Geometry).
 @remark Some WFS services expect coordinates to be sent in (X,Y) order, while others use (Y,X). Use @c Swap to send
 coordinates in (Y,X) order and @c NoSwap to use (X,Y) order. Defaults to @c Auto.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) AGSOGCAxisOrder filterAxisOrder;

/** Metadata describing the WFS layer.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) AGSWFSLayerInfo *layerInfo;

/** The preferred spatial reference for the WFS feature table.
 @remark If the preferred spatial reference isn't available from the service, the table will fail to load.
 Preferred spatial reference must be set before loading the table.
 Set preferred spatial reference to match the map or scene's spatial reference to avoid automatic reprojection of features.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *preferredSpatialReference;

#pragma mark -
#pragma mark methods

/** Manually populate the table using a query.
 Specifying nil or an empty @c NSArray<T> for \p outFields will result in the default set of outFields being used.
 @remark Use the default (empty) @c AGSQueryParameters to get all features from the service. WFS is only compatible
 with a subset of possible queries defined by @c AGSQueryParameters. Where clause only works when the table is backed
 by a service powered by GeoServer. Spatial queries (those that specify a geometry) must use the @c Intersects spatial relationship.
 @param parameters defining which data should be requested from the service and added to the table
 @param clearCache If true, existing data will be cleared before adding the new data
 @param outFields A list of field names specifying which attribute values (columns) should be included in the table.
 @param completion block that is invoked when the operation finishes. The `result` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100.5
 */
-(id<AGSCancelable>)populateFromServiceWithParameters:(AGSQueryParameters *)parameters
                                           clearCache:(BOOL)clearCache
                                            outFields:(nullable NSArray<NSString*> *)outFields
                                           completion:(nullable void(^)(AGSFeatureQueryResult *__nullable result, NSError *__nullable error))completion;

/**
 Manually populate the table using an XML query.
 
 @param requestXML A string containing the XML of the complete GetFeature
    request including but not limited to filters, joins, and aliases.
 @param clearCache If true, existing data will be cleared before adding the new
    data.
 @param completion A block that is invoked when the operation finishes. The
    @c result parameter is populated if the operation completed successfully,
    otherwise the @c error parameter is populated.
 @remark The schema of the query result must match or be a subset of the schema of the feature table.
 Queries must be made against the same feature type represented by the wfs feature table.
 @return The operation which can be canceled.
 @since 100.5
 */
-(id<AGSCancelable>)populateFromServiceWithRequestXML:(NSString *)requestXML
                                           clearCache:(BOOL)clearCache
                                           completion:(nullable void(^)(AGSFeatureQueryResult *__nullable result, NSError *__nullable error))completion;


NS_ASSUME_NONNULL_END

@end

