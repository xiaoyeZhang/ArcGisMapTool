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

/** @file AGSArcGISMapServiceCapabilities.h */ //Required for Globals API doc

/** @brief Information about an ArcGIS Server map service capabilities.
 
 Instances of this class represent information about an ArcGIS Map service capabilities.
 
 @since 100
 */
@interface AGSArcGISMapServiceCapabilities : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether the service supports data operations.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsData;

/** Indicates whether the service supports map operations.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsMap;

/** Indicates whether the service supports query operations.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsQuery;

/** Indicates whether the service supports tile map.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL supportsTilemap;

/** Indicates whether the service supports tiles only.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL supportsTilesOnly;

NS_ASSUME_NONNULL_END
@end
