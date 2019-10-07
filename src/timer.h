#ifndef timer_h__
#define timer_h__

#include <time.h>

typedef unsigned long int TimerType;


class Timer {

  TimerType timerval;

public:
  Timer();
  void Reset();
  TimerType ElapsedTime();
};

#endif  //timer_h__
