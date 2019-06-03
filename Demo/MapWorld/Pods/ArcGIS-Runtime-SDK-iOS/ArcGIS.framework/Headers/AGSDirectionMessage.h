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

/** @file AGSDirectionMessage.h */ //Required for Globals API doc

/** @brief A message describing `AGSDirectionManeuver`
 
 Instances of this class represent a message used to describe an `AGSDirectionManeuver`
 
 @since 100
 */
@interface AGSDirectionMessage : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The type of message
 @since 100
 */
@property (nonatomic, assign, readonly) AGSDirectionMessageType type;

/** The text of the message
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *text;

NS_ASSUME_NONNULL_END
@end
