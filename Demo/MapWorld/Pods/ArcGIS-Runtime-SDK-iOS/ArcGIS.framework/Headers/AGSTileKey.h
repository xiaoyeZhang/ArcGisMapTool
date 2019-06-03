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

/** @file AGSTileKey.h */ //Required for Globals API doc

/** @brief A tile key
 
 Instances of this class represent a "key" (as in a key-value pair) that uniquely identifies a tile in a tiling scheme.
 
 @since 100
 */

@interface AGSTileKey : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a tile key to represent a tile
 @param level in the tiling scheme that the tile belongs to
 @param column in the tiling scheme that the tile belongs to
 @param row in the tiling scheme that the tile belongs to
 @return Initialized tile key
@since 100
 */
-(instancetype)initWithLevel:(NSInteger)level column:(NSInteger)column row:(NSInteger)row;

/** Initialize a tile key to represent a tile
 @param level in the tiling scheme that the tile belongs to
 @param column in the tiling scheme that the tile belongs to
 @param row in the tiling scheme that the tile belongs to
 @return Initialized tile key
@since 100
 */
+(instancetype)tileKeyWithLevel:(NSInteger)level column:(NSInteger)column row:(NSInteger)row;

#pragma mark -
#pragma mark properties

/** The column of tiling scheme.
@since 100
 */
@property (nonatomic, assign, readonly) NSInteger column;

/** The scale level of tiling scheme
@since 100
 */
@property (nonatomic, assign, readonly) NSInteger level;

/** The row of tiling scheme
@since 100
 */
@property (nonatomic, assign, readonly) NSInteger row;

#pragma mark -
#pragma mark methods

/** Compares two tile keys for equality
 @param other tile key to compare this one to
 @return whether the two tile keys are equal
 @since 100
 */
-(BOOL)isEqualToTileKey:(AGSTileKey*)other;

NS_ASSUME_NONNULL_END
@end
