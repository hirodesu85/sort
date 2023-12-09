#include <stdio.h>
#include <stdlib.h>
#include "sort_collection.h"

unsigned long compare_count = 0;

void cmp_cnt_reset(void) {
  compare_count = 0;
}

int compare(int ldata, int rdata) {
  compare_count++;
  printf("Compare %d, %d\n", ldata, rdata);
  if      (ldata  < rdata) return -1;
  else if (ldata == rdata) return  0;
  else                     return  1;
}

void swap(int a[], int lidx, int ridx) {
  printf("Swap %d, %d\n", a[lidx], a[ridx]);
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
    while (j >= 0 && compare(insertion, a[j]) == -1) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = insertion;
  }
}

// Functions for Heap sort
/**************************************/
void sift_down(int a[], int i, int n) {
  int snode;
  int svalue;
  while (2*i+1 <= n-1) {
    if (2*i+1 == n-1) {
      snode = 2*i+1;
      svalue = a[2*i+1];
    } else {
      if (compare(a[2*i+1], a[2*i+2]) == 1) {
        snode = 2*i+1;
        svalue = a[2*i+1];
      } else {
        snode = 2*i+2;
        svalue = a[2*i+2];
      }
    }

    if (compare(a[i], svalue) == -1) {
      swap(a, i, snode);
      i = snode;
    } else {
      return;
    }
  }
  return;
}

void build_heap (int a[], int n) {
  for (int i = n/2 - 1; i >= 0; i--) {
    sift_down(a, i, n);
  }
}

void heap_sort (int a[], int n) {
  build_heap(a, n);
  for (int m = n-1; m > 0; m--) {
    swap(a, 0, m);
    sift_down(a, 0, m);
  }
}

// Functions for Quick sort
/**************************************/
int partition(int a[], int pivot, int left, int right) {
  swap(a, right, pivot);
  int l = left;
  int r = right - 1;
  while (1) {
    while (compare(a[l], a[right]) == -1) l++;
    while (l <= r && (compare(a[r], a[right]) != -1)) r = r - 1;
    if (l < r) swap(a, l, r);
    else break;
  }
  swap(a, l, right);
  return l;
}

void quick_sort(int a[], int left, int right) {
  if (left < right) {
    int pivot = right;
    int p = partition(a, pivot, left, right);
    quick_sort(a, left, p-1);
    quick_sort(a, p+1, right);
  }
}

void q_sort(int a[], int n) {
  quick_sort(a, 0, n-1);
}