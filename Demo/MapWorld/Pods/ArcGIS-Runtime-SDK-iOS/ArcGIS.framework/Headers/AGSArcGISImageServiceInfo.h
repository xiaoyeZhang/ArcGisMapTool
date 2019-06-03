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

@class AGSField;
@class AGSEnvelope;
@class AGSRenderingRuleInfo;
@class AGSSpatialReference;
@class AGSLayerTimeInfo;

/** @brief Metadata of an ArcGIS Image Service
 
 An instance of this class represents metadata for an ArcGIS Image Service
 
 @see `AGSImageServiceRaster`
 @since 100.1
 */
@interface AGSArcGISImageServiceInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** URL of the ArcGIS Image Service
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSURL *URL;

/** Attribution text for the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *attribution;

/** Version of the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *currentVersion;

/** The attribute fields (columns) available in the service's data.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSField*> *fields;

/** Full geographic extent of the service
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *fullExtent;

/** The maximum scale at which contents of the service is visible. If the map is zoomed in beyond this scale, the contents will not be visible.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double maxScale;

/** The minimum scale at which contents of the service is visible. If the map is zoomed out beyond this scale, the contents will not be visible.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double minScale;

/** Name of the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Type of data, such as signed integer, unsigned integer, or floating point, contained in each pixel of the raster provided by the service.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSPixelType pixelType;

/** Rendering rules available in the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSRenderingRuleInfo*> *renderingRuleInfos;

/** Spatial reference of the service's geographic data
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

@property (nullable, nonatomic, strong, readonly) AGSLayerTimeInfo *timeInfo;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
