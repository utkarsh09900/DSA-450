Given an array of distinct integers, find all the pairs having both negative and positive values of a number in the array.


Example 1:

Input:
n = 8
arr[] = {1,3,6,-2,-1,-3,2,7}
Output: -1 1 -3 3 -2 2
Explanation: 1, 3 and 2 are present 
pairwise postive and negative. 6 and 
7 have no pair.
Example 2:

Input:
n = 3
arr[] = {3,2,1}
Output: 0
Explanation: No such pair exists so the 
output is 0.
  
  TC: O(N)
  SC: O(N)
    
class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        set<int> s;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(s.find(-arr[i])!=s.end()){
               ans.push_back(-abs(arr[i]));
               ans.push_back(abs(arr[i]));
            }
            else
            {
                s.insert(arr[i]);
            }
        }
        return ans;
    }
};
