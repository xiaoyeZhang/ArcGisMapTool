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

/** @file AGSOrderBy.h */ //Required for Globals API doc

/** @brief An object that is used to specify the sort order of query results.
 
 Instances of this class represent information about the sort order of query results.
 
 @since 100
 */
@interface AGSOrderBy : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;

/** Initialize the object with the provided parameters
 @param fieldName based on which the query results should be sorted
 @param sortOrder specifying how the results should be sorted
 @return Initialized object
 @since 100
 */
-(instancetype)initWithFieldName:(NSString *)fieldName sortOrder:(AGSSortOrder)sortOrder;

/** Initialize the object with the provided parameters
 @param fieldName based on which the query results should be sorted
 @param sortOrder specifying how the results should be sorted
 @return Initialized object
 @since 100
 */
+(instancetype)orderByWithFieldName:(NSString *)fieldName sortOrder:(AGSSortOrder)sortOrder;

#pragma mark -
#pragma mark properties

/** The field based on which the query results should be sorted
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *fieldName;

/** The order specifying how the query results should be sorted
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSortOrder sortOrder;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
