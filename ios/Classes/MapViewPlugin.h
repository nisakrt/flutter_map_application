#import <Flutter/Flutter.h>
#import <CoreLocation/CoreLocation.h>
@class MapViewController;

@class GMSCameraPosition;
@class GMSIndoorBuilding;
@class GMSIndoorLevel;

@interface MapViewPlugin : NSObject<FlutterPlugin>

@property (nonatomic, assign) UIViewController *host;
@property (nonatomic, assign) FlutterMethodChannel *channel;
@property (nonatomic, retain) MapViewController *mapViewController;
@property (nonatomic, retain) NSString *mapTitle;
@property (nonatomic, assign) int mapViewType;
@property (nonatomic, retain) NSObject <FlutterPluginRegistrar> *registrar;

- (void)onMapReady;
- (void)locationDidUpdate:(CLLocation *)location;
- (void)annotationTapped:(NSString *)identifier;
- (void)annotationDragStart:(NSString *)identifier position:(CLLocationCoordinate2D)position;
- (void)annotationDragEnd:(NSString *)identifier position:(CLLocationCoordinate2D)position;
- (void)annotationDrag:(NSString *)identifier position:(CLLocationCoordinate2D)position;
- (void)polylineTapped:(NSString *)identifier;
- (void)polygonTapped:(NSString *)identifier;
- (void)infoWindowTapped:(NSString *)identifier; 
- (void)mapTapped:(CLLocationCoordinate2D)coordinate;
- (void)mapLongTapped:(CLLocationCoordinate2D)coordinate;
- (void)cameraPositionChanged:(GMSCameraPosition *)position;
- (void)indoorBuildingActivated:(GMSIndoorBuilding *)indoorBuilding;
- (void)indoorLevelActivated:(GMSIndoorLevel *)indoorLevel;
- (NSArray<NSDictionary *> *)mappingIndoorLevels:(NSArray<GMSIndoorLevel *> *)levels;
- (NSDictionary *)mappingIndoorLevel:(GMSIndoorLevel *)level;
- (int)getMapViewType:(NSString *)mapViewTypeName;
- (NSString *)getAssetPath:(NSString *)iconPath;
@end
