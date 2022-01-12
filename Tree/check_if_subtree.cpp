Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 
Explanation: S is present in T

Example 2:

Input:
T:      26         S:   26
       /   \           /  \
     10     N        10    N
   /    \           /  \
   20    30        20  30
  /  \            /  \
 40   60         40  60
Output: 1 
Explanation: 
S and T are both same. Hence, 
it can be said that S is a subtree 
of T.
  
  class Solution
{
 public:
   //Function to check if S is a subtree of tree T.
 bool isSubTree(Node* T, Node* S) {
       if(T == NULL) return false;
       if(isIdentical(T,S)) 
            return true;
       return isSubTree(T->left,S) || isSubTree(T->right,S);
   }
   
 bool isIdentical(Node* T, Node* S){
       if(T == NULL && S == NULL) return true;
       
       if(T == NULL && S != NULL) return false;
       if(T != NULL && S == NULL) return false;
       
       return (T->data == S->data) && isIdentical(T->left,S->left) && isIdentical(T->right,S->right); 
   }
};
