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

#import "AGSGrid.h"

/** @file AGSLatitudeLongitudeGrid.h */ //Required for Globals API doc

/** @brief A grid consisting of east-west lines of latitude and north-south lines of longitude.
 
 Instances of this class represent graticules – lines showing parallels of latitude and meridians of longitude . The grid is supported in spatial references which are continuously pannable or some polar spatial references. (You can check `AGSSpatialReference#isPannable` on the spatial reference)
 
  Examples of continuously pannable spatial references include WGS84 (WKID 4326) and Web Mercator Auxilliary Sphere
  (WKID 102113, 102100, or 3857). The following polar spatial references are also supported:
  
  @li North pole Azimuthal Equidistant (WKID 102016)
  @li North pole gnomic (WKID 102034)
  @li North pole lambert equal area (WKID 102017)
  @li North pole orthographic (WKID 102035)
  @li North pole stereographic (WKID 102018)
  @li NSIDE EASE North (WKID 3408)
  @li NSIDC Sea Ice polar stereographic north (WKID 3411)
  @li WGS 1984 NSIDC Sea Ice Polar Stereographic North (WKID 3413)
  @li UPS North (WKID 32661)
  @li South pole Azimuthal Equidistant (WKID 102019)
  @li South pole gnomic (WKID 102036)
  @li South pole lambert equal area (WKID 102020)
  @li South pole orthographic (WKID 102037)
  @li South pole stereographic (WKID 102021)
  @li NSIDE EASE South (WKID 3409)
  @li NSIDC Sea Ice polar stereographic South (WKID 3412)
  @li UPS South (WKID 32761)
  @li WGS1984 Antarctic polar stereographic (WKID 3031)
 
 @since 100
 */
@interface AGSLatitudeLongitudeGrid : AGSGrid

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a new latitude-longitude grid
 @since 100
 */
+(instancetype)latitudeLongitudeGrid;

#pragma mark -
#pragma mark properties

/** Specifies the format to use for the grid's text labels
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSLatitudeLongitudeGridLabelFormat labelFormat;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
