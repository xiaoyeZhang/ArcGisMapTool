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

@class AGSEnvelope;

/** @file AGSENCDataset.h */ //Required for Globals API doc

/** @brief An ENC Dataset
 
 Instances of this class represent an ENC (Electronic Navigational Chart) dataset.
 ENC datasets are retrieved from an exchange set. See `AGSENCExchangeSet`.
 
 @since 100.2
 */
@interface AGSENCDataset : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**  Whether the dataset is authorized.
 If the underlying data is S-57, then this function returns true.
 If the underlying data is S-63 and there is a valid cell permit, this function returns true.
 If the underlying data is S-63 and there is no valid cell permit, this function returns false.
 @since 100.3
 */
@property (nonatomic, assign, readonly) BOOL authorized;

/** Description of the dataset
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *datasetDescription;

/** Bounding box representing the geographic extent of the dataset
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** Name of the dataset
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Volume name of the dataset
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *volumeName;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
