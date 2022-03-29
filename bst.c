typedef struct BinarySearchTree BSTR;
// if BSTR is empty then we have to handle the error
struct BinarySearchTree
{
  int passengerNumber; // busNo0SeatNo.
  char name[10];
  struct BinarySearchTree *left;
  struct BinarySearchTree *right;
};