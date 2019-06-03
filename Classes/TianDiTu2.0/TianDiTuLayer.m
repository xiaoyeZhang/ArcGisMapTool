//
//  TianDiTuLayer.m
//  MapViewDemo-ObjC
//
//  Created by maklMac on 1/6/17.
//  Copyright © 2017 Esri. All rights reserved.
//

#import "TianDiTuLayer.h"
#import "TianDiTuLayerInfo.h"

@interface TianDiTuLayer()

@property (copy, nonatomic) NSString *mainType;

@end

@implementation TianDiTuLayer

-(instancetype)initWithTianDiTuLayerInfo:(TianDiTuLayerInfo *)tdtInfo layerType:(TianDiTuLayerType)layerType{
    
    self = [super initWithTileInfo:tdtInfo.tileInfo fullExtent:tdtInfo.fullExtent];
    
    __weak TianDiTuLayer *weakLtl = self;
    
    [self setTileRequestHandler:^(AGSTileKey *tileKey) {
        
        // get an image – probably from a network request…
        NSString *mainURL = [tdtInfo getTianDiTuServiceURL];
        
        switch (layerType) {
            case 0:
                weakLtl.mainType = @"TDT_VECTOR";

                break;
            case 1:
                weakLtl.mainType = @"TDT_IMAGE";
                break;
            default:
                break;
        }

        NSString *requestUrl1= [mainURL stringByAppendingString:@"&TILEMATRIX=%ld&TILEROW=%ld&TILECOL=%ld&FORMAT=tiles&tk=b51f69b1d856cb9cfa9400f889646b38"];
        NSString *requestUrl = [NSString stringWithFormat:requestUrl1,tileKey.column % 8,tdtInfo.servicename,tdtInfo.layername,tdtInfo.tilematrixset,(tileKey.level + 1),tileKey.row,tileKey.column];
        
        NSURL* aURL = [NSURL URLWithString:requestUrl];

        dispatch_queue_t queue = dispatch_queue_create("mapimage", DISPATCH_QUEUE_CONCURRENT);
        
        dispatch_async(queue, ^{
            
            NSData *imageData = [[NSData alloc] initWithContentsOfURL:aURL];

            dispatch_async(dispatch_get_main_queue(), ^{

                UIImage *img = [UIImage imageWithData:imageData];

                [weakLtl respondWithTileKey:tileKey data:UIImagePNGRepresentation(img) error:nil];
            });
        });
    }];

    return self;
}

@end
