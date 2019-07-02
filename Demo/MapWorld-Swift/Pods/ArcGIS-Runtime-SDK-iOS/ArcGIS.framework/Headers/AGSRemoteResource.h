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

@class AGSRequestConfiguration;
@class AGSCredential;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A protocol adopted by classes that access remote network resources that have the potential to be secured
 
 A protocol adopted by classes whose objects need to access remote network resources, potentially in a secured manner.
 For example, a web service or a file on a web server that could require credentials to access.
 
 @since 100
 */
@protocol AGSRemoteResource <NSObject>

@required

/** The URL of the remote resource.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** Security credentials to access the remote resource. Only applicable if the resource is secured.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSCredential *credential;

/** The AGSRequestConfiguration object which defines the behavior and policies to use when accessing the remote resource.
 The default will be nil. If it is nil the [AGSRequestConfiguration globalConfiguration] will be used.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSRequestConfiguration *requestConfiguration;

@end

NS_ASSUME_NONNULL_END
