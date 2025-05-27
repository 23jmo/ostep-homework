#include "pingpong.h"
#include <pthread.h>
#include "common_threads.h"
#include <stdio.h>

// increment a shared counter - when this counter is even, ping is allowed to print, odd then pong is allowed to print
// actually that doesn't work - need a counter and a condition variable probably 


//Note: this implementation wastes hella cpu cycles since i'm not properly waiting with pthread_cond_wait

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void *ping(void *arg){
  while(1){
    Pthread_mutex_lock(&m1);
    // critical section
    if (count >= 10) {
      pthread_mutex_unlock(&m1);
      return NULL;
    }
    if (count % 2 == 0){
      printf("%s\n", "ping");
      count += 1;
    }
    Pthread_mutex_unlock(&m1);
  }
  return NULL;
}

void *pong(void *arg){
  while(1){
    Pthread_mutex_lock(&m1);
    // critical section
    if (count >= 10) {
      pthread_mutex_unlock(&m1);
      return NULL;
    }
    if (count % 2 == 1){
      printf("%s\n", "pong");
      count += 1;
    }
    Pthread_mutex_unlock(&m1);
  }
  return NULL;
}

int main(){
  // create the locks

  pthread_t t1;
  pthread_t t2;
  

  pthread_mutex_init(&m1, NULL);

  pthread_create(&t1, NULL, *ping, NULL);
  pthread_create(&t2, NULL, *pong, NULL);

  // check the counter = 10
  while(1){
    Pthread_mutex_lock(&m1);

    // critical section
    if(count == 10){
      pthread_join(t1, NULL);
      pthread_join(t2, NULL);
      break;
    }

    Pthread_mutex_unlock(&m1);
  }


}