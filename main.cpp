#include <iostream>
#include"BST.h"
#include"BSTNODE.h"

using namespace std;

int main()
{
    BST BST1;
    BST1.add(4);
    BST1.add(8);
    BST1.add(2);
    BST1.add(10);
   BST1.print_inorder();
    return 0;
}
