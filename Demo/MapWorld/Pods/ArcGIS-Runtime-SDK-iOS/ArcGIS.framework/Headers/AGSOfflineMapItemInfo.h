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

/** @file AGSOfflineMapItemInfo.h */ //Required for Globals API doc

/** @brief Metadata about an offline map
 
 Instances of this class represent metadata about a map that should be persisted when it is taken offline.
 
 @since 100.1
 */
@interface AGSOfflineMapItemInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)offlineMapItemInfo;

#pragma mark -
#pragma mark properties

/** The access information about the item.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString * accessInformation;


/** The description of the item.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *itemDescription;

/** Snippet or summary of the item with a character limit of 250 characters.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *snippet;

/** Words or short phrases that describe the item.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSArray<NSString *> *tags;


/** The terms of use of the item.
 This property can contain HTML formatting.
 @since 100.4
 */
@property (nonatomic, copy, readwrite) NSString *termsOfUse;

/** The thumbnail image of the item.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSImage *thumbnail;

/** Title of the item.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *title;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END


