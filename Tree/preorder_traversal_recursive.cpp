
/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to return a list containing the preorder traversal of the tree.
void dfs(Node*root, vector<int> &ans)
      {
          if(root==NULL) return;
          
          ans.push_back(root->data);
          dfs(root->left,ans);
          dfs(root->right,ans);
      }
      
 
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
