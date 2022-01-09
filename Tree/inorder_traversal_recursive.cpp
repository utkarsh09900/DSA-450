/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
    
  public:
      void dfs(Node*root, vector<int> &ans)
      {
          if(root==NULL) return;
          
          dfs(root->left,ans);
          ans.push_back(root->data);
          dfs(root->right,ans);
      }
      
 
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};

