#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "queue.h"

Queue *create_queue(int len) {
  Queue *que = malloc(sizeof(Queue));
  if (que != NULL) {
    que->front = 0;
    que->rear = 0;
    que->length = len;
    que->buffer = malloc(sizeof(int) * (len+1));
    if (que->buffer == NULL) {
      free(que);
      return NULL;
    }
  } else {
    exit(EXIT_FAILURE);
  }
  return que;
}

void enqueue(Queue *q, int d) {
  if ((q->rear + 1) % (q->length + 1) == q->front) {
    printf("Queue Overflow !!\n");
    exit(EXIT_FAILURE);
  }
  q->buffer[q->rear] = d;
  q->rear += 1;

  if (q->rear == q->length + 1) {
    q->rear = 0;
  }
}

int dequeue(Queue *q) {
  if (q->front == q->rear) {
    printf("Queue Underflow !!\n");
    exit(EXIT_FAILURE);
  } else {
    int x = q->buffer[q->front];
    q->front += 1;
    if (q->front == q->length + 1) {
      q->front = 0;
    }
    return x;
  }
}

void display_queue(Queue *q) {
  int x = q->front;

  if (x == q->rear) {
    printf("Nothing to display\n");
    return;
  }

  while (x % (q->length + 1) != q->rear) {
    printf("%d ", q->buffer[x % (q->length + 1)]);
    x++;
  }
  printf("\n");
}

void delete_queue(Queue *q) {
  free(q->buffer);
  free(q);
}
