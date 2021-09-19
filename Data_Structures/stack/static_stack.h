#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * static int stack implementation
 */

/* static stack struct representation*/
struct Stack{
  int sp;                   // next free space in the stack
  unsigned int MAXLENGTH;   // size of the array
  int* array;
};

/* stalloc: creates a Stack */
struct Stack* stalloc(void)
{
  return (struct Stack *) malloc(sizeof(struct Stack));
}

/* new_stack: Stack initializer */
struct Stack* new_stack(unsigned int length)
{
  struct Stack* stack = stalloc();
  stack->MAXLENGTH = length;
  stack->sp = 0;
  stack->array = (int*)malloc(length*sizeof(int));
  return stack;
}

/* stack_empty: 1 if the Stack is empty, 0 if not */
int stack_empty(struct Stack* S)
{
  return S->sp == 0;
}

/* push: inserts an element into the Stack */
void push(struct Stack* S, int x)
{
  if(S->sp+1 > S->MAXLENGTH){
    printf("error: overflow\n");
    return;
  }
  
  S->array[S->sp++] = x;
}

/* pop: deletes and returns the top of the stack */
int pop(struct Stack* S)
{
  if(stack_empty(S)){
    printf("error: underflow\n");
    return INT_MIN;
  }
  return S->array[S->sp--];
}

/* stack_print: prints the stack */
void stack_print(struct Stack* S)
{
  int i;
  
  if(stack_empty(S)){
    printf("error: can't print empty stack\n");
    return;
  }
  
  printf("---------Stack---------\ntop:");
  for(i = S->sp-1; i >= 0; i--)
    printf("\t%d\n", S->array[i]);
  printf("-----------------------\n");
}

/* stack_clear: clears the stack */
void stack_clear(struct Stack *S)
{
  S->sp = 0;
}
