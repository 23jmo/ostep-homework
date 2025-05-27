#include "pingpong.h"
#include <pthread.h>

// Here's the plan 
// 1. Create a mutex and a condition variable
// 2. Create two threads, ping and pong
// 3. In the ping thread, print "ping" and signal the condition variable
// 4. In the pong thread, wait for the condition variable and print "pong"
// 5. The main thread should wait for the two threads to finish
// 6. The main thread should run it five times

void pingpong() {
  pthread_t p; 
  int rc = pthread_create(
    &p,

  )
}