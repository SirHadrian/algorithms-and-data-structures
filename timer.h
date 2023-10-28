#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>

typedef struct {
  double starttime;
  double lifetime;
} Timer;

void start_timer(Timer *timer, double start, double lifetime);
bool timer_done(Timer *timer, double present_time);

#endif /* TIMER_H */
