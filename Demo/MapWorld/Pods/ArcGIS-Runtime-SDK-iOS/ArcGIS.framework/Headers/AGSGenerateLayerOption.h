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

/** @file AGSGenerateLayerOption.h */ //Required for Globals API doc

/** @brief Options defining what data to include for a layer in a geodatabase
 
 Instances of this class represent options that define what data is included in a sync-enabled geodatabase for a particular layer or table.
 
 @since 100
 @see `AGSGenerateGeodatabaseParameters#layerOptions`
 */
@interface AGSGenerateLayerOption : AGSObject <NSCopying>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the layer option with provided parameters
 @param layerID The ID of the layer for which these options are defined. Same as `AGSArcGISFeatureLayerInfo#serverLayerID`
 @return A new layer option object
 @since 100
 */
-(instancetype)initWithLayerID:(NSInteger)layerID;

/** Initialize the layer option with provided parameters
 @param layerID The ID of the layer for which these options are defined. Same as `AGSArcGISFeatureLayerInfo#serverLayerID`
 @param includeRelated Specifies whether to include any data from this layer that is related to data in other layers in the geodatabase. This parameters is only valid if the layer participates in any relationships, and if those related layers are also included in the geodatabase.
 @return A new layer option object
 @since 100
 */
-(instancetype)initWithLayerID:(NSInteger)layerID includeRelated:(BOOL)includeRelated;

/** Initialize the layer option with provided parameters
 @param layerID The ID of the layer for which these options are defined. Same as `AGSArcGISFeatureLayerInfo#serverLayerID`.
 @param whereClause An attribute query to specify which features should be included in the geodatabase.
 @return A new layer option object
 @since 100
 */
-(instancetype)initWithLayerID:(NSInteger)layerID whereClause:(NSString *)whereClause;

+(instancetype)generateLayerOption;

/** Initialize the layer option with provided parameters
 @param layerID The ID of the layer for which these options are defined. Same as `AGSArcGISFeatureLayerInfo#serverLayerID`
 @return A new layer option object
 @since 100
 */
+(instancetype)generateLayerOptionWithLayerID:(NSInteger)layerID;

/** Initialize the layer option with provided parameters
 @param layerID The ID of the layer for which these options are defined. Same as `AGSArcGISFeatureLayerInfo#serverLayerID`
 @param includeRelated Specifies whether to include any data from this layer that is related to data in other layers in the geodatabase. This parameters is only valid if the layer participates in any relationships, and if those related layers are also included in the geodatabase.
 @return A new layer option object
 @since 100
 */
+(instancetype)generateLayerOptionWithLayerID:(NSInteger)layerID includeRelated:(BOOL)includeRelated;

/** Initialize the layer option with provided parameters
 @param layerID The ID of the layer for which these options are defined. Same as `AGSArcGISFeatureLayerInfo#serverLayerID`.
 @param whereClause An attribute query to specify which features should be included in the geodatabase.
 @return A new layer option object
 @since 100
 */
+(instancetype)generateLayerOptionWithLayerID:(NSInteger)layerID whereClause:(NSString *)whereClause;

#pragma mark -
#pragma mark properties

/** Specifies whether to include any data from this layer that is related to data in other layers in the geodatabase. This parameters is only valid if the layer participates in any relationships, and if those related layers are also included in the geodatabase.
 @note Only applicable if `#queryOption` is set to `AGSGenerateLayerQueryOptionNone`
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL includeRelated;

/** The ID of the layer for which these options are defined. Same as `AGSArcGISFeatureLayerInfo#serverLayerID`
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger layerID;

/** Specifies how features should be included in the sync-enabled geodatabase.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSGenerateLayerQueryOption queryOption;

/** Determines whether to filter features based on geometry to include in the geodatabase. Only features that intersect `AGSGenerateGeodatabaseParameters#extent` are considered for inclusion. Default value is `true`
 @note Only applicable if `#queryOption` is set to `AGSGenerateLayerQueryOptionUseFilter`
 @see `#whereClause` for additional filtering option
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL useGeometry;

/** An attribute query to filter which features should be included in the geodatabase. Can be nil, in which case, features are not filtered based on the where clause.
 @note Only applicable if `#queryOption` is set to `AGSGenerateLayerQueryOptionUseFilter`
 @see `#useGeometry` for additional filtering option
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *whereClause;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
