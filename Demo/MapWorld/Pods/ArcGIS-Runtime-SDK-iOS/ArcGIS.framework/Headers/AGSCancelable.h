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


/** @file AGSCancelable.h */ //Required for Globals API doc

/** @brief A protocol exposed by operations that allow cancellation
 
 A protocol exposed by operations that allow cancellation while in progress.
 
 @define{AGSCancelable.h, ArcGIS}
 @since 100
 */
@protocol AGSCancelable <NSObject>
NS_ASSUME_NONNULL_BEGIN

@required

/** Cancel the operation
 @since 100
 */
- (void)cancel;

/** Indicates whether the operation has been canceled
 @since 100
 */
- (BOOL)isCanceled;

NS_ASSUME_NONNULL_END
@end
