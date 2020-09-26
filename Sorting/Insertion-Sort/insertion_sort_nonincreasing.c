#include <stdio.h>

void insertionSortNonIncreasing(int array[], int n);

void main(){
  int n;
  
  printf("Size of the input: \n");
  scanf("%d",&n);
  int array[n];
  for(int i = 0; i < n; i++)
    scanf("%d", &array[i]);
  insertionSortNonIncreasing(array, n);
  printf("Output: \n");
  for (int i = 0; i < n; i++)
    printf("%d\n", array[i]);
}

void insertionSortNonIncreasing(int array[], int n){
  int key;
  int l;
  
  for(int j = n - 2; j >= 0; j--){
    key = array[j];
    //insert A[j] into the sorted sequence A[0,...,j-1].
    l = j + 1;
    while(l < n && array[l] < key){
      array[l-1] = array[l];
      l = l + 1;
    }
    array[l-1] = key;
  }
}
