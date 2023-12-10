#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_collection.h"

typedef struct timer {
  double seconds;
  double ref;
  void (*reset)(struct timer *this_timer);
  void (*start)(struct timer *this_timer);
  void (*stop)(struct timer *this_timer);
  void (*display)(struct timer *this_timer);
  double (*result)(struct timer *this_timer);
} Timer;

void timer_reset(Timer *this_timer) {
  this_timer->seconds = 0.0;
  this_timer->ref = 0.0;
  printf("Timer reset\n");
  struct timespec ts;
  clock_getres(CLOCK_MONOTONIC, &ts);
  printf("Time precision:\t%ld.%09ld sec\n", (long)ts.tv_sec, ts.tv_nsec);
}

void timer_start(Timer *this_timer) {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  this_timer->ref = (double)(ts.tv_sec) + (double)ts.tv_nsec*1e-9;
}

void timer_stop(Timer *this_timer) {
  this_timer->seconds -= this_timer->ref;
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  this_timer->ref = (double)(ts.tv_sec) + (double)ts.tv_nsec*1e-9;
  this_timer->seconds += this_timer->ref;
}

void timer_display(Timer *this_timer) {
  printf("Elapsed time: \t%lf sec\n", this_timer->seconds);
}

double timer_result(Timer *this_timer) {
  return this_timer->seconds;
}

int GetRandom(int min, int max) {
  return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int main(int argc, char *argv[]) {
  Timer stop_watch = {
    0.0,
    0.0,
    timer_reset,
    timer_start,
    timer_stop,
    timer_display,
    timer_result
  };

  int numdata;
  for (numdata = 1000000; numdata <= 10000000; numdata += 1000000) {  // numdata is 1000000, 2000000, ..., 10000000
    int *array = (int*)malloc(sizeof(int) * numdata);
    int i;
    for (i = 0; i < numdata; i++) {
      array[i] = GetRandom(0, (numdata * 10 - 1));  // random number from 0 to numdata * 10 - 1
    }
    stop_watch.reset(&stop_watch);
    stop_watch.start(&stop_watch);
    // heap_sort(array, numdata);
    q_sort(array, numdata);
    printf("%d %lu\n", numdata, compare_count);
    stop_watch.stop(&stop_watch);
    stop_watch.display(&stop_watch);
    cmp_cnt_reset();
    free(array);
  }
  return EXIT_SUCCESS;
}