Given N bits to an XOR - Gate find the output that will be produced. 
XOR - Gate Table:
1 ^ 1 = 0
1 ^ 0 = 1
0 ^ 1 = 1
0 ^ 0 = 0
 

Example 1:

Input:
N = 4
arr: 1 1 1 0
Output:
1
Explanation:
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1
hence output is 1
Example 2:

Input:
N = 4
arr: 0 0 1 0
Output:
1
Explanation:
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
hence output is 1
  
  
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
   
    int xorGate(vector<int> arr,int N){
        int count = 0;
        for(int i = 0 ;i<N ;i++){
            // count number of ones.
            if(arr[i] == 1)
                count++;
        }
        //if there are even number of 1s answer is 0 otherwise 1.
        return count%2;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.xorGate(v,N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
