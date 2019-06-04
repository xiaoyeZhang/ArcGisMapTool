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

#import "AGSObject.h"

/** @file AGSServiceDocumentInfo.h */ //Required for Globals API doc

/** @brief metadata about the service
 
 Instances of this class represent metatdata about the service
 
 @since 100
 */
@interface AGSServiceDocumentInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** anti aliasing mode of the service
 @since 100
 */
@property (nonatomic, assign, readonly) AGSAntialiasingMode antialiasingMode;

/** anti aliasing mode of the text in the service
 @since 100
 */
@property (nonatomic, assign, readonly) AGSTextAntialiasingMode textAntialiasingMode;

/** author of the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *author;

/** category of the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *category;

/** comments for the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *comments;

/** tags for the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *keywords;

/** subject of the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *subject;

/** title of the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *title;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
