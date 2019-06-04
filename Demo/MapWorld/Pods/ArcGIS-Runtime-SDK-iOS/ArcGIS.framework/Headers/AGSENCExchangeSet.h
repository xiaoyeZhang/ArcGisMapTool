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

@class AGSENCDataset;

/** @file AGSENCExchangeSet.h */ //Required for Globals API doc

/** @brief An ENC exchange set
 
 Instances of this class represent an ENC (Electronic Navigational Chart) exchange set. ENC exchange sets consist of one or more datasets and a catalog. The exchange set's datasets can be used to create ENC cell objects, which can be used to create ENC layer objects for display in a map.
 
 @note `AGSENCEnvironmentSettings#SENCDataDirectory` and `AGSENCEnvironmentSettings#resourceDirectory` need to be set before ENC data can be used
 @since 100.2
 @see `AGSENCLayer` to display ENC data in a map
 @license{Standard}
 @ingroup licensing
 */
@interface AGSENCExchangeSet : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the exchange set with paths to catalog files
 @param fileURLs Array containing paths to catalog (CATALOG.031) files
 @return Initialized ENC exchange set
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithFileURLs:(NSArray<NSURL*> *)fileURLs;

/** Initialize the exchange set with paths to catalog files
 @param fileURLs Array containing paths to catalog (CATALOG.031) files
 @return Initialized ENC exchange set
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)ENCExchangeSetWithFileURLs:(NSArray<NSURL*> *)fileURLs;

#pragma mark -
#pragma mark properties

/** The ENC datasets that are part of the exchange set.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<AGSENCDataset*> *datasets;

/**  Path to the ENC exchange set's Readme file.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) NSURL *readmeFileURL;

/** The ENC catalog files that are part of the exchange set.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<NSURL*> *fileURLs;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
