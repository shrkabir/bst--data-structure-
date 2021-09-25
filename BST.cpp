#include"BST.h"
#include"iostream"
using namespace std;

BST::BST()
{
    root=NULL;
    //left=NULL;
    //right=NULL;
}

void BST::add(int value)
{
    BSTNODE* node1=new BSTNODE;
    node1->data=value;
    node1->left=NULL;
    node1->right=NULL;
    if(root==NULL)
    {
        root=node1;
    }
    else
    {
        BSTNODE* nodeptr=new BSTNODE;
        nodeptr=root;
        while(true)
        {
            if(value<nodeptr->data){
                if(nodeptr->left==NULL)
                    {
                        nodeptr->left=node1;
                        break;
                    }
                else
                    {
                        nodeptr=nodeptr->left;
                    }
                }
            else
                {
                    if(nodeptr->right==NULL)
                        {
                            nodeptr->right=node1;
                            break;
                        }
                    else
                        {
                            nodeptr=nodeptr->right;
                        }

                }
        }

    }

}
void BST::print_inorder()
 {
 inorder(root);
 }

 void BST::inorder(BSTNODE* p)
 {
 if(p != NULL)
 {
 if(p->left) inorder(p->left);
 cout<<" "<<p->data<<" ";
 if(p->right) inorder(p->right);
 }
 else return;
 }

/*void BST::printbst(BSTNODE* PN)
{
    if(PN!=NULL)
    {
        printbst(PN->left);
        cout<<PN->value;
        printbst(PN->right);
    }
}
void BST::printinorder()
{
    return printbst(root);
}*/

void BST::Delete(BSTNODE *root, int data) {
  if (root == NULL) {
     cout<<"tree is null";
  }
  if (data < root->data) {  // data is in the left sub tree.
      root->left = Delete(root->left, data);
  } else if (data > root->data) { // data is in the right sub tree.
      root->right = Delete(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        delete(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->right;
        delete temp;
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->left;
        delete temp;
     }
     // case 4: two children
     else {
        struct Node *temp = FindMin(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        root->right = Delete(root->right, temp->data); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}





int FindMin(Node *root) {
   if (root == NULL) {
      return INT_MAX; // or undefined.
   }
   if (root->left != NULL) {
      return FindMin(root->left); // left tree is smaller
   }
   return root->data;
}
