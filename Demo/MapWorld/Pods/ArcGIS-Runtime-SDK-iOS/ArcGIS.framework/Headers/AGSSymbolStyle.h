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

#import "AGSLoadableRemoteResourceBase.h"

@class AGSSymbolStyleSearchParameters;
@class AGSSymbolStyleSearchResult;
@class AGSSymbol;

/** @file AGSSymbolStyle.h */ //Required for Globals API doc

/** @brief A symbol style
 
 Instances of this class represent a symbol style that is based on a .stylx file (a sqlite database from ArcGIS Pro containing symbols)
 
 When used by itself, a symbol style supports two key workflows. The first is to find a symbol with provided key values. This is done by creating an array of key fields, and passing those into `#symbolForKeys:completion:`, which returns a new symbol. In this case, the key is the value associated to the symbol in the .stylx file. You might use this symbol to create a new Graphic.
 
 You can also use a standalone symbol style to search for symbol primitives. Symbol primitives are the individual symbols that make up more complex symbols. This is achieved using `#searchSymbolsWithParameters:completion:`. You could create a symbol picker app that searches for all symbols that have the tag "maritime" in it. The search results contain symbols which you could then either use as they are or extract from them different individual symbols to create a new composite symbol.
 
 @since 100
 */
@interface AGSSymbolStyle : AGSLoadableRemoteResourceBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a symbol style with the specified .stylx file
 @param fileURL to a .stylx file on disk
 @return a new initialized symbol style
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)fileURL;

/** Initialize a symbol style with the specified .stylx file
 @param fileURL to a .stylx file on disk
 @return a new initialized symbol style
 @since 100
 */
+(instancetype)symbolStyleWithURL:(NSURL*)fileURL;

/** Initialize a symbol style with the name of a .stylx file that is within the application bundle or shared documents directory.
 @param name of the .stylx file (without the file extension) within the application bundle or shared documents directory.
 @return a new initialized symbol style
 @since 100
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize a symbol style with the name of a .stylx file that is within the application bundle or shared documents directory.
 @param name of the .stylx file (without the file extension) within the application bundle or shared documents directory.
 @return a new initialized symbol style
 @since 100
 */
+(instancetype)symbolStyleWithName:(NSString*)name;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

/**  A convenience method to get properly initialized search parameters for looking up symbols within the .stylx file. The parameters contain all of the possible input values for categories, keys, names, symbolClasses, and tags. This is an expensive task that should be used sparingly.
 @param completion block that is invoked when the operation completes. The search parameters are populated if the operation succeeds, else the error is populated if the operation fails.
 @see `AGSSymbolStyle#searchSymbolsWithParameters:completion:`
 @since 100
 */
-(id<AGSCancelable>)defaultSearchParametersWithCompletion:(void(^)(AGSSymbolStyleSearchParameters * __nullable searchParams, NSError * __nullable error))completion;

/** Find a symbol in the .stylx file based on the supplied keys. For example, assume XYZ stylx file has a symbol with key "abc" which is the central symbol and another symbol with key "pqr", which could be the modifier/echelon placed at some offset from central geometry. So if you provide these two keys as attributes then symbol style will find and assemble a multi-layer symbol accordingly.
 @since 100
 */
-(id<AGSCancelable>)symbolForKeys:(NSArray<NSString*>*)keys completion:(void(^)(AGSSymbol * __nullable symbol, NSError * __nullable error))completion;

/** Search for a symbol in the .stylx file based on the input search parameters. For example, you could search for all symbols that have the tag "airspace". You can also set the match to be strict or not, which will determine if the search uses "=" or "LIKE" for each parameter. To get all available symbols, pass in the parameters returned by `#defaultSearchParametersWithCompletion`.
 @param searchParameters defining which symbols to search for
 @param completion block that is invoked when the operation completes. The results are populated if the operation succeeds, else the error is populated if the operation fails.
 @see `AGSSymbolStyle#defaultSearchParametersWithCompletion:`
 @since 100
 */
-(id<AGSCancelable>)searchSymbolsWithParameters:(AGSSymbolStyleSearchParameters*)searchParameters completion:(void(^)(NSArray<AGSSymbolStyleSearchResult*> * __nullable searchResults, NSError * __nullable error))completion;


NS_ASSUME_NONNULL_END

@end
