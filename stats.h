#ifndef STATS_H
#define STATS_H

struct Stats {
  float average;
  float min;
  float max;
};

extern struct Stats compute_statistics( float* numberset, int setlength);

typedef void (*alerter_funcptr)();
extern void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern void emailAlerter (void);
extern void ledAlerter (void);

extern int emailAlertCallCount;
extern int ledAlertCallCount;

#endif
