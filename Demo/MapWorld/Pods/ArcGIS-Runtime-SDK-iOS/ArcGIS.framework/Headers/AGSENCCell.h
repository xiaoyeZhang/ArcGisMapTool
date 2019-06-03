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

/** @file AGSENCCell.h */ //Required for Globals API doc

/** @brief An ENC Cell
 
 Instances of this class represent a single ENC (Electronic Navigational Chart) data source.

 @note `AGSENCEnvironmentSettings#SENCDataDirectory` and `AGSENCEnvironmentSettings#resourceDirectory` need to be set before ENC data can be used
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
@interface AGSENCCell : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the ENC cell with the provided dataset
 @param dataset retrieved from an ENC exchange set
 @return Initialized ENC cell
 @since 100.2
 */
-(instancetype)initWithDataset:(AGSENCDataset *)dataset;

/** Initialize the ENC cell with the provided dataset
 @param dataset retrieved from an ENC exchange set
 @return Initialized ENC cell
 @since 100.2
 */
+(instancetype)ENCCellWithDataset:(AGSENCDataset *)dataset;

/** Initialize the ENC cell with a S-57/ENC (extension .000) file.
 @note `#initWithDataset:` is the preferred method of constructing an ENC cell delivered as part of an exchange set. When an ENC cell is constructed from the path directly, updates (*.001, *.002, etc.) that are part of the associated exchange set (if there is one) will not be applied.
 @param fileURL path to S-57/ENC (extension .000) file.
 @return Initialized ENC cell
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL;

/** Initialize the ENC cell with a S-57/ENC (extension .000) file.
 @note `#initWithDataset:` is the preferred method of constructing an ENC cell delivered as part of an exchange set. When an ENC cell is constructed from the path directly, updates (*.001, *.002, etc.) that are part of the associated exchange set (if there is one) will not be applied.
 @param fileURL path to S-57/ENC (extension .000) file.
 @return Initialized ENC cell
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)ENCCellWithFileURL:(NSURL *)fileURL;

#pragma mark -
#pragma mark properties

/** The ENC dataset associated with the ENC cell. Only applicable if this cell was initialized with a dataset.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSENCDataset *dataset;

/** The path to the S-57/ENC (extension .000) file associated with the ENC cell. Only applicaable if this cell was initialized with a path.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) NSURL *fileURL;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
