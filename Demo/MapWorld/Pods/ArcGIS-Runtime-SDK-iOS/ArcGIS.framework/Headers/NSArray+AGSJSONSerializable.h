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

/** @file NSArray+AGSJSONSerializable.h */ //Required for Globals API doc

/** @brief A category on @c NSArray to provide convenience methods for JSON serialization
 
 This category provides helper methods to express an <code>NSArray</code> as JSON and create
 an <code>NSArray</code> from JSON
 
 @since 100
 */

@interface NSArray (AGSJSONSerializable)

-(id)ags_toJSON;

+(NSArray*)ags_fromJSON:(NSArray*)jsonArray class:(Class)cls;

@end
