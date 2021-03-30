#include <stdio.h>

/**
 *Consider the problem of adding two n-bit binary integers, 
 *stored in two n-element array A and B. 
 *The sum of the two integers should be stored in binary form in an 
 *(n+1)-element array C. 
 *State the problem formally and write pseudocode for adding the two integers.
 ****************************************************************************
 *This program reads the binary integers with spaces.
 ****************************************************************************
 *Example:
 *n = 3
 *A:   1 0 1 = 5_{10}
 *B:   0 1 0 = 2_{10}
 *C: 0 1 1 1 = 7_{10}
*/

void two_bit_add(int A[], int B[], int C[], int n);
int binary_add(int a, int b, int aux[]);
void print_C(int C[], int n);

void main(int argc, char *argv[]){
  int n;
  printf("n:");
  scanf("%d", &n);

  int A[n-1];
  int B[n-1];
  int C[n];
  
  printf("A:   ");
  for(int i = n - 1; i >= 0; i--)
    scanf("%d", &A[i]);

  printf("B:   ");
  for(int i = n - 1; i >= 0; i--)
    scanf("%d", &B[i]);
  
  two_bit_add(A, B, C, n);
  print_C(C, n);
}

void two_bit_add(int A[], int B[], int C[], int n){
  int aux[1] = {0};

  for(int i = 0; i < n; i++)
    C[i] = binary_add(A[i], B[i], aux);
  C[n] = aux[0];
}

/**
 * binary_add: returns the binary number result of adding the two binary number
 *            received and saves the carrying on the aux array. 
 *
 * @param a,b: binary numbers.
 * @param aux[] : array of length one, used for the add carrying.
 * @return returns the binary number result of adding a and b.
 */
int binary_add(int a, int b, int aux[]){
  /*if(a + b + aux[0] == 0){
    aux[0] = 0;
    return 0;
  }
  if(a + b + aux[0] == 1){
    aux[0] = 0;
    return 1;
  }
  if(a + b + aux[0] == 2){
    aux[0] = 1;
    return 0;
  }
  if(a + b + aux[0] == 3){
    aux[0] = 1;
    return 1;
    }  */
  
  int sum = a + b + aux[0];
  
  if(sum >= 2)
    aux[0] = 1;
  else aux[0] = 0;
    
  if(sum == 2)
    return 0;
  
  return 1;
}

/**
 * print_C: prints on the console the array with the result of the 
            two_binary_add.
 */
void print_C(int C[], int n){
  printf("C: ");
  
  for(int i = n; i >= 0; i--)
    printf("%d ",C[i]);
  
  printf("\n");
}x
