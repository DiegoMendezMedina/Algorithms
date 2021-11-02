#include "binary_tree.h"

int main()
{
  int item;
  int arr[] ={1,2,3,4,5,6,7};
  B3Node * root, *busca, *busca2, *tree;
  
  scanf("%d", &item);
  
  root = new_Btree(item, NULL);
  
  root->left = new_Btree(2*item, root);
  root->right = new_Btree(2*item, root);
  
  root->left->left = new_Btree(3*item, root->left);
  //root->right->right = new_Btree(3*item, root->right);

  int h = heightB3(root);
  int d1 = depthB3(root);
  int d2 = depthB3(root->right);
		   //left->left);

  B3Node * target = new_Btree(3*item, NULL);
  B3Node * target2 = new_Btree(4*item, NULL);
  
  busca = searchB3(root, target);
  busca2 = searchB3(root, target2);

  if(busca != NULL)
    printf("encontrado: %d\n", busca->item);
  if(busca2 == NULL)
    printf("search works\n");
  
  print_Btree(root, 0);
  printf("height: %d\n", h);
  printf("depth root: %d\n", d1);
  printf("depth hoja: %d\n", d2);

  bfs(root);
  cleanB3(&root);
  print_Btree(root, 0);
  
  tree = new_Btree_arr(arr, 7);
  print_Btree(tree, 0);
  bfs(tree);
  // [5[2 [3]][1 [10]]]
  /*
    5
    |- 2
       |- 3
    |- 1
       |- 10
   */
  free(root);
  free(tree);
  free(busca);
  free(busca2);
  return 0;
}
