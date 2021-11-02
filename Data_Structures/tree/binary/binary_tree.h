#include "b3Node_queue.h"

/**
 * Binary tree implementation
 */


/* tree and node initializer, in case of root, father must be NULL */
B3Node * new_Btree(int item, B3Node* father)
{
  struct B3Node *root = B3nodealloc();
  
  root->item = item;
  root->left = NULL;
  root->right = NULL;
  root->father = father;
    
  return root;
}

void newBtree_arr(int *, int, int, B3Node**);
/* tree initializer given an array*/
B3Node* new_Btree_arr(int *arr, int n)
{
  B3Node * tree = B3nodealloc();
  newBtree_arr(arr, n, 0, &tree);
  return tree;
}

void newBtree_arr(int *arr, int n, int i, B3Node** root)
{
  if(i==0){
    (*root)->father = NULL;
    (*root)->item = arr[i];
  }
  
  if(2*i+1<n){
    (*root)->left= B3nodealloc();
    (*root)->left->father = (*root);
    (*root)->left->item = arr[2*i+1];
    newBtree_arr(arr, n, 2*i+1, &(*root)->left);
    }
  
  else
    (*root)->left = NULL;
  
  if(2*i+2<n){
    (*root)->right= B3nodealloc();
    (*root)->right->father = (*root);
    (*root)->right->item = arr[2*i+2];
    newBtree_arr(arr, n, 2*i+2, &(*root)->right);
  }
  else
    (*root)->right = NULL;
    
  
}
/**
 * height : Recursive function, returns the height of the tree received.
 *
 * Recusrive definition:
 *  - The height of the empty tree is -1.
 *  - The height of the tree is 1 + max(tree->left, tree->right)
 */
int heightB3(B3Node* tree)
{
  if(tree == NULL)
    return -1;

  int left, right;
  
  left = heightB3(tree->left);
  right = heightB3(tree->right);

  return (left>right)? 1+left : 1+right;
}


/**
 * depthB3: gets the depth of the node received.
 *          distance from the node to root.
 */
int depthB3(B3Node* node)
{
  
  if(node->father == NULL)
    return 0;

  return 1 + depthB3(node->father);
}

int emptyB3(B3Node* root){
  if(root == NULL)
    return 1;
  return 0;
}

/**
 * searchB3: if node is in tree returns the B3Node,
 *           NULL if not.
 */
B3Node* searchB3(B3Node* tree, B3Node* node)
{
  if(node == NULL)
    return NULL;
  
  if(tree == NULL)
    return NULL;

  if(tree->item == node->item)
    return tree;
  
  B3Node* left, *right;
  left = searchB3(tree->left, node);
  right = searchB3(tree->right, node);

  if(left != NULL)
    return left;
  if(right != NULL)
    return right;
  return NULL;
}

/**
 * containsB3: returns 1 if node is in tree,
 *             INT_MIN if not.
 */
int containsB3(B3Node* tree, B3Node* node)
{
  B3Node *n = searchB3(tree, node);
  if(n == NULL)
    return INT_MIN;
  return 1;
}

/**
 * cleanB3: Cleans the tree in constant time.
 */
void cleanB3(B3Node** root)
{
  *root = NULL;
}


/* printing the binary tree */
void print_Btree(B3Node* node, int depth)
{
  if( depth == 0)
    printf("----Binary Tree---\n");
  
  if(node != NULL){
    /* proper alignment */
    for(int i = 0; i <= depth ; i++)
      printf("\t");
    // printing the item
    printf("%d  \n", node->item);
    /* proper alignment left son */
    for(int i = 0; i <= depth ; i++)
      printf("\t");
    printf("|\n"); // denote separation between sons.
    print_Btree(node->left, depth+1);
    /* proper alignment right son */
    for(int i = 0; i <= depth ; i++)
      printf("\t");
    printf("|\n"); // denote separation between sons.
    print_Btree(node->right, depth+1);
  }
  else{ /* empty node */
    for(int i = 0; i <= depth ; i++)
      printf("\t");
    printf("VOID\n");
  }
  if(depth == 0)
    printf("-------------------\n"); // end of printing
}

/* Just prints but can be easily modified to do
   domething on the nodes */
void bfs(B3Node* tree)
{
  if(tree == NULL)
    return;
  
  printf("-----BFS Printing-----\n");
  B3Node* aux;
  Queue* q = newQueue();
  
  enqueue(q, tree);
  while(!Qempty(q)){
    aux = (B3Node*) dequeue(q);
    printf("%d ", aux->item);
    if(aux->left != NULL)
      enqueue(q, aux->left);
    if(aux->right != NULL)
      enqueue(q, aux->right);
  }
  printf("\n----------------------\n");  
}
