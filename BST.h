#ifndef BST_H
#define BST_H
#include "BSTNODE.h"
#include"iostream"
using namespace std;

class BST{
    struct BSTNODE
    {
        int data;
        BSTNODE* left;
        BSTNODE* right;
    };
    //public:
//BST();
BSTNODE *root;
public:
BST();
void add(int value);
void printbst(BSTNODE* PN);
void printinorder();
void inorder(BSTNODE* p);
void print_inorder();
void removenode(int dvalue);
void Delete(BSTNODE *root, int data);
#endif // BST_H
};
