#include <stdio.h>
#include "queue.h"

int main(){
  Queue* q, *p;

  q = newQueue();
  p = newQueue();
  
  enqueue(q, 10);
  enqueue(q, 20);
  QtoString(q);
  dequeue(q);
  QtoString(q);
  dequeue(q);
  QtoString(q);
  enqueue(q, 30);
  QtoString(q);

  printf("Are both queues iqual?: %d\n", Qequals(q, p));
  free(q);
  free(p);  
  return 0;
}
