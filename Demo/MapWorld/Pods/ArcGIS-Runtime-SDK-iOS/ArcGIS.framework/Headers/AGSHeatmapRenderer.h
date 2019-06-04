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

#import "AGSRenderer.h"

/** @file AGSHeatmapRenderer.h */ //Required for Globals API doc

/** @brief A renderer to display heatmaps

 Instances of this class represent renderers that can display heat maps which represent the geographic density of features on a map. The relative density is displayed using a color scheme that smoothly varyies a set of colors ranging from cool (low density of points) to hot (high density of points).  Heat map symbology is a dynamic raster surface that changes as you zoom in and out. For example, if you map a city's crime hot spots, zooming out shows a bigger picture of criminal activity across the city, while zooming in shows more detailed density patterns in particular neighborhoods without having to change any symbology properties.
 
 @since 100.1
 */
@interface AGSHeatmapRenderer : AGSRenderer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

