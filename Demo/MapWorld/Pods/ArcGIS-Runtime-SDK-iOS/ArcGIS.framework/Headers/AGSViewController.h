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

/** @file AGSViewController.h */ //Required for Globals API doc


#if TARGET_OS_IPHONE
/** AGSViewController is defined as UIViewController on iOS platform.
 @since 100
 */
#define AGSViewController UIViewController
#elif TARGET_OS_MAC && !TARGET_OS_IPHONE
/** AGSViewController is defined as NSViewController on macOS platform.
 @since 100
 */
#define AGSViewController NSViewController
#endif

NS_ASSUME_NONNULL_BEGIN

NS_ASSUME_NONNULL_END
