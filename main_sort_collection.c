#include <stdio.h>
#include <stdlib.h>
#include "sort_collection.h"

int GetRandom(int min, int max) {
  return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    int numdata = atoi(argv[1]);  // set numdata with cmd. argument
    int *array = (int*)malloc(sizeof(int) * numdata);
    int i;
    printf("Enter %d integers\n", numdata);
    for (i = 0; i < numdata; i++) {
      scanf("%d", &array[i]);  // enter integers
    }
    insertion_sort(array, numdata);
    // heap_sort(array, numdata);
    // q_sort(array, numdata);
    printf("sorting result\n");
    display(array, numdata);
    printf("# of comparisons: %lu\n", compare_count);
    free(array);
  } else {
    int numdata;
    for (numdata = 1000; numdata <= 10000; numdata += 1000) {  // numdata is 1000, 2000, ..., 10,000
      int *array = (int*)malloc(sizeof(int) * numdata);
      int i;
      for (i = 0; i < numdata; i++) {
        array[i] = GetRandom(0, (numdata * 10 - 1));  // random number from 0 to numdata * 10 - 1
      }
      selection_sort(array, numdata);
      printf("%d %lu\n", numdata, compare_count);
      cmp_cnt_reset();
      free(array);
    }
  }

  return EXIT_SUCCESS;
}