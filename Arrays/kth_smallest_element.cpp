Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.
Example 2:

Input:
N = 5
arr[] = 7 10 4 20 15
K = 4
Output : 15
Explanation :
4th smallest element in the given 
array is 15.

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    int kthSmallest(int arr[], int l, int r, int k) {
//code here
        priority_queue<int> mxhp;
        for(int i=l;i<=r;i++){
        mxhp.push(arr[i]);
        if(mxhp.size()>k){
            mxhp.pop();
        }
    }
        return mxhp.top();
    }
};
