#include <stdio.h>

void selection_sort(int a[], int n);
void change(int a[], int b, int c);
void main(){
  int n;
  
  printf("n: ");
  scanf("%d", &n);

  int a[n];
  
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  selection_sort(a, n);

  for(int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void selection_sort(int a[], int n){
  int smallest;
  int k;
  
  for(int i = 0; i < n - 1; i++){
    smallest = a[i];
    k = i;
    for(int j = i+1; j < n; j++)
      if(a[j] < smallest){
	smallest = a[j];
	k = j;
      }
    if(i != k)
      change(a, i, k);
  }
}

void change(int a[], int b, int c){
  int aux = a[b];
  a[b] = a[c];
  a[c] = aux;
}
