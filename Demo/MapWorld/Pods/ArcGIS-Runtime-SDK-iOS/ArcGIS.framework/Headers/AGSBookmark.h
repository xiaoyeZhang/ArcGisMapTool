/*
 COPYRIGHT 2014 ESRI
 
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
@class AGSViewpoint;

/** @file AGSBookmark.h */ //Required for Globals API doc

/** @brief A bookmark in a map
 
 Instance of this class represent a bookmark in a map. A bookmark represents a shortcut to a location in the map.
 @since 100
 */
@interface AGSBookmark : AGSObject <NSCopying>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize this object with the provided information
 @param name of the bookmark
 @param viewpoint the bookmark represents
 @return intitalized bookmark
 @since 100
 */
-(instancetype)initWithName:(NSString*)name viewpoint:(AGSViewpoint*)viewpoint;

+(instancetype)bookmark;

/** Initialize this object with the provided information
 @param name of the bookmark
 @param viewpoint the bookmark represents
 @return intitalized bookmark
 @since 100
 */
+(instancetype)bookmarkWithName:(NSString*)name viewpoint:(AGSViewpoint*)viewpoint;

#pragma mark -
#pragma mark properties

/** The name of the bookmark
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *name;

/** The map location that this bookmark represents
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSViewpoint *viewpoint;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
