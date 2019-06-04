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

#import "AGSLoadableBase.h"

@class AGSLocalItem;

/** @file AGSItemResourceCache.h */ //Required for Globals API doc

/** @brief  Information on resources associated with an item.
 
 Instances of this class provide information on resources associated with an item. For instance, an item representing a vector tile layer has style resources such as fonts, sprites, etc.
 
 @since 100.2
 */
@interface AGSItemResourceCache : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize this object with a path to the resource cache on disk
 @param fileURL to a directory representing the resource cache on disk
 @return Initialized item resource cache
 @since 100.2
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL;

/** Initialize this object with a path to the resource cache on disk
 @param fileURL to a directory representing the resource cache on disk
 @return Initialized item resource cache
 @since 100.2
 */
+(instancetype)itemResourceCacheWithFileURL:(NSURL*)fileURL;

#pragma mark -
#pragma mark properties

/** Path to a directory representing the resource cache on disk
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** The local item containing metadata about this resource cache.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSLocalItem *item;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
