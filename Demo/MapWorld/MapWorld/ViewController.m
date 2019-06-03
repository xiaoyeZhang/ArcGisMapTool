//
//  ViewController.m
//  MapWorld
//
//  Created by zhangxiaoye on 2019/5/21.
//  Copyright © 2019 zhangxiaoye. All rights reserved.
//

#import "ViewController.h"
#import <Masonry/Masonry.h>
#import "Classes/TianDiTu2.0/TianDiMarco.h"
#import "View/MapTypeView.h"
#import "Classes/GISMapToolUtils/GISMapTool.h"

#define RGBCOLOR(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]

@interface ViewController ()<AGSCalloutDelegate,AGSGeoViewTouchDelegate>

@property (strong, nonatomic) AGSMapView *mapView;

@property (nonatomic, strong) AGSMap *map;

@property (strong, nonatomic) NSMutableDictionary *TDT_typeDic;

/**
 定位
 */
@property (strong, nonatomic) UIButton *locationBtn;

/**
 切换地图类型
 */
@property (strong, nonatomic) UIButton *MapTypeBtn;

/**
 测量长度
 */
@property (strong, nonatomic) UIButton *MeasuringLengthBtn;

/**
 测量面积
 */
@property (strong, nonatomic) UIButton *MeasuringAreaBtn;

@property (strong, nonatomic) MapTypeView *mapTypeBtnView;

@property (assign, nonatomic) NSInteger selsecTag;


@property (strong, nonatomic) UIButton *otherBtn;


@property (strong, nonatomic) GISMapTool *polyline;


@property (strong, nonatomic) UIView *calloutView;

@property (strong, nonatomic) UIButton *leftBtn;
@property (strong, nonatomic) UILabel *titleLabel;
@property (strong, nonatomic) UIButton *rightBtn;
@property (strong, nonatomic) UIButton *NavigationBtn;
@property (strong, nonatomic) UIButton *DetailBtn;


@property (strong, nonatomic) NSArray *featureArr;
@property (assign, nonatomic) NSInteger featureIndex;


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    

    [self.view addSubview:self.mapView];
    
    [self.mapView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.mas_equalTo(self.view);
    }];
    
    
//    AGSArcGISTiledLayer *tiledLayer = [[AGSArcGISTiledLayer alloc]initWithURL:[NSURL URLWithString:@"http://223.112.123.34:6080/arcgis/rest/services/BaseMap/szdzdt_wgs84_3/MapServer"]];
//
//    self.mapView.map = [[AGSMap alloc]initWithBasemap:[AGSBasemap basemapWithBaseLayer:tiledLayer]];

    self.TDT_typeDic = [NSMutableDictionary dictionary];

    self.map = [[AGSMap alloc] init];

//    self.map.minScale = 2000000; // 最小缩小比例
    self.map.maxScale = 2000; // 最大放大比例

    [self loadingSlyMap:TDT_VECTOR];

    [self loadingSlyMap:TDT_IMAGE];
    
    [self loadingSlyMap:TDT_TERRAIN];

    [self.map.basemap.baseLayers setArray:[self.TDT_typeDic objectForKey:@(TDT_VECTOR)]];
    
    self.mapView.map = self.map;
    
    [self LocationClick:nil];

    [self addLocationBtn];

    self.polyline = [[GISMapTool alloc]initWithAGSMapView:self.mapView];

}

- (void)loadingSlyMap:(TianDiTuLayerType)type{
    
    TianDiTuLayerInfo *tdtInfo = [[TianDiTuLayerInfo alloc] initwithlayerType:type SpatialReferenceWKID:TDT_MERCATOR];

    TianDiTuLayerInfo *tdtannoInfo = [[TianDiTuLayerInfo alloc] initwithlayerType:type LanguageType:TDT_CN SpatialReferenceWKID:TDT_MERCATOR];

    TianDiTuLayer *ltl1 = [[TianDiTuLayer alloc] initWithTianDiTuLayerInfo:tdtInfo layerType:type];

    TianDiTuLayer *ltl2 = [[TianDiTuLayer alloc] initWithTianDiTuLayerInfo:tdtannoInfo layerType:type];

    NSArray *ltlArr = @[ltl1,ltl2];

    [_TDT_typeDic setObject:ltlArr forKey:@(type)];

}

- (void)addLocationBtn{
    
    
    [self.view addSubview:self.locationBtn];
    [self.view addSubview:self.MapTypeBtn];
    [self.view addSubview:self.mapTypeBtnView];
    [self.view addSubview:self.MeasuringLengthBtn];
    [self.view addSubview:self.MeasuringAreaBtn];
    
    [self.locationBtn mas_makeConstraints:^(MASConstraintMaker *make) {

        make.left.equalTo(self.view).offset(14);
        make.bottom.equalTo(self.view).offset(-25 -49);
        make.width.height.equalTo(@(42));
    }];

    [self.MapTypeBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.view).offset(-13);
        
        make.top.equalTo(self.view).offset(106);
        
        make.width.height.equalTo(@(42));
        
    }];
    
    [self.mapTypeBtnView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.mas_equalTo(self.MapTypeBtn.mas_left).offset(0);
        //        make.top.equalTo(self.titleScrollView.mas_bottom).offset(56);
        make.top.equalTo(self.view).offset(106);
        make.height.equalTo(@(42));
        make.width.equalTo(@(80));
        
    }];
    
    [self.MeasuringLengthBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.view).offset(-13);
        make.top.equalTo(self.MapTypeBtn.mas_bottom).offset(5);
        make.width.height.equalTo(@(42));

    }];

    [self.MeasuringAreaBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.view).offset(-13);
        make.top.equalTo(self.MeasuringLengthBtn.mas_bottom).offset(5);
        make.width.height.equalTo(@(42));

    }];
    
    
    self.otherBtn = [[UIButton alloc]init];
    
    self.otherBtn.backgroundColor = [UIColor whiteColor];
    
    [self.otherBtn setTitle:@"图层" forState:UIControlStateNormal];

    [self.otherBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

    [self.otherBtn addTarget:self action:@selector(closest) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.otherBtn];
    
    [self.otherBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.view).offset(-13);
        make.top.equalTo(self.MeasuringAreaBtn.mas_bottom).offset(5);
        make.width.height.equalTo(@(42));
        
    }];
    
}

- (void)closest{
    
    [self.polyline removeResourceLayerForKey:@"1"];
    
    [self.polyline AddResourceLayer:self.mapView MapViewScale:0 ResourceLayerId:@"1" ResourceLayerUrl:@"http://58.215.18.176:6080/arcgis/rest/services/WXNY/YQJS/MapServer/0"];
    
    __weak __typeof(self)weakSelf = self;
    
    self.polyline.CalloutForGraphicBlock = ^(NSArray * _Nonnull featureArr, AGSPoint * _Nonnull tapLocation, AGSFeatureLayer * _Nonnull featureLayer) {
        
        __strong typeof(self) strongBlock = weakSelf;

        [strongBlock showCalloutForGraphic:featureArr tapLocation:tapLocation];
 
    };
    
}

#pragma mark 弹出气泡
- (void)isClickUniqueLineSymbol:(AGSFeature *)field{
    
    [self.polyline showCalloutCustomView:self.calloutView MapViewScale:0 ForGraphic:field tapLocation:field.geometry.extent.center];

}

- (void)showCalloutForGraphic:(NSArray *)featureArr tapLocation:(AGSPoint *)tapLocation{
    
    [self addCalloutView];
    
    self.featureArr = featureArr;
    self.featureIndex = 0;

    if ([self.featureArr count] == 1) {

        self.leftBtn.hidden = YES;
        self.rightBtn.hidden = YES;

    }else{

        self.leftBtn.hidden = NO;
        self.rightBtn.hidden = NO;
    }

    if ([self.featureArr count] > 0) {
        AGSFeature *field = self.featureArr[self.featureIndex];

        self.titleLabel.text = field.attributes[@"YQMC"];
        
        [self isClickUniqueLineSymbol:field];

    }
    
}

- (void)addCalloutView{
    
    
    [self.calloutView addSubview:self.leftBtn];
    [self.calloutView addSubview:self.titleLabel];
    [self.calloutView addSubview:self.DetailBtn];
    [self.calloutView addSubview:self.rightBtn];
    [self.calloutView addSubview:self.NavigationBtn];
    
    [self.leftBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.left.equalTo(self.calloutView).offset(-5);
        make.top.equalTo(self.calloutView).offset(10);
        make.width.height.equalTo(@(28));
        
    }];
    
    [self.NavigationBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.top.equalTo(self.calloutView).offset(-5);
        make.bottom.right.equalTo(self.calloutView).offset(5);
        
        make.width.equalTo(@(34));
    }];
    
    [self.rightBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.right.mas_equalTo(self.NavigationBtn.mas_left).offset(0);
        make.top.equalTo(self.calloutView).offset(10);
        make.width.height.equalTo(@(28));
    }];
    
    [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.centerY.equalTo(self.leftBtn);
        make.left.mas_equalTo(self.leftBtn.mas_right).offset(0);
        make.right.mas_equalTo(self.rightBtn.mas_left).offset(0);
        
    }];
    
    [self.DetailBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.centerX.equalTo(self.titleLabel);
        make.top.mas_equalTo(self.titleLabel.mas_bottom).offset(5);
        make.width.equalTo(@(65));
    }];
    
    self.mapView.callout.customView = self.calloutView;

    self.mapView.callout.color = [UIColor whiteColor];
    
    self.mapView.callout.layer.shadowColor = RGBCOLOR(153, 153, 153, 1).CGColor;
    self.mapView.callout.layer.shadowOffset = CGSizeMake(0,1);
    self.mapView.callout.layer.shadowOpacity = 1;
    self.mapView.callout.layer.shadowRadius = 3;
    self.mapView.callout.layer.cornerRadius = 2;
    
}

/**
 点击定位
 
 @param sender 点位Btn
 */
- (void)LocationClick:(UIButton *)sender{
    
    [self.mapView setViewpointScale:10000 completion:nil];
    
    [self.mapView.locationDisplay.dataSource startWithCompletion:nil];//实现定位
    self.mapView.locationDisplay.autoPanMode = AGSLocationDisplayAutoPanModeRecenter;
    
}

/**
 地图类型切换
 
 @param sender 地图类型Btn
 */
- (void)MapTypeClick:(UIButton *)sender{
    
    self.mapTypeBtnView.hidden = !self.mapTypeBtnView.hidden;
    
}

- (void)BtnIsClick:(UIButton *)sender{
    
    sender.selected = !sender.selected;
    
    for (UIView * v in [self.view subviews]) {
        
        if([v isKindOfClass:[UIButton class]]){
            ///   判断是否选中，是否同一组
            
            if (![((UIButton *)v).OperationType isEqualToString:sender.OperationType]) {
                if (((UIButton *)v).OperationGroup == sender.OperationGroup) {
                    
                    if (((UIButton *)v).selected) {
                        [self.polyline removeObjectForKey:((UIButton *)v).OperationType];
                        ((UIButton *)v).selected = NO;
                    }
                    
                }else{
                    
                }
                
            }else{
                
            }
            
        }
    }
    
    if (sender.selected) {
        
        if(sender.OperationType == ZXYMapViewOperationTypeLine){
            
            [self.mapView.callout dismiss];
            
            [self MeasuringLengthClick:sender];
            
        }else if (sender.OperationType == ZXYMapViewOperationTypeArea){
            
            [self.mapView.callout dismiss];
            
            [self MeasuringAreaClick:sender];
            
        }else{
            
        }
        
    }else{
        
        [self.polyline removeObjectForKey:sender.OperationType];
        
    }
    
}

/**
 绘制长度
 
 @param sender 长度Btn
 */
- (void)MeasuringLengthClick:(UIButton *)sender{
    
    __weak typeof(GISMapTool) *weakSelf = self.polyline;

    [self.polyline createPolyline:self.mapView];

    self.polyline.PolylineBuilderBlock = ^(AGSPolylineBuilder *polylineBuilder) {

        __strong typeof(GISMapTool) *strongBlock = weakSelf;

        double distance = [GISMapTool MeasureDistanceOnTheMapView:polylineBuilder];

        if(distance > 1000){

            [strongBlock resultTextSymbol:[NSString stringWithFormat:@"%.2f千米",distance / 1000]];

        }else{

            [strongBlock resultTextSymbol:[NSString stringWithFormat:@"%.2f米",distance]];

        }

    };
    
    
}

/**
 绘制面积
 
 @param sender 面积Btn
 */
- (void)MeasuringAreaClick:(UIButton *)sender{
    

    __weak typeof(GISMapTool) *weakSelf = self.polyline;

    [self.polyline createPolygons:self.mapView];

    self.polyline.PolygonsBuilderBlock = ^(AGSPolygonBuilder *polyBuilder) {

        __strong typeof(GISMapTool) *strongBlock = weakSelf;

        double area = [GISMapTool MeasureAreaOnTheMapView:polyBuilder];

        if(area>10000){

            [strongBlock resultTextSymbol:[NSString stringWithFormat:@"%.2f公顷",area/10000]];

        }else{
            [strongBlock resultTextSymbol:[NSString stringWithFormat:@"%.2f平方米",area]];

        }


    };
    
}

/**
 气泡详情
 
 @param sender  气泡详情Btn
 */
- (void)DetailBtnClick:(UIButton *)sender{
    
    NSLog(@"点击详情");

}

/**
 气泡左按钮
 
 @param sender   气泡左按钮Btn
 */
- (void)LeftBtnClick:(UIButton *)sender{
    
    if (self.featureIndex == 0) {
        
        self.featureIndex = self.featureArr.count - 1;
        
    }else{
        
        self.featureIndex--;
    }
    
    AGSFeature *field = self.featureArr[self.featureIndex];
    
    self.titleLabel.text = field.attributes[@"YQMC"];
    
    [self isClickUniqueLineSymbol:field];
    
}

/**
 气泡右按钮
 
 @param sender  气泡右按钮Btn
 */
- (void)RightBtnClick:(UIButton *)sender{
    
    if (self.featureIndex == self.featureArr.count - 1) {
        
        self.featureIndex = 0;
        
    }else{
        
        self.featureIndex++;
    }
    
    AGSFeature *field = self.featureArr[self.featureIndex];

    self.titleLabel.text = field.attributes[@"YQMC"];

    [self isClickUniqueLineSymbol:field];
    
}

/**
 气泡导航
 
 @param sender  气泡导航Btn
 */
- (void)NavigationBtnClick:(UIButton *)sender{
    
    NSLog(@"点击导航");
}

- (AGSMapView *)mapView{
    
    if (!_mapView) {
        
        _mapView = [[AGSMapView alloc]init];
        
        _mapView.callout.delegate = self;
        _mapView.touchDelegate = self;
        
        [_mapView setAttributionTextVisible:NO];//去掉logo
        
        _mapView.interactionOptions.rotateEnabled = false; // 禁用地图旋转

    }
    return _mapView;
}


- (UIButton *)locationBtn{
    
    if (!_locationBtn) {
        _locationBtn = [[UIButton alloc]init];
        [_locationBtn setImage:[UIImage imageNamed:@"定位"] forState:UIControlStateNormal];
        
        [_locationBtn addTarget:self action:@selector(LocationClick:) forControlEvents:UIControlEventTouchUpInside];
        
    }
    
    return _locationBtn;
}

- (UIButton *)MapTypeBtn{
    if (!_MapTypeBtn) {
        _MapTypeBtn = [[UIButton alloc]init];
        [_MapTypeBtn setImage:[UIImage imageNamed:@"地图切换"] forState:UIControlStateNormal];
        
        [_MapTypeBtn addTarget:self action:@selector(MapTypeClick:) forControlEvents:UIControlEventTouchUpInside];
        
    }
    
    return _MapTypeBtn;
}

- (MapTypeView *)mapTypeBtnView{
    
    if (!_mapTypeBtnView) {
        _mapTypeBtnView = [[MapTypeView alloc]init];
        _mapTypeBtnView.hidden = YES;
        
        __weak __typeof(self)weakSelf = self;
        
        _mapTypeBtnView.MapTypeBtnBlock = ^(NSInteger selsecTag) {
            
            __strong typeof(self) strongBlock = weakSelf;
            
            strongBlock.mapTypeBtnView.hidden = YES;
            
            if (weakSelf.selsecTag != selsecTag) {
                
//                if (!NET_CAN_USE) {
//
//                }else{
                
                    [strongBlock.map.basemap.baseLayers setArray:[weakSelf.TDT_typeDic objectForKey:@(selsecTag)]];
                    
//                }
                
            }
            strongBlock.selsecTag = selsecTag;
            
        };
    }
    
    return _mapTypeBtnView;
}

- (UIButton *)MeasuringLengthBtn{
    
    if (!_MeasuringLengthBtn) {
        _MeasuringLengthBtn = [[UIButton alloc]init];
        _MeasuringLengthBtn.OperationType = ZXYMapViewOperationTypeLine;
        _MeasuringLengthBtn.OperationGroup = @(1);
        [_MeasuringLengthBtn setImage:[UIImage imageNamed:@"测量"] forState:UIControlStateNormal];
        [_MeasuringLengthBtn setImage:[UIImage imageNamed:@"测量-1"] forState:UIControlStateSelected];
        
        [_MeasuringLengthBtn addTarget:self action:@selector(BtnIsClick:) forControlEvents:UIControlEventTouchUpInside];
        
    }
    
    return _MeasuringLengthBtn;
}

- (UIButton *)MeasuringAreaBtn{
    
    if (!_MeasuringAreaBtn) {
        
        _MeasuringAreaBtn = [[UIButton alloc]init];
        _MeasuringAreaBtn.OperationType = ZXYMapViewOperationTypeArea;
        _MeasuringAreaBtn.OperationGroup = @(1);
        [_MeasuringAreaBtn setImage:[UIImage imageNamed:@"面积测量"] forState:UIControlStateNormal];
        [_MeasuringAreaBtn setImage:[UIImage imageNamed:@"面积测量-1"] forState:UIControlStateSelected];
        
        [_MeasuringAreaBtn addTarget:self action:@selector(BtnIsClick:) forControlEvents:UIControlEventTouchUpInside];
        
        
    }
    
    return _MeasuringAreaBtn;
}

- (UIView *)calloutView{
    
    if (!_calloutView) {
        _calloutView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, 220, 70)];
        
    }
    
    return _calloutView;
}

- (UIButton *)leftBtn{
    
    if (!_leftBtn) {
        _leftBtn = [[UIButton alloc]init];
        [_leftBtn setImage:[UIImage imageNamed:@"左"] forState:UIControlStateNormal];
        [_leftBtn addTarget:self action:@selector(LeftBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    }
    
    return _leftBtn;
}

- (UIButton *)rightBtn{
    
    if (!_rightBtn) {
        _rightBtn = [[UIButton alloc]init];
        [_rightBtn setImage:[UIImage imageNamed:@"右"] forState:UIControlStateNormal];
        [_rightBtn addTarget:self action:@selector(RightBtnClick:) forControlEvents:UIControlEventTouchUpInside];
        
        
    }
    
    return _rightBtn;
}

- (UIButton *)NavigationBtn{
    
    if (!_NavigationBtn) {
        _NavigationBtn = [[UIButton alloc]init];
        [_NavigationBtn addTarget:self action:@selector(NavigationBtnClick:) forControlEvents:UIControlEventTouchUpInside];
        
        _NavigationBtn.backgroundColor = [UIColor colorWithRed:10/255.0 green:93/255.0 blue:240/255.0 alpha:1.0];
        _NavigationBtn.layer.cornerRadius = 2;
        [_NavigationBtn setImage:[UIImage imageNamed:@"导航"] forState:UIControlStateNormal];
        
    }
    
    return _NavigationBtn;
}

- (UIButton *)DetailBtn{
    
    if (!_DetailBtn) {
        _DetailBtn = [[UIButton alloc]init];
        [_DetailBtn addTarget:self action:@selector(DetailBtnClick:) forControlEvents:UIControlEventTouchUpInside];
        _DetailBtn.titleLabel.font = [UIFont systemFontOfSize:11];
        [_DetailBtn setTitleColor:RGBCOLOR(38, 59, 166, 1) forState:UIControlStateNormal];
        [_DetailBtn setTitle:@"查看详情" forState:UIControlStateNormal];
        
    }
    
    return _DetailBtn;
}

- (UILabel *)titleLabel{
    
    if (!_titleLabel) {
        _titleLabel = [[UILabel alloc]init];
        _titleLabel.numberOfLines = 2;
        _titleLabel.textAlignment = NSTextAlignmentCenter;
        _titleLabel.text = @"无锡尚品食品有限公司";
        _titleLabel.font = [UIFont systemFontOfSize:12];
    }
    
    return _titleLabel;
}

@end
