#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "B3Node.h"

/**
 * B3Node queue implementation.
 */

/* queue node abstraction */
typedef struct QNode{
  B3Node* item;
  struct QNode* next;
} QNode;
/* queue abstraction */
typedef struct Queue{
  QNode* head;
  QNode* tail;
}Queue;

/* creates the queue node in memory*/
QNode* Qnodealloc()
{
  return (QNode*) malloc(sizeof(QNode));
}

/* creates the queue in memory */
Queue* Qalloc()
{
  return (Queue*) malloc(sizeof(Queue));
}

/**
 * newQueue: queue initializer.
 */
Queue* newQueue()
{
  Queue* q = Qalloc();
  q->head = NULL;
  q->tail = NULL;
}


/**
 * enqueue: puts elements into the queue.
 */
void enqueue(Queue* q, B3Node* item)
{
  QNode* node = Qnodealloc();
  node->item = item;
  node->next = NULL;
  
  if(q->tail == NULL){
    q->head = node;
    q->tail = node;
  }
  else{
    q->tail->next = node;
    q->tail = node;
  }
}

/**
 * dequeue: takes a element out of the
 *          queue and returns it.
 *          returns NULL if the queue is 
 *          empty.
 * DONT FORGET TO CAST
 */
void* dequeue(Queue* q)
{
  if(q->head == NULL)
    return NULL;
  B3Node* aux = q->head->item;
  
  q->head = q->head->next;
  if(q->head == NULL)
    q->tail = NULL;
  return aux;
}

/**
 * Qlength: returns the length of the queue.
 */
int Qlength(Queue* q)
{
  if(q->head == NULL)
    return 0;
  
  int cont = 0;
  QNode* n = q->head;

  while(n != NULL){
    n = n->next;
    cont++;
  }
  return cont;
}

/**
 * QtoString: prints the queue.
 */
void QtoString(Queue* q)
{
  int length, i;
  QNode* aux = q->head;
  printf("Head->");
  while(aux != NULL){
    printf("%d ", aux->item->item);
    aux = aux->next;
  }
  printf("<-Tail\n");
}

/**
 * head: returns the head of the queue,
 *       if the queue is empty returns INT_MIN.
 * DONT FORGET TO CAST
 */
void* Qhead(Queue* q)
{
  
  if(q->head == NULL)
    return NULL;
  return q->head->item;
}

/**
 * Qempty: returns 1 if the queue is empty, 0 if not.
 */
int Qempty(Queue* q)
{
  return q->head == NULL;
}

/**
 * Qequals: returns 1 if all the elements in the 
 *         first queue received are the same as the 
 *         second queue(this implies same length).
 *         returns 0 if not.
 */
int Qequals(Queue* q, Queue* p){
  QNode* qaux = q->head;
  QNode* paux = p->head;

  while(qaux != NULL && paux != NULL){
    if(qaux->item != paux->item)
      return 0;
    qaux = qaux->next;
    paux = paux->next;
  }
  
  if(qaux == NULL && paux == NULL)
    return 1;
  return 0;
}
