You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

Example 1:

Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need 
to be flipped are 01010. If we flip 
these bits, we get 10100, which is B.
Example 2:

Input: A = 20, B = 25
Output: 3
Explanation:
A  = 10100
B  = 11001
As we can see, the bits of A that need 
to be flipped are 10100. If we flip 
these bits, we get 11001, which is B.

  Expected Time Complexity: O(log N).
  Expected Auxiliary Space: O(1).
  
  class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countSetBit(int n)
   {
       int res = 0;
       while(n > 0)
       {
           n = n & (n-1);
           res++;
       }
       return res;
   }
   
   int countBitsFlip(int a, int b)
   {
       int Xor = a ^ b;
       
       return countSetBit(Xor);
   }
};



OR

//Back-end complete function Template for C++

class Solution{
    public:
    // Function to count set bits
    int countSetBits(unsigned int n)
    {
        //We use a counter variable
      unsigned int count = 0;
      while(n)
      {
        //AND operation of n and 1 gives us the rightmost bit. 
        //counter variable is increased if we get 1 as the rightmost bit.
        count += n & 1;
        
        //Right Shift n by 1 to remove the rightmost bit.
        n >>= 1;
        
      }
      return count;
    }
    
    
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        int ans = 0;
        //XOR operation gives set bits only when there are dissimilar bits.
        //We store the value of XOR operation of a and b.
        ans = a^b;
        
        //returning the number of set bits in resultant.
        return countSetBits(ans);
        
    }
};
