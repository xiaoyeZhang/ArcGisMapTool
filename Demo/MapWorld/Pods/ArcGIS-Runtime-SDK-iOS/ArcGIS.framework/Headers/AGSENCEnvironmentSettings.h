/*
 COPYRIGHT 2017 ESRI
 
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

@class AGSENCDisplaySettings;

/** @file AGSENCEnvironmentSettings.h */ //Required for Globals API doc

/** @brief Environment settings for ENC data

Environment settings for ENC data.

@note Changes are applied to the display of all ENC layers in a map
@since 100.2
*/
@interface AGSENCEnvironmentSettings : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** The singleton instance of ENC Envrionment settings.
 @since 100.2
 */
+(instancetype)sharedSettings;

#pragma mark -
#pragma mark properties

/** ENC Display Settings, which allows selection of mariner, viewing group, and text group visibility settings.
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSENCDisplaySettings *displaySettings;

/** The location where the intermediate SENC files will be stored on disk. SENC is an acronym for System Electronic Navigational Chart. ENC data is converted into SENC format for optimal chart display.
 Subsequent loads of an ENC cell or exchange set will ignore the underlying cells (.000 files). Runtime will instead read from these intermediate SENC files directly. If these files get deleted, they will be re-created the next time the ENC cell or exchange set is used.
 @note This must be set before ENC content can be used
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *SENCDataDirectory;

/** The location of ENC resource files on disk.
 @note This must be set before ENC content can be used
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *resourceDirectory;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
