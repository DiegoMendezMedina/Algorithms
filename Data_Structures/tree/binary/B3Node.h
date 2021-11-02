// Binary tree abstraction 
typedef struct B3Node{
  struct B3Node* father;
  struct B3Node* left;
  struct B3Node* right;
  int item;
} B3Node;


/* creates the memory of a Node */
B3Node * B3nodealloc()
{
  return (B3Node *) malloc(sizeof(B3Node));
}
