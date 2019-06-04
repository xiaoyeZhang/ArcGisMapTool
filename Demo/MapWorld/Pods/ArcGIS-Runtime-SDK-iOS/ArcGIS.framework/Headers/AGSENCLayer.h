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

#import "AGSLayer.h"

@class AGSENCEnvironmentSettings;
@class AGSENCCell;
@class AGSENCFeature;

/** @file AGSENCLayer.h */ //Required for Globals API doc

/** @brief A layer that can display ENC data
 
 Instances of this class respresent a layer that can display ENC (Electronic Navigational Charts) data in S-57 format. ENC is a vector chart that conforms to the IHO specifications contained in Publication S-57, which is a transfer standard for vector data.
 
 @note `AGSENCEnvironmentSettings#SENCDataDirectory` and `AGSENCEnvironmentSettings#resourceDirectory` need to be set before ENC data can be used
 @license{Standard}
 @ingroup licensing
 @since 100.2
 */
@interface AGSENCLayer : AGSLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the layer with the provided ENC Cell
 @param cell used as the source of data for the ENC Layer
 @return Initialized ENC layer
 @since 100.2
 */
-(instancetype)initWithCell:(AGSENCCell*)cell;

/** Initialize the layer with the provided ENC Cell
 @param cell used as the source of data for the ENC Layer
 @return Initialized ENC layer
 @since 100.2
 */
+(instancetype)ENCLayerWithCell:(AGSENCCell*)cell;

#pragma mark -
#pragma mark properties

/** Cell used as the source of data for the ENC Layer
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSENCCell *cell;

#pragma mark -
#pragma mark methods

/** Clears selection on all features.
 @since 100.2
 */
-(void)clearSelection;

/** Select the specified feature. The map will be updated to render the feature so that it stands out. Only one feature can be selected at a time. Note that some ENC features are rendered as multiple objects on the map - for example, a soundings feature might consist of many individual measurements, each of which will be highlighted when the feature is selected.
 @param feature to select
 @since 100.2
 */
-(void)selectFeature:(AGSENCFeature *)feature;

NS_ASSUME_NONNULL_END

@end
