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

#import "AGSLoadableRemoteResourceBase.h"

@class AGSLocatorInfo;
@class AGSGeocodeParameters;
@class AGSReverseGeocodeParameters;
@class AGSSuggestParameters;
@class AGSSuggestResult;
@class AGSGeocodeResult;
@class AGSPoint;

/** @file AGSLocatorTask.h */ //Required for Globals API doc

/** @brief A task to geocode and reverse-geocode addresses and places
 
 Instances of this class represent a task used to convert an address to a point (geocode) or vice-versa (reverse geocode). It also supports finding well known places and points of interest, and can provide suggestions character-by-character as a user types.
 
 The task can be created for an ArcGIS Geocode service hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server. The task can also be created for a locator dataset stored locally on the device in which case it can used even when the device has no network connectivity.
 
 @since 100
 @see https://developers.arcgis.com/features/geocoding/
 */
@interface AGSLocatorTask : AGSLoadableRemoteResourceBase
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the task with a URL to a remote ArcGIS Geocode service or a locator dataset (.loc file) on disk.
 @param URL to a remote ArcGIS Geocode service or a locator dataset (.loc file) on disk.
 @return initialized locator task
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize the task with a URL to a remote ArcGIS Geocode service or a locator dataset (.loc file) on disk.
 @param URL to a remote ArcGIS Geocode service or a locator dataset (.loc file) on disk.
 @return initialized locator task
 @since 100
 */
+(instancetype)locatorTaskWithURL:(NSURL*)URL;

/** Initialize the task with the name of a locator dataset within the application bundle or shared documents directory.
 @param name of the locator dataset (same as the name of the .loc file without the file extension)
 @return initialized locator task
 @since 100
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize the task with the name of a locator dataset within the application bundle or shared documents directory.
 @param name of the locator dataset (same as the name of the .loc file without the file extension)
 @return initialized locator task
 @since 100
 */
+(instancetype)locatorTaskWithName:(NSString*)name;

#pragma mark -
#pragma mark properties

/**
 Metadata about the ArcGIS Geocode service or locator dataset being used by the task
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLocatorInfo *locatorInfo;

#pragma mark -
#pragma mark methods

/** Perform a geocode operation to find location candidates for the provided text.
 @param searchText to geocode. Can be an address (such as "380 New York St" or "380 New York St, Redlands, California, 92373") or the name of a well known place (such as "Disneyland")
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)geocodeWithSearchText:(NSString *)searchText
                                completion:(void(^)(NSArray<AGSGeocodeResult*> * __nullable geocodeResults, NSError * __nullable error))completion;

/** Perform a geocode operation to find location candidates for the provided text.
 @param searchText to geocode. Can be an address (such as "380 New York St" or "380 New York St, Redlands, California, 92373") or the name of a well known place (such as "Disneyland")
 @param parameters to refine the results returned
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)geocodeWithSearchText:(NSString*)searchText
                                parameters:(AGSGeocodeParameters*)parameters
                                completion:(void(^)(NSArray<AGSGeocodeResult*> * __nullable geocodeResults, NSError * __nullable error))completion;

/** Perform a geocode operation to find location candidates for a suggestion provided by `#suggestWithSearchText:completion:`
 @param suggestResult suggestion to geocode
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)geocodeWithSuggestResult:(AGSSuggestResult*)suggestResult
                                   completion:(void(^)(NSArray<AGSGeocodeResult*> * __nullable geocodeResults, NSError * __nullable error))completion;

/** Perform a geocode operation to find location candidates for a suggestion provided by `#suggestWithSearchText:parameters:completion:`
 @param suggestResult suggestion to geocode
 @param parameters to refine the results returned. __Note:__ The parameters must match the original criteria specified in the `AGSSuggestParameters`, if `#suggestWithSearchText:parameters:completion:` was used to produce the `suggestResult`
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)geocodeWithSuggestResult:(AGSSuggestResult*)suggestResult
                                   parameters:(AGSGeocodeParameters*)parameters
                                   completion:(void(^)(NSArray<AGSGeocodeResult*> * __nullable geocodeResults, NSError * __nullable error))completion;

/** Perform a geocode operation to find location candidates for the provided values of a multi-line address.
 @param searchValues to geocode. Each value represents an individual address component of a multi-line address. The address components supported are defined by `AGSLocatorInfo#searchAttributes`. The _key_ of this dictionary should match `AGSLocatorAttribute#name`, and the _value_ in the input for that address component.
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)geocodeWithSearchValues:(NSDictionary<NSString*, NSString*> *)searchValues
                                  completion:(void(^)(NSArray<AGSGeocodeResult*> * __nullable geocodeResults, NSError * __nullable error))completion;

/** Perform a geocode operation to find location candidates for the provided values of a multi-line address.
 @param searchValues to geocode. Each value represents an individual address component of a multi-line address. The address components supported are defined by `AGSLocatorInfo#searchAttributes`. The _key_ of this dictionary should match `AGSLocatorAttribute#name`, and the _value_ in the input for that address component.
 @param parameters to refine the results returned
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)geocodeWithSearchValues:(NSDictionary<NSString*, NSString*> *)searchValues
                                  parameters:(AGSGeocodeParameters*)parameters
                                  completion:(void(^)(NSArray<AGSGeocodeResult*> * __nullable geocodeResults, NSError * __nullable error))completion;

/** Perform a reverse geocode operation to find address candidates for the provided location.
 @param location to reverse geocode
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
*/
-(id<AGSCancelable>)reverseGeocodeWithLocation:(AGSPoint*)location
                                     completion:(void(^)(NSArray<AGSGeocodeResult*> * __nullable geocodeResults, NSError * __nullable error))completion;

/** Perform a reverse geocode operation to find address candidates for the provided location.
 @param location to reverse geocode
 @param parameters to refine the results returned
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)reverseGeocodeWithLocation:(AGSPoint*)location
                                     parameters:(AGSReverseGeocodeParameters*)parameters
                                     completion:(void(^)(NSArray<AGSGeocodeResult*> * __nullable geocodeResults, NSError * __nullable error))completion;

/** Find suggestions for the provided text. Suggestion results are intended to be displayed as a user enters text character-by-character into a search box. When the user picks a suggestion, you will need to use `#geocodeWithSuggestResult:completion:` to find the location candidates for the suggestion.
 @param searchText to find suggestions for
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)suggestWithSearchText:(NSString*)searchText
                                completion:(void(^)(NSArray<AGSSuggestResult*> * __nullable suggestResults, NSError * __nullable error))completion;

/** Find suggestions for the provided text. Suggestion results are intended to be displayed as a user enters text character-by-character into a search box. When the user picks a suggestion, you will need to use `#geocodeWithSuggestResult:parameters:completion:` to find the location candidates for the suggestion.
 @param searchText to find suggestions for
 @param parameters to refine the results returned.
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)suggestWithSearchText:(NSString*)searchText
                                parameters:(AGSSuggestParameters*)parameters
                                completion:(void(^)(NSArray<AGSSuggestResult*> * __nullable suggestResults, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
