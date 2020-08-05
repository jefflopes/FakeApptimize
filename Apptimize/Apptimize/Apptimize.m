//
//  Apptimize.m
//  Apptimize
//
//  Created by Jeff Lopes on 8/5/20.
//  Copyright © 2020 Change Collective. All rights reserved.
//

#import "Apptimize.h"

NSString *const ApptimizeTestsProcessedNotification = @"ApptimizeTestsProcessedNotification";
NSString *const ApptimizeDevicePairingOption = @"ApptimizeDevicePairingOption";

@implementation Apptimize
+ (void)track:(nonnull NSString *)eventName {}
+ (void)setUserAttributeString:(nonnull NSString *)attributeValue forKey:(nonnull NSString *)attributeName {}
+ (nullable NSDictionary<NSString*,id<ApptimizeTestInfo>>*)testInfo { return nil; }
+ (void)setUserAttributeBool:(BOOL)attributeValue forKey:(nonnull NSString *)attributeName {}
+ (BOOL)waitForTestsToBecomeAvailable:(NSTimeInterval)timeout { return YES; }
+ (void)startApptimizeWithApplicationKey:(nullable NSString *)applicationKey options:(nullable NSDictionary<NSString*,id> *)options {}
@end

@implementation ApptimizeVariable
+ (ApptimizeVariableString* _Nullable)stringWithName:(NSString* _Nonnull)name andDefaultString:(NSString* _Nonnull)defaultString { return nil; }
+ (ApptimizeVariableString* _Nullable)getStringForName:(NSString* _Nonnull)name { return nil; }
+ (ApptimizeVariableArray<NSString*>* _Nullable)stringArrayWithName:(NSString* _Nonnull)name andDefaultArray:(NSArray<NSString*>* _Nonnull)defaultStringArray { return nil; }
+ (ApptimizeVariableArray<NSString*>* _Nullable)getStringArrayForName:(NSString* _Nonnull)name { return nil; }
+ (ApptimizeVariableBool* _Nullable)boolWithName:(NSString* _Nonnull)name andDefaultBool:(BOOL)defaultBool { return nil; }
+ (ApptimizeVariableBool* _Nullable)getBoolForName:(NSString* _Nonnull)name { return nil; }
+ (ApptimizeVariableInteger* _Nullable)integerWithName:(NSString* _Nonnull)name andDefaultInteger:(NSInteger)defaultInteger { return nil ; }
+ (ApptimizeVariableInteger* _Nullable)getIntegerForName:(NSString* _Nonnull)name { return nil; }
@end

@implementation ApptimizeVariableString
@synthesize stringValue;
@end

@implementation ApptimizeVariableArray
@synthesize arrayValue;
@end

@implementation ApptimizeVariableBool
@synthesize boolValue;
@end

@implementation ApptimizeVariableInteger
@synthesize integerValue;
@synthesize unsignedIntegerValue;
@end
