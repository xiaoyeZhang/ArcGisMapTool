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
#import "AGSSublayerSource.h"


/** @file AGSMapSublayerSource.h */ //Required for Globals API doc

/** @brief A source for `AGSArcGISMapImageSublayer` based on an existing sub layer.
 
 Instances of this class represent a source for `AGSArcGISMapImageSublayer` based on an existing sublayer in the ArcGIS Map Service.
 
 @since 100.1
 @see `AGSArcGISMapImageSublayer#initWithID:source:`
*/
@interface AGSMapSublayerSource : AGSSublayerSource

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the source with the ID of an existing sublayer in the ArcGIS Map Service.
 @param mapSublayerID ID of an existing sublayer in the ArcGIS Map Service.
 @since 100.1
 @return A new initialized source
 */
-(instancetype)initWithID:(NSInteger)mapSublayerID;

/** Initialize the source with the ID of an existing sublayer in the ArcGIS Map Service.
 @param mapSublayerID ID of an existing sublayer in the ArcGIS Map Service.
 @since 100.1
 @return A new initialized source
 */
+(instancetype)mapSublayerSourceWithID:(NSInteger)mapSublayerID;

#pragma mark -
#pragma mark properties

/** The geodatabase version to use.
 @since 100.1
*/
@property (nonatomic, copy, readwrite) NSString *geodatabaseVersion;


/** ID of an existing sublayer in the ArcGIS Map Service
 @since 100.1
 */
@property (nonatomic, assign, readonly) NSInteger mapSublayerID;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

