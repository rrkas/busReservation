typedef struct BinarySearchTree BST;
// if bst is empty then we have to handle the error
struct BinarySearchTree
{
  int PassnNo; // busNo0SeatNo.
  char name[10];
  struct BinarySearchTree *left;
  struct BinarySearchTree *right;
};