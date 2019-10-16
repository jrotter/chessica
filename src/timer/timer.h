#ifndef timer_h__
#define timer_h__

#include <sys/time.h>

typedef unsigned long int TimerType;


class Timer {

  TimerType timerval;

private:
  TimerType CurrentTime();

public:
  Timer();
  void Reset();
  TimerType ElapsedTime();
};

#endif  //timer_h__
