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

#import "AGSFeatureTable.h"
#import "AGSFeatureSet.h"

@class AGSField;
@class AGSSpatialReference;
@class AGSArcGISFeatureLayerInfo;
@class AGSRenderer;
@class AGSSymbol;

/** @file AGSFeatureCollectionTable.h */ //Required for Globals API doc

/** @brief An individual table that contains features belonging to a feature collection
 
 Instances of this class represent an individual table that contains features belonging to a feature collection. The tables help to organize features of the feature collection where features that share the same attribute schema (fields), geometry type, and spatial reference belong to the same table.
 
 @since 100
 @see `AGSFeatureCollection`
 */
@interface AGSFeatureCollectionTable : AGSFeatureTable <AGSFeatureSet>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize an empty table with the provided parameters
 @param fields The attributes of features that will be held in this table.
 @param geometryType The type of feature geometry that will be held in this table.
 @param spatialReference The spatial reference of the features that will be held in this table.
 @since 100
 */
-(instancetype)initWithFields:(NSArray<AGSField*>*)fields
                 geometryType:(AGSGeometryType)geometryType
             spatialReference:(nullable AGSSpatialReference*)spatialReference;

/** Initialize the table populated with the provided geoelements. The geometry type and spatial reference will be inferred from the geo-elements passed in. Be aware that this constructor may take some time to complete depending on how many geo-elements are passed in.
 @param geoElements that will be copied into the table as features. All geo-elements must support the fields specified next.
 @param fields The attributes of features that will be held in this table.
 @since 100
 */
-(instancetype)initWithGeoElements:(NSArray<id<AGSGeoElement>>*)geoElements
                            fields:(nullable NSArray<AGSField*>*)fields;

/** Initialize the table populated with the provided feature set. The geometry type and spatial reference will be inferred from the features in the feature set passed in. Be aware that this constructor may take some time to complete depending on how many features are in the feature set.
 @param featureSet containing the features that will be copied into this table.
 @since 100
 */
-(instancetype)initWithFeatureSet:(id<AGSFeatureSet>)featureSet;

/** Initialize an empty table with the provided parameters
 @param fields The attributes of features that will be held in this table.
 @param geometryType The type of feature geometry that will be held in this table.
 @param spatialReference The spatial reference of the features that will be held in this table.
 @param hasZ Bool specifying whether the table supports geometries with Z values.
 @param hasM Bool specifying whether the table supports geometries with M values.
 @since 100.4
 */
-(instancetype)initWithFields:(NSArray<AGSField*>*)fields
                 geometryType:(AGSGeometryType)geometryType
             spatialReference:(nullable AGSSpatialReference*)spatialReference
                         hasZ:(BOOL)hasZ
                         hasM:(BOOL)hasM;
    
/** Initialize the table with the provided parameters
 @param fields The attributes of features that will be held in this table.
 @param geometryType The type of feature geometry that will be held in this table.
 @param spatialReference The spatial reference of the features that will be held in this table.
 @since 100
 */
+(instancetype)featureCollectionTableWithFields:(NSArray<AGSField*>*)fields
                                   geometryType:(AGSGeometryType)geometryType
                               spatialReference:(nullable AGSSpatialReference*)spatialReference;

/** Initialize the table populated with the provided geoelements. The geometry type and spatial reference will be inferred from the geo-elements passed in. Be aware that this constructor may take some time to complete depending on how many geo-elements are passed in.
 @param geoElements that will be copied into the table as features. All geo-elements must support the fields specified next.
 @param fields The attributes of features that will be held in this table.
 @since 100
 */
+(instancetype)featureCollectionTableWithGeoElements:(NSArray<id<AGSGeoElement>>*)geoElements
                                              fields:(nullable NSArray<AGSField*>*)fields;

/** Initialize the table populated with the provided feature set. The geometry type and spatial reference will be inferred from the features in the feature set passed in. Be aware that this constructor may take some time to complete depending on how many features are in the feature set.
 @param featureSet containing the features that will be copied into this table.
 @since 100
 */
+(instancetype)featureCollectionTableWithFeatureSet:(id<AGSFeatureSet>)featureSet;

/** Initialize an empty table with the provided parameters
 @param fields The attributes of features that will be held in this table.
 @param geometryType The type of feature geometry that will be held in this table.
 @param spatialReference The spatial reference of the features that will be held in this table.
 @param hasZ Bool specifying whether the table supports geometries with Z values.
 @param hasM Bool specifying whether the table supports geometries with M values.
 @since 100.4
 */
+(instancetype)featureCollectionTableWithFields:(NSArray<AGSField*>*)fields
                 geometryType:(AGSGeometryType)geometryType
             spatialReference:(nullable AGSSpatialReference*)spatialReference
                         hasZ:(BOOL)hasZ
                         hasM:(BOOL)hasM;
    
#pragma mark -
#pragma mark properties

@property (nullable, nonatomic, strong, readonly) AGSArcGISFeatureLayerInfo *layerInfo;
@property (nullable, nonatomic, strong, readwrite) AGSRenderer *renderer;
@property (nonatomic, copy, readwrite) NSString *title;

#pragma mark -
#pragma mark methods

-(nullable AGSSymbol*)symbolOverrideForFeature:(AGSFeature*)feature;
-(void)setSymbolOverride:(nullable AGSSymbol*)symbol forFeature:(AGSFeature*)feature;

NS_ASSUME_NONNULL_END

@end
