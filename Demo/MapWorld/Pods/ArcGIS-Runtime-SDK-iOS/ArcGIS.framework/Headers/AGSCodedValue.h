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

/** @file AGSCodedValue.h */ //Required for Globals API doc

/** @brief Coded values of a domain
 
 Instances of this class represent a coded values of a domain
 
 @since 100
 */

@interface AGSCodedValue : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The actual value of the coded value. The data type of the value depends upon the data type of the field it is associated with.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) id code;

/** A user-friendly name of the coded value.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

NS_ASSUME_NONNULL_END
@end
