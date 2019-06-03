/*
 COPYRIGHT 2017 ESRI
 
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

/** @brief Information about an ArcGIS Image Service rendering rule
 
 An instance of this class represents information about a pre-existing rendering rule of an ArcGIS Image Service.
 
 @see `AGSRenderingRule`
 @since 100.1
 */
@interface AGSRenderingRuleInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a new rendering rule info with the given name
 @param name of the pre-existing rendering rule available in the ArcGIS Image Service
 @return Initialized rendering rule info
 @since 100.1
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize a new rendering rule info with the given name
 @param name of the pre-existing rendering rule available in the ArcGIS Image Service
 @return Initialized rendering rule info
 @since 100.1
 */
+(instancetype)renderingRuleInfoWithName:(NSString*)name;

#pragma mark -
#pragma mark properties

/** Description of the rendering rule
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *infoDescription;

/** Details about the rendering rule
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *help;

/** Name of the rendering rule
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *name;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
