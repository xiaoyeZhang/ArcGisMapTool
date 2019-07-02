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

@class AGSGeodatabase;

/** @file AGSGeodatabaseDataset.h */ //Required for Globals API doc

/** @brief A dataset within a geodatabase
 
 Instances of this class represent a dataset in a local geodatabase (.geodatabase file)
 
 @since 100
 */
@protocol AGSGeodatabaseDataset <NSObject>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The geodatabase within which the dataset resides
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSGeodatabase *geodatabase;

/** The name of the dataset
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

