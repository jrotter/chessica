#include "timer.h"

/// Constructor for a Timer
///
/// Initializes and resets a timer
///
Timer::Timer() 
{ 			//constructor
  Reset();
}

/// Get the current time
///
/// @returns curent time in microseconds
///
TimerType Timer::CurrentTime()
{
  timeval current_time;
  gettimeofday(&current_time, (struct timezone *) 0);
  return current_time.tv_sec*1000000+current_time.tv_usec;
}

/// Reset the Timer
///
/// Sets the Timer value to the current time (in microseconds)
///
void Timer::Reset()
{
  timerval = CurrentTime();
}

/// Get the elapsed time since the Timer was set (or initialized)
///
/// @returns the number of microseconds that have have elapsed since timer 
/// was last reset or initialized
///
TimerType Timer::ElapsedTime()
{
  return(CurrentTime() - timerval);
}
  


