
//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.
void dfs(Node*root, vector<int> &ans)
      {
          if(root==NULL) return;
          
          dfs(root->left,ans);
          dfs(root->right,ans);
          ans.push_back(root->data);
      }
      
 
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
