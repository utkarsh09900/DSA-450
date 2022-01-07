Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 

Example 1:

Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.
Example 2:

Input: n = 3, arr[] = {1, 2, 3}
Output: 0
Explanation: No triplet with zero sum exists.
  
  
//   TC:O(N^2)
//   SC: O(1)
    
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {
    int l, r;
    //Sorting the elements.
    sort(arr, arr+n);

    //Traversing the array elements.
    for (int i = 0; i < n - 2; i++)
    {
        //Taking two pointers. One at element after ith index and another
        //at the last index.
        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            //If sum of elements at indexes i, l and r is equal 
            //to 0, we return true.
            if (arr[i] + arr[l] + arr[r] == 0)
                return true;
            //Else if the sum is less than required number, it means we need
            //to increase the sum so we increase the left pointer l.
            else if (arr[i] + arr[l] + arr[r] < 0)
                l++;
            //Else the sum is more than required number and we need to
            //decrease the sum so we decrease the right pointer r.
            else
                r--;
        }
    }

    //returning false if no triplet sum equal to required number is present.
    return false;
}
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends
