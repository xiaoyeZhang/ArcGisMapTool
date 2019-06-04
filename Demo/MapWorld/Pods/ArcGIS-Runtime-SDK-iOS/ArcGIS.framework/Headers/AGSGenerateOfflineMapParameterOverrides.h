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

@class AGSOfflineMapParametersKey;
@class AGSExportTileCacheParameters;
@class AGSExportVectorTilesParameters;
@class AGSGenerateGeodatabaseParameters;

/** @file AGSGenerateOfflineMapParameterOverrides.h */ //Required for Globals API doc

/** @brief Gives access to the individual parameters objects that will generate the various geodatabase, vector tile and tile cache packages that make up the data of an offline map.
 
 This object allows the user more fine-grained control over the generation of an offline map than the options presented in the standard `AGSGenerateOfflineMapParameters`. For example, the parameters overrides allow the user to adjust specific layers so that they: use a different spatial extent or scale range; use custom attribute or geometry settings; are omitted from the download. An instance of this object can be created from the overall map settings in `AGSGenerateOfflineMapParameters` by calling `AGSOfflineMapTask#generateOfflineMapParameterOverridesWithParameters:completion:`. This object gives access to the individual parameter objects via three dictionaries containing generate geodatabase parameters, export tile cache parameters and export vector tile parameters. These can be accessed using `AGSGenerateOfflineMapParameterOverrides#generateGeodatabaseParameters`, `AGSGenerateOfflineMapParameterOverrides#exportTileCacheParameters` and `AGSGenerateOfflineMapParameterOverrides#exportVectorTilesParameters` respectively. The dictionaries contain the various parameters objects mapped against an `AGSOfflineMapParametersKey` instance. An `AGSOfflineMapParametersKey` instance represents the service that a particular parameters object is intended for. Given a layer or table, a key to find its matching parameters object can be constructed with `AGSOfflineMapParametersKey#initWithLayer:` or `AGSOfflineMapParametersKey#initWithServiceFeatureTable:` respectively. The returned key's `AGSOfflineMapParametersKey#type` property will indicate which of the three dictionaries contains the desired parameters object and the key can be used to extract it. Note that a given parameters key/value pair may be shared by multiple layers in the map: for example a single `AGSGenerateGeodatabaseParameters` instance could represent the online settings for multiple feature layers which all access the same underlying feature service. All entries in the dictionaries should correspond to layers and table instances in the online `AGSMap`. If a dictionary entry is removed the corresponding layers or tables will be removed from the offline map without raising an error.
 
 @since 100.4
 */
@interface AGSGenerateOfflineMapParameterOverrides : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The dictionary of `AGSExportTileCacheParameters`, which can be changed or overridden for taking a map offline.
 All entries in the dictionary should correspond to `AGSArcGISTiledLayer` instances in the online `AGSMap`. If a dictionary entry is removed the corresponding layers will be removed from the offline map without raising an error.
 @since 100.4
 */
@property (nonatomic, copy, readwrite) NSDictionary<AGSOfflineMapParametersKey *, AGSExportTileCacheParameters *> *exportTileCacheParameters;

/** The dictionary of `AGSExportVectorTilesParameters`, which can be changed or overridden for taking a map offline.
 All entries in the dictionary should correspond to `AGSArcGISVectorTiledLayer` instances in the online `AGSMap`. If a dictionary entry is removed the corresponding layers will be removed from the offline map without raising an error.
 @since 100.4
 */
@property (nonatomic, copy, readwrite) NSDictionary<AGSOfflineMapParametersKey *, AGSExportVectorTilesParameters *> *exportVectorTilesParameters;

/** The dictionary of `AGSGenerateGeodatabaseParameters`, which can be changed or overridden for taking a map offline.
 All entries in the dictionary should correspond to `AGSFeatureLayer` and `AGSServiceFeatureTable` instances in the online `AGSMap`. If a dictionary entry is removed the corresponding layers or tables will be removed from the offline map without raising an error.
 @since 100.4
 */
@property (nonatomic, copy, readwrite) NSDictionary<AGSOfflineMapParametersKey *, AGSGenerateGeodatabaseParameters *> *generateGeodatabaseParameters;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
