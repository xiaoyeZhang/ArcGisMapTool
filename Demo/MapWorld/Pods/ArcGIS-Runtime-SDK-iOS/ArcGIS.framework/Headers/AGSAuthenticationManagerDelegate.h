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

NS_ASSUME_NONNULL_BEGIN

@class AGSAuthenticationManager;
@class AGSAuthenticationChallenge;

#if TARGET_OS_IPHONE && !TARGET_OS_TV
@class UIViewController;
#elif TARGET_OS_MAC && !TARGET_OS_IPHONE
@class NSViewController;
#endif

/** @file AGSAuthenticationManagerDelegate.h */ //Required for Globals API doc

/** @brief A delegate for `AGSAuthenticationManager`
 
 A protocol which must be adopted by a class wishing to be notified of authentication challenges issued or handled by the `AGSAuthenticationManager`. An instance of the class must then be set as `AGSAuthenticationManager#delegate` .
 
 All of the methods of this protocol are optional.
 
 @since 100
 */
@protocol AGSAuthenticationManagerDelegate <NSObject>
@optional

/** Tells the delegate that the `AGSAuthenticationManager` received an authentication challenge. It then becomes the delegate's responsibility to handle the challenge.
 
 If this method is not implemented by the delegate, the authentication manager will try to resolve the challenge using its own default challenge handler instead.
 @since 100
 */
-(void)authenticationManager:(AGSAuthenticationManager*)authenticationManager didReceiveAuthenticationChallenge:(AGSAuthenticationChallenge*)challenge;

#if TARGET_OS_IPHONE && !TARGET_OS_TV

/** Tells the delegate that the `AGSAuthenticationManager` wants to show the provided view controller as part of handling the authentication challenge using its own default handler. This method is optional, but if you want to show view controller in different way than the standard modal way, then you need to implement this method. Currently, this method is called only while displaying the OAuth login page. All other prompts are being displayed in standard alert which is always presented and dismissed modally.
 
 If this method is not implemented by the delegate, the authentication manager will present the view controller.
 @since 100
 */
-(void)authenticationManager:(AGSAuthenticationManager*)authenticationManager wantsToShowViewController:(UIViewController*)viewController;

/** Tells the delegate that the `AGSAuthenticationManager` wants to dismiss the provided view controller as part of handling the authentication challenge using its own default handler. This method is optional, but if you want to dismiss view controller in different way than the standard modal way, then you need to implement this method. Currently, this method is called only while displaying the OAuth login page. All other prompts are being displayed in standard alert which is always presented and dismissed modally.
 
 If this method is not implemented by the delegate, the authentication manager will dismiss the view controller.
 @since 100
 */
-(void)authenticationManager:(AGSAuthenticationManager*)authenticationManager wantsToDismissViewController:(UIViewController*)viewController;
#elif TARGET_OS_MAC && !TARGET_OS_IPHONE

/** Tells the delegate that the `AGSAuthenticationManager` wants to show the provided view controller as part of handling the authentication challenge using its own default handler. This method is optional, but if you want to show view controller in different way than the sheet, then you need to implement this method. Currently, this method is called only while displaying the OAuth login page. All other prompts are being displayed in standard alert which is always presented and dismissed as sheet.
 
 If this method is not implemented by the delegate, the authentication manager will present the view controller.
 @since 100
 */
-(void)authenticationManager:(AGSAuthenticationManager*)authenticationManager wantsToShowViewController:(NSViewController*)viewController;

/** Tells the delegate that the `AGSAuthenticationManager` wants to dismiss the provided view controller as part of handling the authentication challenge using its own default handler. This method is optional, but if you want to dismiss view controller in different way than the sheet, then you need to implement this method. Currently, this method is called only while displaying the OAuth login page. All other prompts are being displayed in standard alert which is always presented and dismissed as sheet.
 
 If this method is not implemented by the delegate, the authentication manager will dismiss the view controller.
 @since 100
 */
-(void)authenticationManager:(AGSAuthenticationManager*)authenticationManager wantsToDismissViewController:(NSViewController*)viewController;
#endif

@end

NS_ASSUME_NONNULL_END

