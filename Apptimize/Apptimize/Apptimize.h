//
//  Apptimize.h
//  Apptimize
//
//  Created by Jeff Lopes on 8/5/20.
//  Copyright © 2020 Change Collective. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for Apptimize.
FOUNDATION_EXPORT double ApptimizeVersionNumber;

//! Project version string for Apptimize.
FOUNDATION_EXPORT const unsigned char ApptimizeVersionString[];

#ifndef APPTIMIZE_EXTERN
#define APPTIMIZE_VISIBLE __attribute__((visibility("default")))
#define APPTIMIZE_EXTERN APPTIMIZE_VISIBLE extern
#endif

NS_ASSUME_NONNULL_BEGIN
APPTIMIZE_EXTERN NSString *const ApptimizeTestsProcessedNotification;
APPTIMIZE_EXTERN NSString *const ApptimizeDevicePairingOption;
NS_ASSUME_NONNULL_END

@protocol ApptimizeTestInfo;

APPTIMIZE_VISIBLE @interface Apptimize : NSObject
+ (void)track:(nonnull NSString *)eventName;
+ (void)setUserAttributeString:(nonnull NSString *)attributeValue forKey:(nonnull NSString *)attributeName;
+ (nullable NSDictionary<NSString*,id<ApptimizeTestInfo>>*)testInfo;
+ (void)setUserAttributeBool:(BOOL)attributeValue forKey:(nonnull NSString *)attributeName;
+ (BOOL)waitForTestsToBecomeAvailable:(NSTimeInterval)timeout;
+ (void)startApptimizeWithApplicationKey:(nullable NSString *)applicationKey options:(nullable NSDictionary<NSString*,id> *)options;
@end

@class ApptimizeVariableString;
@class ApptimizeVariableBool;
@class ApptimizeVariableInteger;
@class ApptimizeVariableArray<__covariant ContainedType>;

@interface ApptimizeVariable : NSObject
+ (ApptimizeVariableString* _Nullable)stringWithName:(NSString* _Nonnull)name andDefaultString:(NSString* _Nonnull)defaultString
    NS_SWIFT_NAME(makeString(name:defaultString:));
+ (ApptimizeVariableString* _Nullable)getStringForName:(NSString* _Nonnull)name
    NS_SWIFT_NAME(getString(name:));
+ (ApptimizeVariableArray<NSString*>* _Nullable)stringArrayWithName:(NSString* _Nonnull)name andDefaultArray:(NSArray<NSString*>* _Nonnull)defaultStringArray
    NS_SWIFT_NAME(makeStringArray(name:defaultStringArray:));
+ (ApptimizeVariableArray<NSString*>* _Nullable)getStringArrayForName:(NSString* _Nonnull)name
    NS_SWIFT_NAME(getStringArray(name:));
+ (ApptimizeVariableBool* _Nullable)boolWithName:(NSString* _Nonnull)name andDefaultBool:(BOOL)defaultBool
    NS_SWIFT_NAME(makeBool(name:defaultBool:));
+ (ApptimizeVariableBool* _Nullable)getBoolForName:(NSString* _Nonnull)name
    NS_SWIFT_NAME(getBool(name:));
+ (ApptimizeVariableInteger* _Nullable)integerWithName:(NSString* _Nonnull)name andDefaultInteger:(NSInteger)defaultInteger
    NS_SWIFT_NAME(makeInteger(name:defaultInteger:));
+ (ApptimizeVariableInteger* _Nullable)getIntegerForName:(NSString* _Nonnull)name
    NS_SWIFT_NAME(getInteger(name:));
@end

@interface ApptimizeVariableString : ApptimizeVariable
@property (nonatomic, readonly) NSString* _Nullable stringValue;
@end

@interface ApptimizeVariableArray<__covariant ContainedType> : ApptimizeVariable
@property (nonatomic, readonly) NSArray<ContainedType>* _Nullable arrayValue;
@end

@interface ApptimizeVariableBool : ApptimizeVariable
@property (nonatomic, readonly) BOOL boolValue;
@end

@interface ApptimizeVariableInteger : ApptimizeVariable
@property (nonatomic, readonly) NSInteger integerValue;
@property (nonatomic, readonly) NSUInteger unsignedIntegerValue;
@end

typedef NS_ENUM(NSInteger, ExperimentType)
{
    ExperimentTypeCodeBlock,
    ExperimentTypeFeatureFlag,
    ExperimentTypeDynamicVariables,
    ExperimentTypeVisual,
    ExperimentTypeUnknown,
};

@protocol ApptimizeTestInfo <NSObject>
- (nonnull NSString *)testName;
- (nonnull NSString *)enrolledVariantName;
- (nonnull NSNumber *)testID;
- (nonnull NSNumber *)enrolledVariantID;
- (nonnull NSDate *)testStartedDate;
- (nonnull NSDate *)testEnrolledDate;
- (nonnull NSNumber *)cycle;
- (nonnull NSNumber *)currentPhase;
- (nonnull NSNumber *)participationPhase;
- (BOOL)userHasParticipated;
- (nullable NSString *)userID;
- (nonnull NSString *)anonymousUserID;
- (ExperimentType)experimentType;
@end
