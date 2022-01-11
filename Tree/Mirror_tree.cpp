Example 1:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2
Example 2:

Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.
  
  TC: O(N)
  SC: O(H)

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node==NULL)
            return;
            
    mirror(node->left);
    mirror(node->right);
    
    swap(node->left, node->right);
    }
};

If using swap function is not allowed then

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node==NULL)
            return;
            
    mirror(node->left);
    mirror(node->right);
    
    Node* temp= node->left;
    node->left=node->right;
    node->right=temp;
    }
};
