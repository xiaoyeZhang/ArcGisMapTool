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

#import "AGSIDInfo.h"

@interface AGSMapServiceLayerIDInfo : AGSIDInfo

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

@property (nonatomic, assign, readonly) BOOL defaultVisibility;
@property (nonatomic, assign, readonly) double maxScale;
@property (nonatomic, assign, readonly) double minScale;
@property (nonatomic, assign, readonly) NSInteger parentLayerID;
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *sublayerIDs;

NS_ASSUME_NONNULL_END

@end
