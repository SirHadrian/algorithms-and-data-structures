#include "timer.h"

bool
timer_done(Timer *timer, double present_time)
{
  return present_time - timer->starttime >= timer->lifetime;
}

void start_timer(Timer *timer, double start, double lifetime)
{
  timer->starttime = start;
  timer->lifetime = lifetime;
  return;
}
