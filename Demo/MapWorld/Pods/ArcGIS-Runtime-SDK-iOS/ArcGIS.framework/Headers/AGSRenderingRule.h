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

@class AGSRenderingRuleInfo;

/** @brief A rendering rule to apply to an `AGSImageServiceRaster`
 
 An instance of this class represents a rendering rule to apply to an `AGSImageServiceRaster`. The rendering rule could be predefined on the service, or it could be defined in JSON on the client and then sent to the service, but in both cases the processing in performed on the service to apply it.
 
 @see `AGSImageServiceRaster#renderingRule`
 @since 100.1
 */
@interface AGSRenderingRule : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this rendering rule with information about a pre-existing rendering rule available in the ArcGIS Image Service
 @param renderingRuleInfo specifying a predefined rendering rule in the ArcGIS Image Service
 @return Initialized rendering rule
 @since 100.1
 */
-(instancetype)initWithRenderingRuleInfo:(AGSRenderingRuleInfo*)renderingRuleInfo;

/** Initialize this rendering rule with provided JSON definition
 @param renderingRuleJSON defining a new rendering rule
 @return Initialized rendering rule
 @since 100.1
 */
-(instancetype)initWithRenderingRuleJSON:(NSDictionary<NSString*,id> *)renderingRuleJSON;

/** Initialize this rendering rule with information about a pre-existing rendering rule available in the ArcGIS Image Service
 @param renderingRuleInfo specifying a predefined rendering rule in the ArcGIS Image Service
 @return Initialized rendering rule
 @since 100.1
 */
+(instancetype)renderingRuleWithRenderingRuleInfo:(AGSRenderingRuleInfo*)renderingRuleInfo;

/** Initialize this rendering rule with provided JSON definition
 @param renderingRuleJSON defining a new rendering rule
 @return Initialized rendering rule
 @since 100.1
 */
+(instancetype)renderingRuleWithRenderingRuleJSON:(NSString*)renderingRuleJSON;

#pragma mark -
#pragma mark properties

/** Information about a predefined rendering rule in the ArcGIS Image Service
 Either this property or `#renderingRuleJSON` may be populated, but not both.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSRenderingRuleInfo *renderingRuleInfo;

/** JSON definition of a new rendering rule
 Either this property or `#renderingRuleInfo` may be populated, but not both.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,id> *renderingRuleJSON;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
