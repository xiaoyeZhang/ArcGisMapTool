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

#import "AGSObject.h"

/** @file AGSSublayerSource.h */ //Required for Globals API doc

/** @brief Base class for sources of a map image sublayer.
 
 Base class for sources of a map image sublayer. Following sources are supported -
 
 * Map Sublayer: a sublayer in an ArcGIS map service. See `AGSMapSublayerSource`
 * Dynamic table: data from a table data source. See `AGSTableSublayerSource`
 * Dynamic query table: data from a queryTable data source. See `AGSTableQuerySublayerSource`
 * Dynamic raster: data from a raster data source. See `AGSRasterSublayerSource`
 * Dynamic join table: data from a joinTable data source. See `AGSTableJoinSublayerSource`
 
 @since 100.1
 */
@interface AGSSublayerSource : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

