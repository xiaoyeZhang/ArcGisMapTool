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

#import "AGSRenderer.h"

@class AGSDictionarySymbolStyle;

/** @file AGSDictionaryRenderer.h */ //Required for Globals API doc

/** @brief A renderer based on dictionary symbol styles
 
 Instances of this class represent a dictionary renderer that uses attributes from source data (such as fields of features in a feature table or attributes of graphics in a graphics overlay) to display unique multilayer symbols based on those attributes. This is achieved through an associated `#dictionarySymbolStyle`.
 
 The `#dictionarySymbolStyle` is created using a given specification such as "mil2525d". Each specification depends on attribute names that define the symbology and text of each feature. For example, the mil2525d specification looks for attributes named "identity", "symbolset", "symbolentity", and "modifier1", among many others. These attributes reference different symbols in the style file that are assembled to create a unique symbol. In order to display features, you must make sure the `AGSDictionaryRenderer` and associated `AGSDictionarySymbolStyle` know which attributes in your data to use. This can be achieved in multiple ways:
 
 @li Pre-author your data so that the attribute names match the attributes needed by the specification. In the case of the mil2525d specification, author a feature service (or other data source) with a field named "identity", another named "symbolset", and so on. In this scenario, you create a FeatureTable from the source data, create a feature layer from the feature table, apply the dictionary renderer to the feature layer, and the symbols are generated automatically and applied to the layer in the map. The same workflow applies for graphics in a graphics overlay. Ideally when creating graphics on the fly, you can give the attributes names that match the specification. When fields in the feature table and attributes in graphics have expected names, the dictionary renderer automatically finds them.
 
 @li Manually map your attribute names to those expected by the specification. You can map as many attribute names as necessary for the specification, but only need to map attribute names that do not match the specification (all matching attribute names will be automatically matched by the renderer). For example, an expected attribute "symbolset" might appear as the "symbol_set" field in your Feature Table. In this scenario, you can create a `AGSServiceFeatureTable` from a feature service, create a `AGSFeatureLayer` from that feature table, create a `AGSDictionaryRenderer` by manually mapping the "symbol_set" name to the "symbolset" name expected by the specification, and finally apply the renderer to the feature layer.
 
 A dictionary renderer can be applied to pre-authored data, such as feature services, mobile geodatabases (generated from ArcMap or a sync-enabled feature service), and feature layers in a mobile map package. You can also apply it to a graphics overlay, which allow for on-the-fly graphic generation.
 
 
 @see `AGSDictionarySymbolStyle` 
 @since 100
 */
@interface AGSDictionaryRenderer : AGSRenderer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the renderer with a reference to the dictionary symbol style.
 @param dictionarySymbolStyle to use
 @return a new dictionary renderer
 @since 100
 */
-(instancetype)initWithDictionarySymbolStyle:(AGSDictionarySymbolStyle*)dictionarySymbolStyle;

/** Initialize the renderer with a reference to the dictionary symbol style.
 @param dictionarySymbolStyle to use
 @return a new dictionary renderer
 @since 100
 */
+(instancetype)dictionaryRendererWithDictionarySymbolStyle:(AGSDictionarySymbolStyle*)dictionarySymbolStyle;

/** Initialize the renderer with a reference to the dictionary symbol style.
 @param dictionarySymbolStyle to use
 @param symbologyFieldOverrides specifying the mapping between the field names that `dictionarySymbolStyle` specification expects and the field names in the source data
 @param textFieldOverrides specifying the mapping between the field names that `dictionarySymbolStyle` specification expects and the field names in the source data
 @return a new dictionary renderer
 @since 100
 */
-(instancetype)initWithDictionarySymbolStyle:(AGSDictionarySymbolStyle*)dictionarySymbolStyle
                     symbologyFieldOverrides:(NSDictionary<NSString*, id> *)symbologyFieldOverrides
                          textFieldOverrides:(NSDictionary<NSString*, NSString*> *)textFieldOverrides;

/** Initialize the renderer with a reference to the dictionary symbol style.
 @param dictionarySymbolStyle to use
 @param symbologyFieldOverrides specifying the mapping between the field names that `dictionarySymbolStyle` specification expects and the field names in the source data
 @param textFieldOverrides specifying the mapping between the field names that `dictionarySymbolStyle` specification expects and the field names in the source data
 @return a new dictionary renderer
 @since 100
 */
+(instancetype)dictionaryRendererWithDictionarySymbolStyle:(AGSDictionarySymbolStyle *)dictionarySymbolStyle
                                   symbologyFieldOverrides:(NSDictionary<NSString*, id> *)symbologyFieldOverrides
                                        textFieldOverrides:(NSDictionary<NSString*, NSString*> *)textFieldOverrides;

#pragma mark -
#pragma mark properties

/** The dictionary symbol style used by the renderer
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSDictionarySymbolStyle *dictionarySymbolStyle;

/** The symbol fields to be overriden to match your data. This is useful when your source data's symbology field names do not match what the `#dictionarySymbolStyle` specification expects. For example, if the expected name in specification is "symbolset", and the value is your field's
 name is "symbol_set", set the override by adding an entry using "symbolset" as the key, and "symbol_set" as the value.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSDictionary<NSString*, NSString*> *symbologyFieldOverrides;

/** The text fields to be overrident to match your data. This is useful when your source data's text field names do not match what the `#dictionarySymbolStyle`  specification expects. For example, if the expected name in specification is "staffcomment", and the value is your field's
 name is "staff_comment", set the override by adding an entry using "staffcomment" as the key, and "staff_comment" as the value.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSDictionary<NSString*, NSString*> *textFieldOverrides;

/** Specifies whether the text for the symbols is visible
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isTextVisible) BOOL textVisible;

/** The maximum scale at which the text for symbols is visible. If the map or scene is zoomed in
 beyond this scale, the text will not be visible.
 @since 100
 */
@property (nonatomic, assign, readwrite) double textVisibilityMaxScale;

/** The minimum scale at which the text for symbols is visible. If the map or scene is zoomed out
 beyond this scale, the text will not be visible.
 @since 100
 */
@property (nonatomic, assign, readwrite) double textVisibilityMinScale;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

