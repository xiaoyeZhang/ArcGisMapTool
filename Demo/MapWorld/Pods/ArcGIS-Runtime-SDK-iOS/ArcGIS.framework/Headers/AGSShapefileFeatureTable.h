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

#import "AGSFeatureTable.h"

@class AGSShapefileInfo;

/** @file AGSShapefileFeatureTable.h */ //Required for Globals API doc

/** @brief A shapefile dataset containing geographic features or non-spatial records
 
 Instances of this class respresent a Shapefile dataset that could include either geographic features. You can query the dataset using attribute or spatial criteria, and if permitted, also edit the data. You can display the geographic features on a map using `AGSFeatureLayer`.
 
 A shapefile dataset consists of at least three files (.shp, .shx, .dbf), and may include many others. Each of the component files of a shapefile must be smaller than 2 GB. If the minimum required files are not present (or larger than 2 GB), the table will fail to load. If the file permissions are read-only, features cannot be edited. On-the-fly projection of a shapefile is only supported if an associated .prj file is present. Otherwise, the features are assumed to have the same spatial reference as the map. A default renderer is used to render a shapefile feature table in a feature layer. In most cases, the default should be replaced with a custom renderer.
 
 @license{Standard}
 @ingroup licensing
 @since 100.2
 */
@interface AGSShapefileFeatureTable : AGSFeatureTable

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Instantiates a featuretable based on the given path to a shapefile dataset on disk.
 
 A shapefile dataset consists of at least three files (.shp, .shx, .dbf), and may include many others. Each of the component files of a shapefile must be smaller than 2 GB. When creating a shapefile feature table, the path must point to the .shp file and the associated .shx and .dbf files must be present at the same location.
 
 @param fileURL to existing shapefile (including .shp file extension)
 @since 100.2
 @return A new shapefile featuretable
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL;

/** Instantiates a featuretable based on the given path to a shapefile dataset on disk.
 
 A shapefile dataset consists of at least three files (.shp, .shx, .dbf), and may include many others. Each of the component files of a shapefile must be smaller than 2 GB. When creating a shapefile feature table, the path must point to the .shp file and the associated .shx and .dbf files must be present at the same location.

 @param fileURL to existing shapefile (including .shp file extension)
 @since 100.2
 @return A new shapefile featuretable
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)shapefileFeatureTableWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of an existing shapefile, excluding the ".shp" extension,
 within the application bundle or shared documents directory.
 
 A shapefile dataset consists of at least three files (.shp, .shx, .dbf), and may include many others. Each of the component files of a shapefile must be smaller than 2 GB. The .shp file and the associated .shx and .dbf files must be present at the same location.
 
 @param name of the shapefile (excluding the .shp extension)
 @return A new shapefile featuretable
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithName:(NSString *)name;

/** Initialize this object with the name of an existing shapefile, excluding the ".shp" extension,
 within the application bundle or shared documents directory.
 
 A shapefile dataset consists of at least three files (.shp, .shx, .dbf), and may include many others. Each of the component files of a shapefile must be smaller than 2 GB. The .shp file and the associated .shx and .dbf files must be present at the same location.
 
 @param name of the shapefile (excluding the .shp extension)
 @return A new shapefile featuretable
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)shapefileFeatureTableWithName:(NSString *)name;

#pragma mark -
#pragma mark properties

/** Metadata of the shapefile dataset. Only available if the shapefile dataset contains a .xml file.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSShapefileInfo *shapefileInfo;

/** Path to the shapefile dataset on disk.
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** Indicates whether or not the shapefile uses spatial indexes.
 
 ArcGIS for Desktop can be used to create spatial indexes for shapefiles, stored in .sbn and .sbx files. Having a current spatial index ensures that a high level of performance is maintained when drawing and working with the shapefile's features and that the shapefile's extent is accurate.
 @since 100.2
 */
@property (nonatomic, assign, readonly, getter=isSpatialIndexEnabled) BOOL spatialIndexEnabled;

#pragma mark -
#pragma mark methods

/** Close connection to the shapefile on disk.
 All use of this instance should cease before closing it. For example: remove feature layers from maps, and release feature tables. Any attempt to access this instance after it is closed will fail, resulting in an error. After closing the connection, the shapefile file can be deleted.
 @since 100.3
 */
-(void)close;

NS_ASSUME_NONNULL_END

@end

