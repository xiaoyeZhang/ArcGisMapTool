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

/** @file AGSEstimateTileCacheSizeResult.h */ //Required for Globals API doc

/** @brief Size estimate of a tile cache requested by `AGSExportTileCacheTask`
 
 This class holds the size estimate about a tile cache requested by the `AGSExportTileCacheTask#estimateTileCacheSizeJobWithParameters:` operation
 
 
 @since 100
 */
@interface AGSEstimateTileCacheSizeResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The size of the tile cache (tile pacakge, .TPK file) in bytes
 @since 100
 */
@property (nonatomic, assign, readonly) unsigned long long fileSize;

/** The number of tiles in the tile cache
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger tileCount;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
