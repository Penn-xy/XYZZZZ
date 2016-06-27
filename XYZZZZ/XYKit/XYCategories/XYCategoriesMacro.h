//
//  XYCategoriesMacro.m
//  XYKit
//
//  Created by Yupeng on 16/6/4.
//  Copyright © 2016年 Yupeng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <sys/time.h>
#import <pthread.h>

#ifndef XYCategoriesMacro_h
#define XYCategoriesMacro_h

#ifdef __cplusplus
#define XY_EXTERN_C_BEGIN  extern "C" {
#define XY_EXTERN_C_END  }
#else
#define XY_EXTERN_C_BEGIN
#define XY_EXTERN_C_END
#endif

XY_EXTERN_C_BEGIN


#ifndef XY_CLAMP // return the clamped value
#define XY_CLAMP(_x_, _low_, _high_)  (((_x_) > (_high_)) ? (_high_) : (((_x_) < (_low_)) ? (_low_) : (_x_)))
#endif

#ifndef XY_SWAP // swap two value
#define XY_SWAP(_a_, _b_)  do { __typeof__(_a_) _tmp_ = (_a_); (_a_) = (_b_); (_b_) = _tmp_; } while (0)
#endif

#define XYAssertNil(condition, description, ...) NSAssert(!(condition), (description), ##__VA_ARGS__)
#define XYCAssertNil(condition, description, ...) NSCAssert(!(condition), (description), ##__VA_ARGS__)

#define XYAssertNotNil(condition, description, ...) NSAssert((condition), (description), ##__VA_ARGS__)
#define XYCAssertNotNil(condition, description, ...) NSCAssert((condition), (description), ##__VA_ARGS__)

#define XYAssertMainThread() NSAssert([NSThread isMainThread], @"This method must be called on the main thread")
#define XYCAssertMainThread() NSCAssert([NSThread isMainThread], @"This method must be called on the main thread")


#ifndef XYSYNTH_DUMMY_CLASS
#define XYSYNTH_DUMMY_CLASS(_name_) \
@interface XYSYNTH_DUMMY_CLASS_ ## _name_ : NSObject @end \
@implementation XYSYNTH_DUMMY_CLASS_ ## _name_ @end
#endif


#ifndef XYSYNTH_DYNAMIC_PROPERTY_OBJECT
#define XYSYNTH_DYNAMIC_PROPERTY_OBJECT(_getter_, _setter_, _association_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_ ## _association_); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
return objc_getAssociatedObject(self, @selector(_setter_:)); \
}
#endif


#ifndef XYSYNTH_DYNAMIC_PROPERTY_CTYPE
#define XYSYNTH_DYNAMIC_PROPERTY_CTYPE(_getter_, _setter_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
NSValue *value = [NSValue value:&object withObjCType:@encode(_type_)]; \
objc_setAssociatedObject(self, _cmd, value, OBJC_ASSOCIATION_RETAIN); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (type)_getter_ { \
_type_ cValue = { 0 }; \
NSValue *value = objc_getAssociatedObject(self, @selector(_setter_:)); \
[value getValue:&cValue]; \
return cValue; \
}
#endif


#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif


static inline NSRange XYNSRangeFromCFRange(CFRange range) {
    return NSMakeRange(range.location, range.length);
}


static inline CFRange XYCFRangeFromNSRange(NSRange range) {
    return CFRangeMake(range.location, range.length);
}


static inline CFTypeRef XYCFAutorelease(CFTypeRef CF_RELEASES_ARGUMENT arg) {
    if (((long)CFAutorelease + 1) != 1) {
        return CFAutorelease(arg);
    } else {
        id __autoreleasing obj = CFBridgingRelease(arg);
        return (__bridge CFTypeRef)obj;
    }
}


static inline void XYBenchmark(void (^block)(void), void (^complete)(double ms)) {
    // <QuartzCore/QuartzCore.h> version
    /*
     extern double CACurrentMediaTime (void);
     double begin, end, ms;
     begin = CACurrentMediaTime();
     block();
     end = CACurrentMediaTime();
     ms = (end - begin) * 1000.0;
     complete(ms);
     */
    
    // <sys/time.h> version
    struct timeval t0, t1;
    gettimeofday(&t0, NULL);
    block();
    gettimeofday(&t1, NULL);
    double ms = (double)(t1.tv_sec - t0.tv_sec) * 1e3 + (double)(t1.tv_usec - t0.tv_usec) * 1e-3;
    complete(ms);
}


static inline NSDate *_XYCompileTime(const char *data, const char *time) {
    NSString *timeStr = [NSString stringWithFormat:@"%s %s",data,time];
    NSLocale *locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US"];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"MMM dd XYXY HH:mm:ss"];
    [formatter setLocale:locale];
    return [formatter dateFromString:timeStr];
}


#ifndef XYCompileTime
// use macro to avoid compile warning when use pch file
#define XYCompileTime() _XYCompileTime(__DATE__, __TIME__)
#endif


static inline dispatch_time_t dispatch_time_delay(NSTimeInterval second) {
    return dispatch_time(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC));
}

static inline dispatch_time_t dispatch_walltime_delay(NSTimeInterval second) {
    return dispatch_walltime(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC));
}

static inline dispatch_time_t dispatch_walltime_date(NSDate *date) {
    NSTimeInterval interval;
    double second, subsecond;
    struct timespec time;
    dispatch_time_t milestone;
    
    interval = [date timeIntervalSince1970];
    subsecond = modf(interval, &second);
    time.tv_sec = second;
    time.tv_nsec = subsecond * NSEC_PER_SEC;
    milestone = dispatch_walltime(&time, 0);
    return milestone;
}

static inline bool dispatch_is_main_queue() {
    return pthread_main_np() != 0;
}

static inline void dispatch_async_on_main_queue(void (^block)()) {
    if (pthread_main_np()) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

static inline void dispatch_sync_on_main_queue(void (^block)()) {
    if (pthread_main_np()) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
}

static inline void pthread_mutex_init_recursive(pthread_mutex_t *mutex, bool recursive) {
#define XYMUTEX_ASSERT_ON_ERROR(x_) do { \
__unused volatile int res = (x_); \
assert(res == 0); \
} while (0)
    assert(mutex != NULL);
    if (!recursive) {
        XYMUTEX_ASSERT_ON_ERROR(pthread_mutex_init(mutex, NULL));
    } else {
        pthread_mutexattr_t attr;
        XYMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_init (&attr));
        XYMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_RECURSIVE));
        XYMUTEX_ASSERT_ON_ERROR(pthread_mutex_init (mutex, &attr));
        XYMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_destroy (&attr));
    }
#undef XYMUTEX_ASSERT_ON_ERROR
}

XY_EXTERN_C_END
#endif
