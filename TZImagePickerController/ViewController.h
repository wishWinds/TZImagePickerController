//
//  ViewController.h
//  TZImagePickerController
//
//  Created by 谭真 on 15/12/24.
//  Copyright © 2015年 谭真. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <sys/time.h>

static inline void YYBenchmark(void (^block)(void), void (^complete)(double ms)) {
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

@interface ViewController : UIViewController



@end

