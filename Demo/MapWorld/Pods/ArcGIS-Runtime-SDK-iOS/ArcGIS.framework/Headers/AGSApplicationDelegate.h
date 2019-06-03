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

/*@file AGSApplicationDelegate.h */

/** @brief An iOS app delegate for handling app events related to actions initiated by ArcGIS classes
 
 An instance of this class represents an application delegate that can handle application related events that are of interest to or initiated by ArcGIS classes.
 
 The methods in this class are designed to mirror those in Apple's `UIApplicationDelegate`. You should call them in the respective methods in your application delegate's implementation so that ArcGIS classes can respond to application events.
 
 @since 100
 */
@interface AGSApplicationDelegate : NSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** The singleton instance of this class.
 @since 100
 */
+(instancetype)sharedApplicationDelegate;

#pragma mark -
#pragma mark methods

/** Provides a way to process @c NSURLSession related events for data downloaded in the background.
 The download could have been initiated in the background by @c #application:performFetchWithCompletionHandler:, or it might have been initiated in the
 foreground and the app later terminated or moved into the background.
 This method should be called in the <code>-[UIApplicationDelegate application:handleEventsForBackgroundURLSession:completionHandler:]</code> delegate method. 
 Once the download finishes, the completion handler on your @c AGSGDBSyncTask or @c AGSExportTileCacheTask will be invoked to let you know that the job has
 completed. If your app is still in the background, you can post a local notification to alert the user.
 @since 100
 */
-(void)application:(UIApplication*)application handleEventsForBackgroundURLSession:(NSString*)identifier completionHandler:(void (^)(void))completionHandler;

/** Provides a way to process the result returned from Safari/SFSafariViewController if you are using Safari-based, out-of-app authentication workflow.
 You should call this method from <code>-[UIApplicationDelegate application:openURL:sourceApplication:annotation:]</code> delegate method.
 
 ArcGIS app delegate can handle this event only if the provided URL is the same as the `redirectURL` used in `AGSOAuthConfiguration` set on `AGSAuthenticationManager#OAuthConfigurations`.
 @return Flag indicating whether the app delegate did indeed handle this event because it was ArcGIS related, or if you need to handle it yourself because it isn't ArcGIS related.
 @since 100
 @deprecated 100.1. Use `#application:openURL:options:` instead.
 */
-(BOOL)application:(UIApplication*)application openURL:(NSURL*)url sourceApplication:(nullable NSString*)sourceApplication annotation:(nullable id)annotation __deprecated_msg("Please use application:openURL:options:");

/** Provides a way to process the result returned from Safari/SFSafariViewController if you are using Safari-based, out-of-app authentication workflow.
 You should call this method from <code>-[UIApplicationDelegate application:openURL:options:]</code> delegate method.
 
 ArcGIS app delegate can handle this event only if the provided URL is the same as the `redirectURL` used in `AGSOAuthConfiguration` set on `AGSAuthenticationManager#OAuthConfigurations`.
 @return Flag indicating whether the app delegate did indeed handle this event because it was ArcGIS related, or if you need to handle it yourself because it isn't ArcGIS related.
 @since 100
 */
-(BOOL)application:(UIApplication*)application openURL:(NSURL*)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id>*)options;

NS_ASSUME_NONNULL_END
@end
