Given a Binary Tree of size N, your task is to complete the function countNonLeafNodes(), that should return the count of all the non-leaf nodes of the given binary tree.

Example:

Input:                                                            1
1 2 3 4 5 N N                                                    / \
Output:                                                         2   3
2                                                              /\
Explanation:                                                  4  5
Nodes 1 and 2 are the only non leaf nodes.
  
  //User function Template for C++
/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        if(root==NULL)
            return 0;
            
        if(root->left==NULL &&root->right==NULL)
            return 0;
            
        return 1+ countNonLeafNodes(root->left) + countNonLeafNodes(root->right);    //Here 1 is added because it is a count of root of the tree
    }
};
