Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
  
  class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            
        vector<vector<int>> ans;
        if(intervals.size()==0)
            return ans;
        
        sort(intervals.begin(),intervals.end());// sort
        vector<int> curr = intervals[0];
        // 0 is starting point
        //1 is ending point
        
        for(auto it:intervals)
        {
            if(it[0]<=curr[1])// means there is overlapping of intervals
            {
                curr[1]=max(it[1],curr[1]); // need to check which has max ending points hence we will make ending point of pre_interval to max
            }
            else
            { // if there is no overlapping
                ans.push_back(curr); // simplely push pre-interval to mergedintervals vector
                curr=it;
            }     
        }
        
        ans.push_back(curr);
        return ans;
    }
};
