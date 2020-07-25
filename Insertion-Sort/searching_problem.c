#include <stdio.h>
/* Consider the searching problem: 
   Input: A sequence of n numbers A = {a1, a2, ..., an} and a value n.
   Output: An index i such that v = A[i] or the special value N if v does not
   appear in A.
   ·Note: index in A goes from 0-n-1, given the exmaple the index from a1 is 0 
   and the one from an is n-1.
 */
char linearSearch(int A[], int v, int n);

void main(){
  int n;
  int v;
  char res;
  
  printf("n:");
  scanf("%d", &n);
  int A[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  printf("v: ");
  scanf("%d", &v);
  res = linearSearch(A, v, n);
  if(res == 'N')
    printf("Output: %c\n", res);
  else
    printf("Output: %d\n", res);
}

char linearSearch( int A[], int v, int n){
  for(int i = 0; i < n; i++){
    if(v == A[i])
      return i;
  }
  return 'N';
}
