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

#import "AGSSymbolStyle.h"

@class AGSSymbol;

/** @file AGSDictionarySymbolStyle.h */ //Required for Globals API doc

/** @brief A dictionary symbol style
 
 Instances of this class represent a dictionary symbol style that is made up of a *.stylx file (a sqlite database from ArcGIS Pro), which contains the symbol primitives for a given symbology specification (such as mil2525d), as well as a rule engine that parses input fields. The dictionary symbols style assembles new symbols from the input attributes, and can also apply geometry manipulations to the symbols in the case of multipoint geometries.
 
 `AGSDictionarySymbolStyle` can be used in conjunction with a `AGSDictionaryRenderer` applied to a `AGSFeatureLayer` or `AGSGraphicsOverlay`.
 
 When used by itself, the dictionary symbol style supports two key workflows. The first is to find a symbol with provided attributes values. This is done by creating a map of field names and attribute values (as determined by the associated specification), and passing those into `#symbolWithAttributes:completion:`, which returns a new symbol. In this case, the key is the name of the specification field (e.g. "symbolset" in the case of mil2525d), and the value is value you want associated with that field (e.g "Atmospheric"). You might use this symbol to create a new graphic.
 
 You can also use a standalone dictionary symbol style to search for symbol primitives. Symbol primitives are the individual symbols that make up more complex and advanced multilayer military symbols. This is achieved using `AGSSymbolStyle#searchSymbolsWithParameters:completion:`. You could create a symbol picker app that searches for all symbols that have the tag "maritime" in it. The search results contain symbols which you could then either use as they are or extract from them different individual symbols to create a new composite symbol.
 
 @see `AGSDictionaryRenderer`
 @since 100
 */
@interface AGSDictionarySymbolStyle : AGSSymbolStyle

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the dictionary symbol style for the specified specification type. An example of specificationType is "mil2525d".
 The corresponding .stylx file for the specification type is assumed to be within the application bundle or shared documents directory.
 @param specificationType to use
 @return a new dictionary symbol style
 @since 100
 */
-(instancetype)initWithSpecificationType:(NSString *)specificationType;

/** Initialize the dictionary symbol style for the specified specification type. An example of specificationType is "mil2525d".
 The corresponding .stylx file for the specification type is assumed to be within the application bundle or shared documents directory.
 @param specificationType to use
 @return a new dictionary symbol style
 @since 100
 */
+(instancetype)dictionarySymbolStyleWithSpecificationType:(NSString *)specificationType;

/** Initialize the dictionary symbol style for the specified specification type and .stylx file. An example of specificationType is "mil2525d".
 @param specificationType to use
 @param styleFileURL URL to the .stylx file on disk
 @return a new dictionary symbol style
 @since 100
 */
-(instancetype)initWithSpecificationType:(NSString *)specificationType styleURL:(NSURL*)styleFileURL;

/** Initialize the dictionary symbol style for the specified specification type and .stylx file. An example of specificationType is "mil2525d".
 @param specificationType to use
 @param styleFileURL URL to the .stylx file on disk
 @return a new dictionary symbol style
 @since 100
 */
+(instancetype)dictionarySymbolStyleWithSpecificationType:(NSString *)specificationType styleURL:(NSURL*)styleFileURL;

#pragma mark -
#pragma mark properties

/**  Configuration containing additional properties for the specification type.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSDictionary<NSString*, NSString*> *configurationProperties;

/** The specification type, for example, "mil2525d"
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *specificationType;

/** Specifies the symbology field names. For example, mil2525d would include "identity", "symbolset", "symbolentity", and "modifier1", among many others.

 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *symbologyFieldNames;

/**  Specifies  thetext field names. For example, mil2525d would include "combateffectiveness", "credibility", "reliability", and "staffcomment", among
 many others.

 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *textFieldNames;

#pragma mark -
#pragma mark methods


/** Creates a symbol based on the provided attributes. For example, with mil2525d, you may want to obtain a symbol where
 "symbolset" is 40, "modifier1" is "Incident Qualifier : Accident", "echelon" is "Army", and so on. All of these
 key/value pairs can be used to obtain the specific symbol that you need. Once you have that symbol, you can apply
 it to a graphic or renderer, obtain its swatch image, or serialize to JSON.
 @param attributes used to create the symbol
 @param completion block that is invoked when the operation completes. The symbol is populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100
 */
-(id<AGSCancelable>)symbolWithAttributes:(NSDictionary<NSString*, id> *)attributes completion:(void(^)(AGSSymbol * __nullable symbol, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end

