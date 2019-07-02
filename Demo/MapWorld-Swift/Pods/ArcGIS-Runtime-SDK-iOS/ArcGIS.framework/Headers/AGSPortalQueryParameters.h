/*
 COPYRIGHT 2011 ESRI
 
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

@class AGSEnvelope;

/** @file AGSPortalQueryParameters.h */ //Required for Globals API doc

/** @brief Defines a query on a portal. 
 
 To query a portal for items or groups, the AGSPortal's <code>findItemsWithQueryParameters:</code> and <code>findGroupsWithQueryParameters:</code> methods must use the query parameters specified by the AGSPortalQueryParameters class. You can choose any of pre-defined query strings, supplied by this class, or you can create a custom query string as per the specification in the Portal API. The default number of results returned is 10. Adjust this limit to return more results and use with the @c #startIndex property, if you wish to paginate the results.
 
 @since 100
 */
@interface AGSPortalQueryParameters : AGSJSONSerializableBase
NS_ASSUME_NONNULL_BEGIN

/** The query string specified for the search. 
 @since 100
 @see http://resources.arcgis.com/en/help/arcgis-rest-api/index.html#//02r3000000mn000000 for information on query syntax
 */
@property (nullable, nonatomic, copy, readwrite) NSString *query;

/** The field on which sorting should be done. 
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) NSString *sortField;

/** The order of sorting. 

 @since 100
 */
@property (nonatomic, assign, readwrite) AGSPortalQuerySortOrder sortOrder;

/** The index from which the results should be returned. The index number is 1-based. You should use this for paginating the search results. 
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger startIndex;

/** The number of results to be returned (default = 10). This, along with the @c #startIndex, can help you paginate the search results.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger limit;

/** The bounding box for a spatial search, which is an overlaps/intersects function of the query bounding box and the extent of the document. Documents that have no extent (e.g., mxds, 3dds, lyr) will not be found when doing a bounding box search.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSEnvelope *boundingBox;

/** Initializes a AGSPortalQueryParameters with a query string. 
 @param query The query string.  
 @since 100
 */
-(instancetype)initWithQuery:(NSString*)query;

/** A method to get an initialized, autoreleased query parameters object with a query string.
 @param query The query string. 
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersWithQuery:(NSString*)query;

/** Initializes a AGSPortalQueryParameters with a query string and the limit on results. 
 @param query The query string.
 @param limit The number of results to be returned. 
 @since 100
 */
-(instancetype)initWithQuery:(NSString*)query limit:(NSInteger)limit;

/** A method to get an initialized, autoreleased query parameters object with a query string and the limit.
 @param query The query string. 
 @param limit The number of results to be returned.  
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersWithQuery:(NSString*)query limit:(NSInteger)limit;

/** Returns query parameters that will find groups with a specified owner and title. Either property can be
 nil, but not simultaneously.
 @param username The username of the owner. 
 @param title The title of the group. 
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersForGroupsWithOwner:(nullable NSString*)username title:(nullable NSString*)title;

/** Returns query parameters that will find items with a specified type that satisfy the specified criteria.
 @param type The type of the portal item. 
 @param searchString The string used for broader search on the items; such as on tags, title etc. Can be nil.
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersForItemsOfType:(AGSPortalItemType)type withSearchString:(nullable NSString*)searchString;

/** Returns query parameters that will find items with a specified type that belong to a specified group.
 @param type The type of the portal item. 
 @param groupID The id of the group. Can be nil.
 @param searchString The string used for broader search on the items; such as on tags, title etc. Can be nil.
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersForItemsOfType:(AGSPortalItemType)type inGroup:(nullable NSString*)groupID withSearchString:(nullable NSString*)searchString;

/** Returns query parameters that will find items with a specified type that belong to a specified group.
 @param type The type of the portal item. 
 @param groupID The id of the group. Can be nil.
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersForItemsOfType:(AGSPortalItemType)type inGroup:(nullable NSString*)groupID;

/** Returns query parameters that will find all items belonging to a specified group.
 @param groupID The id of the group.
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersForItemsInGroup:(NSString*)groupID;

/** Returns a query parameters that will find an item with a specified id.
 @param itemID The id of the item.
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersForItemWithID:(NSString*)itemID;

/** Returns query parameters that will find items with a specified owner.
 @param username The username of the owner.
 @param searchString The string used for broader search on the items; such as on tags, title etc. Can be nil.
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersForItemsWithOwner:(NSString*)username searchString:(nullable NSString*)searchString;

/** Returns query parameters that will find items with a specified type that belong to a specified owner.
 @param type The type of the portal item.
 @param username The username of the owner.
 @param searchString The string used for broader search on the items; such as on tags, title etc. Can be nil.
 @since 100
 */
+(AGSPortalQueryParameters*)queryParametersForItemsOfType:(AGSPortalItemType)type owner:(NSString*)username searchString:(nullable NSString*)searchString;

NS_ASSUME_NONNULL_END
@end
