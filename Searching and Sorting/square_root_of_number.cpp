Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.
Example 2:

Input:
x = 4
Output: 2
Explanation: Since, 4 is a perfect 
square, so its square root is 2.
  
  Expected Time Complexity: O(log N)
  Expected Auxiliary Space: O(1)
  
  class Solution{
  public:
    long long int floorSqrt(long long int x) 
{
   // Your code goes here   
   long long int l=0,h=x;
   long long int ans=0;
   while(l<=h){
      long long int mid=l+(h-l)/2;
      long long int sq=mid*mid;
       if(sq==x){
           return mid;
       }
       else if(sq<x){
           ans=mid;
           l=mid+1;
       }
       else{
           h=mid-1;
       }
   }
   return ans;
  }
};
