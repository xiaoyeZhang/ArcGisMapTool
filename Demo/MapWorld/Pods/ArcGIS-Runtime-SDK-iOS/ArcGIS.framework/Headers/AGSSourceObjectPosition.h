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

@interface AGSSourceObjectPosition : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));
-(instancetype)initWithSourceIndex:(NSInteger)sourceIndex sourceObjectID:(long long)sourceObjectID position:(double)position;
+(instancetype)sourceObjectPositionWithSourceIndex:(NSInteger)sourceIndex sourceObjectID:(long long)sourceObjectID position:(double)position;

#pragma mark -
#pragma mark properties

@property (nonatomic, assign, readwrite) double position;
@property (nonatomic, assign, readwrite) NSInteger sourceIndex;
@property (nonatomic, assign, readwrite) long long sourceObjectID;

NS_ASSUME_NONNULL_END
@end
