Given N bits to an OR - Gate find the output that will be produced. 
OR - Gate Table:
1 | 1 = 1
1 | 0 = 1
0 | 1 = 1
0 | 0 = 0
 

Example 1:

Input:
N = 4
arr: 1 1 1 0
Output:
1
Explanation:
1 | 1 = 1
1 | 1 = 1
1 | 0 = 1
hence output is 1
  
  TC:O(N)
  SC:O(1)
 

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
   
class Solution{
public:
    int orGate(vector<int> arr,int N){
        for(int i = 0 ;i<N ;i++){
            // if we find a bit as 1 the resulting 
            // answer will always be 1
            if(arr[i] == 1)
                return 1;
        }
        // if no 1 is present then answer is zero
        return 0;
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
        cout << ob.orGate(v,N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
