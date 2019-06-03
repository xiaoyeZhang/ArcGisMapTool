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

#import "AGSObject.h"

/** @file AGSSymbolStyleSearchParameters.h */ //Required for Globals API doc

/** @brief Search parameters used to search for symbols in a symbol style
 
 Instances of this class represent search parameters used to search for symbols in a symbol style. You can specify different parameters when searching a symbol style. For example, you may want to search for any symbols where the category is "2", the name contains "destroyed", and the tags contain "Protection Lines". You need to pass this handle to all style symbol search parameters functions. This object allows you to set the parameters in order to perform a search on symbol style .
 
 @see `AGSSymbolStyle#searchSymbolsWithParameters:completion:`
 @since 100
 */

@interface AGSSymbolStyleSearchParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialze the search parameters
 @since 100
 */
+(instancetype)symbolStyleSearchParameters;

#pragma mark -
#pragma mark properties

/** Specifies the list of categories defined in the .stylx file to be used for search. For example, with mil2525d you may want to search for symbols where the categories are "Activities : Main Icon" or "Sea Surface : Main Icon".
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *categories;

/** Specifies if `#categories` parameter is to be matched exactly against the database. A strict match will force the search to use "=", otherwise SQL "LIKE" operator is used.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL categoriesStrictlyMatch;

/** Returns true if the values for categories, keys, names, symbolClasses and tags are all empty. This does not take into account any of the strictlyMatch settings.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

/** Specifies the list of keys(unique identifiers) to be used for search. For example, with mil2525d you may want to search for symbols where the keys are "25272100" or "2_635_1c"
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *keys;

/** Specifies if `#keys` parameter is to be matched exactly against the database. A strict match will force the search to use "=", otherwise SQL "LIKE" operator is used.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL keysStrictlyMatch;

/** Specifies the list of names to be used for search. For example, with mil2525d you may want to search for symbols where the names are "Ship Propulsion : Nuclear Powered" or "Simulation : Friend : Air".
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *names;

/** Specifies if `#names` parameter is to be matched exactly against the database. A strict match will force the search to use "=", otherwise SQL "LIKE" operator is used.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL namesStrictlyMatch;

/** Specifies the list of symbol classes to be used for search.  For example, with mil2525d you may want to search for symbols where the symbol classes are "3" (Point Symbol) or "7" (North Arrow).
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *symbolClasses;

/** Specifies if `#symbolClasses` parameter is to be matched exactly against the database. A strict match will force the search to use "=", otherwise SQL "LIKE" operator is used.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL symbolClassesStrictlyMatch;

/** Specifies the list of names to be used for search. For example, with mil2525d you may want to search for symbols where the tags include "Airspace Control Points" or "Meteorological - Oceanographic".
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *tags;

/** Specifies if `#tags` parameter is to be matched exactly against the database. A strict match will force the search to use "=", otherwise SQL "LIKE" operator is used.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL tagsStrictlyMatch;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

