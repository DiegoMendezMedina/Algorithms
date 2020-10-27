#include <stdio.h>
/*
  Consider the problem of adding two n-bit binary integers, 
  stored in two n-element array A and B. 
  The sum of the two integers should be stored in binary form in an 
  (n+1)-element array C. 
  State the problem formally and write pseudocode for adding the two integers.
*/
int suma(int a, int b);
int aux;
void main(int argc, char *argv[]){
  int n;
  printf("n:");
  scanf("%d", &n);

  int A[n];
  int B[n];
  int C[n+1];
  int j = n;
  
  printf("A:   ");
  for(int i = 0; i < n; i++)
    scanf("%d", &A[i]);
  printf("B:   ");
  for(int i = 0; i < n; i++)
    scanf("%d", &B[i]);
  aux = 0;

  //Start:
  for(int i = n-1; i >= 0; i--, j--){
    C[j] = suma(A[i], B[i]);
  }
  C[0] = aux;
  //end
  //printing the result:
  printf("C: ");
  for(int i = 0; i < n+1; i++)
    printf("%d ",C[i]);
  printf("\n");
  
}

int suma(int a, int b){
  if(a + b + aux == 2){
    aux = 1;
    return 0;
  }
  if(a + b + aux == 3){
    aux = 1;
    return 1;
  }
  if(a + b + aux == 1){
    aux = 0;
    return 1;
  }
  if( a + b + aux == 0){
    aux = 0;
    return 0;
  }
}
