#include <stdio.h>
#include <stdlib.h>
#include "sort_collection.h"

unsigned long compare_count = 0;

void cmp_cnt_reset(void) {
  compare_count = 0;
}

int compare(int ldata, int rdata) {
  compare_count++;
  if      (ldata  < rdata) return -1;
  else if (ldata == rdata) return  0;
  else                     return  1;
}

void swap(int a[], int lidx, int ridx) {
  int temp = a[lidx];
  a[lidx] = a[ridx];
  a[ridx] = temp;
}

void display(int a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void selection_sort(int a[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (compare(a[j], a[min]) == -1) {
        min = j;
      }
    }
    swap(a, i, min);
  }
}

// Insertion sort
/**************************************/
void insertion_sort(int a[], int n) {
  int insertion;
  for (int i = 0; i < n; i++) {
    insertion = a[i];
    int j = i - 1;
    while (j >= 0 && insertion < a[j]) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = insertion;
  }
}

// Functions for Heap sort
/**************************************/
void sift_down(int a[], int i, int n) { ... }

void build_heap (int a[], int n) { ... }

void heap_sort (int a[], int n) { ... }

// Functions for Quick sort
/**************************************/
int partition(int a[], int pivot, int left, int right) { ... }

void quick_sort(int a[], int left, int right) { ... }

void q_sort(int a[], int n) {
  quick_sort(a, 0, n-1);
}