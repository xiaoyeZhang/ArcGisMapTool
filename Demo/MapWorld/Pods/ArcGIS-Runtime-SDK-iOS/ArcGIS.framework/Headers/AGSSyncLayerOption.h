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

/** @file AGSSyncLayerOption.h */ //Required for Globals API doc

/** @brief Sync parameters for a layer in a geodatabase
 
 Instances of this class represent sync parameters for an individual layer in a sync-enabled geodatabase that 
 uses the `AGSSyncModelLayer` sync model
 
 @since 100
 @see `AGSSyncGeodatabaseParameters`
 */

@interface AGSSyncLayerOption : AGSObject <NSCopying>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;

/** Initialize this object with provided values
 @param layerID ID of the layer
 @return initialized object
 @since 100
 */
-(instancetype)initWithLayerID:(NSInteger)layerID;

/** Initialize this object with provided values
 @param layerID ID of the layer
 @param syncDirection direction in which to synchronize data with the service
 @return initialized object
 @since 100
 */
-(instancetype)initWithLayerID:(NSInteger)layerID syncDirection:(AGSSyncDirection)syncDirection;

+(instancetype)syncLayerOption;

/** Initialize this object with provided values
 @param layerID ID of the layer
 @return initialized object
 @since 100
 */
+(instancetype)syncLayerOptionWithLayerID:(NSInteger)layerID;

/** Initialize this object with provided values
 @param layerID ID of the layer
 @param syncDirection direction in which to synchronize data with the service
 @return initialized object
 @since 100
 */
+(instancetype)syncLayerOptionWithLayerID:(NSInteger)layerID syncDirection:(AGSSyncDirection)syncDirection;

#pragma mark -
#pragma mark properties

/** ID of the layer
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger layerID;

/** Direction in which to synchronize the layer's data with the service
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSyncDirection syncDirection;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
