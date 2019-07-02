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

/** @file AGSViewLabelProperties.h */ //Required for Globals API doc

/** @brief Label properties for `AGSGeoView`
 
 Instances of this class represent label properties for `AGSGeoView` that specify how the contents of the map or scene should be labeled.
 
 @since 100
 */
@interface AGSViewLabelProperties : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize this object with the provided parameters
 @param animationEnabled whether label animations should be enabled
 @param labelingEnabled whether labels should be enabled
 @return Initialized view label properties
 @since 100
 */
-(instancetype)initWithAnimationEnabled:(BOOL)animationEnabled labelingEnabled:(BOOL)labelingEnabled;

/** Initialize this object with the provided parameters
 @param animationEnabled whether label animations should be enabled
 @param labelingEnabled whether labels should be enabled
 @return Initialized view label properties
 @since 100
 */
+(instancetype)viewLabelPropertiesWithAnimationEnabled:(BOOL)animationEnabled labelingEnabled:(BOOL)labelingEnabled;

#pragma mark -
#pragma mark properties

/** Specifies whether labels should animate or not
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isAnimationEnabled) BOOL animationEnabled;

/** Specifies whether labels are enabled or not
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isLabelingEnabled) BOOL labelingEnabled;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
