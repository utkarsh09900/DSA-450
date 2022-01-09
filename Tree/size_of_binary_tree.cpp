Given a binary tree of size N, you have to count number of nodes in it. For example, count of nodes in below tree is 4.

        1
     /      \
   10      39
  /
5
  
  Given Tree is :
                                10
                             /        \
                           5          9
                             \       /     \
                              1    3       6

                                  There are six nodes in the tree .
                                  
                                  
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left;
     Node* right;
}; */

/* Computes the number of nodes in a tree. */
int getSize(Node* node)
{
   // Your code here
   if(node==NULL) return 0;
   
    int lh=getSize(node->left);
    int rh=getSize(node->right);
    
    return 1+lh+rh;
}                                  
