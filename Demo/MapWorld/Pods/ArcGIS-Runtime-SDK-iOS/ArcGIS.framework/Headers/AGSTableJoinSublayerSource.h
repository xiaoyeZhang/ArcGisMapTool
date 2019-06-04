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

#import "AGSSublayerSource.h"

/** @file AGSTableJoinSublayerSource.h */ //Required for Globals API doc

/** @brief A source for `AGSArcGISMapImageSublayer` based on a join of other sources
 
 Instances of this class represent a source for `AGSArcGISMapImageSublayer` based on a join of other sources.
 
 Nested joins are supported. To use nested joins, set either `#leftSublayerSource` or `#rightSublayerSource` to be a `AGSTableJoinSublayerSource`.
 
 The type of data represented by this source is determined by the `leftSublayerSource`. If the `leftSublayerSource` is a non-spatial table, this source also represents a non-spatial table. If the `leftSublayerSource` is a layer, this source represents a layer.
 For performance reasons, it is ideal to have `leftSublayerSource` and `rightSublayerSource` point to a dataset from the same workspace and, `leftFieldName`/`rightFieldName` be indexed.
 
 @since 100.1
 @see `AGSArcGISMapImageSublayer#initWithID:source:`
 */
@interface AGSTableJoinSublayerSource : AGSSublayerSource

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Intialize the source with the provided parameters.
 @param leftFieldName Name of the field in the `leftSublayerSource` to use in the join operation for finding matching values
 @param leftSublayerSource The source on the left side of the join
 @param rightFieldName Name of the field in the `rightSublayerSource` to use in the join operation for finding matching values
 @param rightSublayerSource The source on the right side of the join
 @param joinType The type of join to perform
 @return A new initialized source
 @since 100.1
 */
-(instancetype)initWithLeftFieldName:(NSString *)leftFieldName
                  leftSublayerSource:(AGSSublayerSource *)leftSublayerSource
                      rightFieldName:(NSString *)rightFieldName
                 rightSublayerSource:(AGSSublayerSource *)rightSublayerSource
                            joinType:(AGSJoinType)joinType;

/** Intialize the source with the provided parameters.
 @param leftFieldName Name of the field in the `leftSublayerSource` to use in the join operation for finding matching values
 @param leftSublayerSource The source on the left side of the join
 @param rightFieldName Name of the field in the `rightSublayerSource` to use in the join operation for finding matching values
 @param rightSublayerSource The source on the right side of the join
 @param joinType The type of join to perform
 @return A new initialized source
 @since 100.1
 */
+(instancetype)tableJoinSublayerSourceWithLeftFieldName:(NSString *)leftFieldName
                                     leftSublayerSource:(AGSSublayerSource *)leftSublayerSource
                                         rightFieldName:(NSString *)rightFieldName
                                    rightSublayerSource:(AGSSublayerSource *)rightSublayerSource
                                               joinType:(AGSJoinType)joinType;
#pragma mark -
#pragma mark properties

/** Type of join to perform between the two sources
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSJoinType joinType;

/** Name of the field in the `#leftSublayerSource` to use in the join operation for finding matching values
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *leftFieldName;

/** The source on the left side of the join
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSSublayerSource *leftSublayerSource;

/** Name of the field in the `#rightSublayerSource` to use in the join operation for finding matching values
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *rightFieldName;

/** The source on the right side of the join
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSSublayerSource *rightSublayerSource;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

