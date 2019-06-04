/*
 COPYRIGHT 2016 ESRI
 
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
#import "AGSGeodatabaseDataset.h"

/** @file AGSTransportationNetworkDataset.h */ //Required for Globals API doc

/** @brief A transportation network dataset
 
 Instances of this class represent a transportation network dataset in a local geodatabase (.geodatabase file)
 
 @since 100
 */
@interface AGSTransportationNetworkDataset : AGSObject <AGSGeodatabaseDataset>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The user-friendly name of the dataset
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *alias;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

