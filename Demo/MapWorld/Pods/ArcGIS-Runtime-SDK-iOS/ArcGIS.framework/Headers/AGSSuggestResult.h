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

/** @file AGSSuggestResult.h */ //Required for Globals API doc

/** @brief Result of a suggest operation on `AGSLocatorTask`
 
 Instances of this class represent a suggestion result provided by `AGSLocatorTask#suggestWithSearchText:parameters:completion:`.
 Suggestion results are intended to be displayed as a user enters text character-by-character into a search box. When the user picks a suggestion, you will need to use `AGSLocatorTask#geocodeWithSuggestResult:parameters:completion:` to find the location candidates for the suggestion.
 @since 100
 */
@interface AGSSuggestResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The user-friendly text of the suggestion to display to a user.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *label;

@property (nonatomic, assign, readonly, getter=isCollection) BOOL collection;

NS_ASSUME_NONNULL_END
@end
