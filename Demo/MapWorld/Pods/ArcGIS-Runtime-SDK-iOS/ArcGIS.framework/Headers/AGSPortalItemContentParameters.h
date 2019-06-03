/*
 COPYRIGHT 2013 ESRI
 
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

/** @file AGSPortalItemContentParameters.h */ //Required for Globals API doc

/** @brief Content for a new @c AGSPortalItem
 
 Instances of this class represent content for a new portal item created by @c AGSPortal#addPortalItem:withContentParams:toFolder:
 
 @define{AGSPortalItemContentParameters.h, ArcGIS}
 @since 100
 */
@interface AGSPortalItemContentParameters : NSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize an AGSPortalItemContentParameter object with data.
 @param data The data representing the file to be added or updated on an @c AGSPortalItem.
 @param filename The file name to be used for the file being uploaded for this content item.
 @return An autoreleased AGSPortalItemContentParameters object.
 @since 100
 */
+(instancetype)portalItemContentParametersWithData:(NSData*)data filename:(nullable NSString*)filename;

/** Initialize an AGSPortalItemContentParameter object with a url.
 @param URL The url to be used for the @c AGSPortalItem.
 @return An autoreleased AGSPortalItemContentParameters object.
 @since 100
 */
+(instancetype)portalItemContentParametersWithURL:(NSURL*)URL;

/** Initialize an AGSPortalItemContentParameter object with json.
 @param JSONObject The json representing the content (like a web map) for the @c AGSPortalItem.
 @return An autoreleased AGSPortalItemContentParameters object.
 @since 100
 */
+(instancetype)portalItemContentParametersWithJSON:(id)JSONObject;

#pragma mark -
#pragma mark properties

/** The object representing the content to be added or updated. 
 Valid objects for adding/updating are:
 @li NSData - for file data
 @li NSURL - for service items
 @li NSDictionary or NSArray - for json content, such as a web map
 @since 100
 */
@property (nonatomic, strong, readonly) id<NSObject> value;

/** The name of the file being uploaded for this content item, including extension.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *filename;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
