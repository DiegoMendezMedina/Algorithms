#include <stdio.h>
#include "static_stack.h"

/* static stack tests*/ 
int main()
{
  int length, i, aux;
  struct Stack* stack;


  scanf("%d", &length);
  stack = new_stack(length);

  if(stack_empty(stack))
    printf("stack_empty works\n");

  printf("input:\n");
  /* filling the stack  */
  i = 0; 
  while(i < length){
    scanf("%d", &aux);
    push(stack, aux);
    i++;
  }
  stack_print(stack);
  
  /* push test, knowing stack_empty works */
  if(!stack_empty(stack)){
    printf("push works\n");
    printf("stack_empty works when the stack is not empty\n");
  }

  /* Clearing the stack with pop */
  i = 0;
  while(i < length){
    pop(stack);
    i++;
  }
  stack_print(stack);
  
  /* Pop test */
  if(stack_empty(stack))
    printf("pop works\n");

  /* filling the stack again */
  i = 0; 
  while(i < length){
    push(stack, i);
    i++;
  }
  stack_print(stack);

  /* clear test*/
  stack_clear(stack);
  stack_print(stack);
  if(stack_empty(stack))
    printf("stack_clear works\n");
  
  free(stack);
}
