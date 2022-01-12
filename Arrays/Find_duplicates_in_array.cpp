Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1.
Example 2:

Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3 
Explanation: 2 and 3 occur more than once
in the given array.
  
  TC:O(N)
  SC:O(N)
    
  class Solution{
  public:
  vector<int> duplicates(int arr[], int n) {
       vector<int>ans;
       int freq[n]={0};
       
       for(int i=0; i<n; i++){
           freq[arr[i]]++;
       }
      for(int i=0; i<n; i++){
          if(freq[i]>1){
              ans.push_back(i);
          }
          
          
      }
      if(ans.empty()==true){
          ans.push_back(-1);
      }
   return ans;
   }
};


Leetcode Variant:

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]*=-1;
        }
        return ans;
    }
};
