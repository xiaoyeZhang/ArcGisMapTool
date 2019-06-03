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

/** @file AGSJobMessage.h */ //Required for Globals API doc

/** @brief Informational message about the execution of a job
 
 Instances of this class represent an informational message about the execution of a job.
 
 @since 100
 */
@interface AGSJobMessage : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The message contents
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *message;

/** The job message's severity: information, warning or error.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSJobMessageSeverity severity;

/** The source of the job message, either from the service or from the ArcGISRuntime client.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSJobMessageSource source;

/** The date and time that the job message was created. This will be the current system
 * time on the user's device.
 @since 100.4
 */
@property (nonatomic, strong, readonly) NSDate *timestamp;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
