/*
 COPYRIGHT 2012 ESRI
 
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

NS_ASSUME_NONNULL_BEGIN

/** @file AGSImage.h */ //Required for Globals API doc

#if TARGET_OS_IPHONE
/** AGSImage is defined as a UIImage for iOS platform.
 @since 100
 */
#define AGSImage UIImage


#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)
/** AGSImage is defined as a NSImage for MacOS platforms.
 @since 100
 */
#define AGSImage NSImage


#endif

NS_ASSUME_NONNULL_END
