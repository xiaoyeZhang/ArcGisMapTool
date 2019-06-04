/*
 COPYRIGHT 2009 ESRI
 
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


/*
 
 This header is for public defines only

 */

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#define AGS_EXTERN UIKIT_EXTERN
#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)
#import <AppKit/AppKit.h>
#define AGS_EXTERN APPKIT_EXTERN
#endif

#if TARGET_OS_IPHONE

/** AGSEdgeInsets is defined as UIEdgeInsets on iOS platform.
Edge inset values are applied to a rectangle to shrink or expand the area represented by that rectangle. Positive values cause the object to be inset (or shrunk) by the specified amount. Negative values cause the object to be outset (or expanded) by the specified amount.
 @since 100.1
 */
#define AGSEdgeInsets UIEdgeInsets

/** Returns a `CGRect` that is inset from the original rect by the specified amount.
 @param rect to inset
 @param inset Amount by which to inset
 @since 100.1
 */
static inline CGRect AGSEdgeInsetsInsetRect(CGRect rect, AGSEdgeInsets inset) {
    return CGRectMake(rect.origin.x + inset.left,
                      rect.origin.y + inset.top,
                      rect.size.width - (inset.right + inset.left),
                      rect.size.height - (inset.top + inset.bottom));
}
#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)

/** Represents edge insets. 
 Edge inset values are applied to a rectangle to shrink or expand the area represented by that rectangle. Positive values cause the object to be inset (or shrunk) by the specified amount. Negative values cause the object to be outset (or expanded) by the specified amount.
 @since 100.1
 */
typedef struct AGSEdgeInsets {
    CGFloat top, left, bottom, right;
} AGSEdgeInsets;

/** Returns a `CGRect` that is inset from the original rect by the specified amount.
 @param rect to inset
 @param inset Amount by which to inset
 @since 100.1
 */
static inline CGRect AGSEdgeInsetsInsetRect(CGRect rect, AGSEdgeInsets inset) {
    return CGRectMake(rect.origin.x + inset.left,
                      rect.origin.y + inset.bottom,
                      rect.size.width - (inset.right + inset.left),
                      rect.size.height - (inset.top + inset.bottom));
}
#endif

/** Returns an edge inset.
Edge inset values are applied to a rectangle to shrink or expand the area represented by that rectangle. Positive values cause the object to be inset (or shrunk) by the specified amount. Negative values cause the object to be outset (or expanded) by the specified amount.
 @param top The inset at the top edge
 @param left The inset at the left edge
 @param bottom The inset at the bottom edge
 @param right The inset at the right edge
 @since 100.1
 */
static inline AGSEdgeInsets AGSEdgeInsetsMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right) {
    AGSEdgeInsets insets = {top, left, bottom, right};
    return insets;
}

/** A AGSEdgeInsets struct whose top, left, bottom, and right fields are all set to the value 0
@since 100.1
*/
AGS_EXTERN const AGSEdgeInsets AGSEdgeInsetsZero;

NS_ASSUME_NONNULL_BEGIN

#ifndef __has_feature
#define __has_feature(x) 0  // compatibility with non-clang compilers
#endif

#ifndef NS_CONSUMES_SELF
#if __has_feature(attribute_ns_consumes_self)
#define NS_CONSUMES_SELF __attribute__((ns_consumes_self))
#else
#define NS_CONSUMES_SELF
#endif
#endif

#ifndef NS_RETURNS_RETAINED
#if __has_feature(attribute_ns_returns_retained)
#define NS_RETURNS_RETAINED __attribute__((ns_returns_retained))
#else
#define NS_RETURNS_RETAINED
#endif
#endif

#pragma mark -
#pragma mark notifications

AGS_EXTERN NSNotificationName AGSLoadableDidLoadNotification;
AGS_EXTERN NSNotificationName AGSLoadableDidFailToLoadNotification;

#pragma mark -
#pragma mark blocks

typedef void(^AGSErrorCompletionBlockType)(NSError * _Nullable);


NS_ASSUME_NONNULL_END




