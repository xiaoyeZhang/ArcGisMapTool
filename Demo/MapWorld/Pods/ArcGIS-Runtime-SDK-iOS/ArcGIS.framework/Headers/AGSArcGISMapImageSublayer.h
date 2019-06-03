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

#import "AGSArcGISSublayer.h"

@class AGSSublayerSource;
@class AGSLabelDefinition;
@class AGSServiceFeatureTable;

/** @file AGSArcGISMapImageSublayer.h */ //Required for Globals API doc

/** @brief Information about an individual layer or table in a dynamic ArcGIS Map Service.
 
 Instances of this class represent information about an individual layer or table in a dynamic ArcGIS Map Service.
 
 @since 100
 */
@interface AGSArcGISMapImageSublayer : AGSArcGISSublayer


NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this sublayer with an ID
 @param ID of the sublayer in the ArcGIS Map Service
 @return Initialized map image sublayer
 @since 100
 */
-(instancetype)initWithID:(NSInteger)ID;

/** Initialize this sublayer with an ID
 @param ID of the sublayer in the ArcGIS Map Service
 @return Initialized map image sublayer
 @since 100
 */
+(instancetype)ArcGISMapImageSublayerWithID:(NSInteger)ID;

/** Initialize this sublayer with an ID and a source
 @note  Only map services that support dynamic layers (`AGSArcGISMapServiceInfo#supportsDynamicLayers`) will be able to handle sublayers with sources
 @param ID of the sublayer
 @param source defining the data for the sublayer
 @return Initialized map image sublayer
 @since 100.1
 */
-(instancetype)initWithID:(NSInteger)ID source:(AGSSublayerSource *)source;

/** Initialize this sublayer with an ID and a source
 @note  Only map services that support dynamic layers (`AGSArcGISMapServiceInfo#supportsDynamicLayers`) will be able to handle sublayers with sources
 @param ID of the sublayer
 @param source defining the data for the sublayer
 @return Initialized map image sublayer
 @since 100.1
 */
+(instancetype)ArcGISMapImageSublayerWithID:(NSInteger)ID source:(AGSSublayerSource *)source;

#pragma mark -
#pragma mark properties

/** The source of the data for this sublayer. 
 Only applicable if this sublayer was created with a source based on dynamic layer capabilities of the service.
 @see `#initWithID:source:`
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSSublayerSource *source;

/** The default visibility of this layer.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isVisibleByDefault) BOOL visibleByDefault;

/** The definition expression in the syntax of a SQL where clause by which to limit which features are displayed for the sublayer.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *definitionExpression;

/** The maximum scale at which this sublayer is visible. If the map is zoomed in beyond this scale, the sublayer will not be visible.
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxScale;

/** The minimum scale at which this sublayer is visible. If the map is zoomed out beyond this scale, the sublayer will not be visible.
 @since 100
 */
@property (nonatomic, assign, readwrite) double minScale;

/** The sublayer's name.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *name;

/** The opacity of this sublayer as a value between 0 (fully transparent) and 1 (fully opaque).
 @since 100.1
 */
@property (nonatomic, assign, readwrite) float opacity;

/** The renderer specifying how the features should be symbolized
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSRenderer *renderer;

/** Specifies whether the symbols for this sublayer are tied to a scale and should resized as the scale varies.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL scaleSymbols;

/** Specifies whether labels should be displayed for this sublayer.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL labelsEnabled;

/** Defines how labels should be displayed.
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSLabelDefinition*> *labelDefinitions;

/** The sublayer's backing table that is used to perform queries or identify features in the sublayer. This property remains nil until the sublayer has been loaded and only applies to sublayers of type "Feature layer" or "Table". See `AGSArcGISMapServiceSublayerInfo#sublayerType` to find out the type of this sublayer.
 @since 100.3
 */
@property (nullable, nonatomic, strong, readonly) AGSServiceFeatureTable *table;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
