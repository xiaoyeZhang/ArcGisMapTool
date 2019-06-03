/*
 COPYRIGHT 2016 ESRI
 
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

#import "AGSLoadableBase.h"

/** @file AGSElevationSource.h */ //Required for Globals API doc

/** @brief A base class for elevation sources used in a scene surface
 
 Subclasses represent elevation sources to be used in a scene surface.
 
 @since 100
 */
@interface AGSElevationSource : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Indicates whether this elevation source is enabled or not
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isEnabled) BOOL enabled;

/** Name of the elevation source
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *name;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
