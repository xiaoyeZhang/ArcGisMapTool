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

@class AGSGeoPackage;

#import "AGSFeatureTable.h"

/** @file AGSGeoPackageFeatureTable.h */ //Required for Globals API doc

/** @brief A dataset in a GeoPackage containing geographic features or non-spatial records
 
 Instances of this class respresent a dataset in a GeoPackage that could include either geographic features or non-spatial records. You can query the dataset using attribute or spatial criteria, and if permitted, also edit the data. If the dataset contains geographic features you can display them on a map using `AGSFeatureLayer`.
 
 It supports core GeoPackage geometry types and represents them as Point, Multipoint, Polyline, or Polygon. The GeoPackage specification supports a geometry collection type (storing a variety of core geometry types in a single table). For these tables, ArcGIS Runtime renders the first geometry type found in the collection. All features can be queried in the table regardless of the geometry type displayed.
 
 @since 100.2
 */
@interface AGSGeoPackageFeatureTable : AGSFeatureTable

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The description for the dataset.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *tableDescription;

/** The GeoPackage to which this dataset belongs.
 @since 100.2
 */
@property (nullable, nonatomic, weak, readonly) AGSGeoPackage *geoPackage;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
