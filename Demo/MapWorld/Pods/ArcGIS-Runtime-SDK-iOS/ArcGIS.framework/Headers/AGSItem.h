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

#import "AGSLoadableBase.h"

@class AGSEnvelope;
@class AGSLoadableImage;

/** @file AGSItem.h */ //Required for Globals API doc


/** @brief Object representing a unit of content.
 
 Subclasses represent a unit of content. The content may reside in an ArcGIS portal, or locally on disk.
 
 @see AGSPortalItem
 @since 100
 */
@interface AGSItem : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The ID of the item.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *itemID;

/** Title of the item.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *title;

/** Snippet or summary of the item with a character limit of 250 characters.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *snippet;

/** The description of the item, if any.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *itemDescription;

/** The access information about the item.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *accessInformation;

/** The default extent of the item. Only applicable to certain item types.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSEnvelope *extent;

/** Words or short phrases that describe the item.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *tags;

/** Spatial reference of the geographic content 
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *spatialReferenceName;

/** Date on which the item was first saved.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *created;

/** Date on which the item was modified.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *modified;

/** The thumbnail image of the item.  The image needs to be loaded asynchronously by calling `AGSLoadableImage#loadWithCompletion:`
 
 If it is nil, there is no item thumbnail.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLoadableImage *thumbnail;

/** The terms of use of the item.
 It is stored in the "licenseInfo" property in json.
 The property can contain HTML markup.
 @since 100.4
 */
@property (nonatomic, copy, readwrite) NSString *termsOfUse;

#pragma mark -
#pragma mark methods

/** Sets the thumbnail for this item.
 @param image The NSImage/UIImage representing the thumbnail. The recommended image size is 200 pixels wide by 133 pixels high. Acceptable image formats are PNG, GIF, and JPEG. The maximum file size for an image is 1 MB.
 @since 100
 */
-(void)setThumbnailWithImage:(nullable AGSImage*)image;

/** Kicks off an operation to fetch the raw bytes for the item. The completion block is invoked when the operation completes successfully or if an error is encountered.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchDataWithCompletion:(void(^)(NSData * __nullable data, NSError * __nullable error))completion;

/** Kicks off an operation to update the item's properties on the portal or in a file on disk.
 The completion block is invoked when the operation completes successfully or if an error is encountered.
 
 Updating properties can be only done for local items that are unpacked.
 For example a mobile map package file (.mmpk) can be unpacked using
 `AGSMobileMapPackage#unpackMobileMapPackageAtFileURL:outputDirectory:completion`. Once unpacked local items within the package can be updated see `AGSMobileMapPackage#item` and for any maps use `AGSMap#item`.
 Like packages, the local item available from an item resource cache can be updated. This is accessed with `AGSItemResourceCache#item`.
 If the package is not unpacked, an error is returned in the completion block.
 
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @license{Basic, when using a portal item}
 @ingroup licensing
 @since 100.4
 */
-(id<AGSCancelable>)updateItemPropertiesWithCompletion:(nullable void(^)(NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
