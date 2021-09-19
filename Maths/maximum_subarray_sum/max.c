#include <stdio.h>

int max(int, int);
int max_sub_sum(int [], int);
  
int main()
{
  int arr[8] = {-1, 2, 4, -3, 5, 2, -5, 2};
  int array[10], i;

  /*
  for(i = 0; i < 10; i++)
    scanf("%d", &array[i]);
  */
  printf("%d\n", max_sub_sum(arr, 8));
}

int max_sub_sum(int array[], int n)
{
  int i, best, sum;

  best = sum = 0;
  for(i = 0; i < n; i++){
    sum = max(array[i], sum+array[i]);
    best = max(best, sum);
  }
  return best;
}

int max(int a, int b)
{
  if(a>b)
    return a;
  return b;
}
