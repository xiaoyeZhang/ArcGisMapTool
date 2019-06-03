/*
 COPYRIGHT 2014 ESRI
 
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

#import "AGSGeometry.h"
@class AGSPartCollection;
@class AGSPart;

/**
 @brief Base class for geometry types that have multiple parts.
 
 A base class for geometry types that have multiple parts. For example, polygons have multiple parts where each part is a ring and polylines have multiple parts where each part is a line.
 
 @since 100
 */
@interface AGSMultipart : AGSGeometry
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**
 The parts of this geometry. 
 Can be iterated through a for-in loop.
 
 ~~~ Objective-C
 AGSPolygon* polygon = ... ; //polygon with 2 parts (rings)
 for (AGSPart* part in polygon.parts){
   ...
 }
 
 ~~~
 
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPartCollection *parts;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
