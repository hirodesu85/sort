#ifndef INCLUDE_GUARD_SORT_COLLECTION_H
#define INCLUDE_GUARD_SORT_COLLECTION_H

extern unsigned long compare_count;

void cmp_cnt_reset(void);
void display(int a[], int n);
void selection_sort(int a[], int n);
void insertion_sort(int a[], int n);
void heap_sort(int a[], int n);
void q_sort(int a[], int n);

#endif  // INCLUDE_GUARD_SORT_COLLECTION_H