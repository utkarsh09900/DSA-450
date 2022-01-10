Given an N bit binary number, find the 1's complement of the number. The ones' complement of a binary number is defined as the value obtained by inverting all the bits in the binary representation of the number (swapping 0s for 1s and vice versa).
 
1's Complement means just change to 1 to 0 and 0 to 1
  
Example 1:

Input:
N = 3
S = 101
Output:
010
Explanation:
We get the output by converting 1's in S
to 0 and 0s to 1
  
Example 2:

Input:
N = 2
S = 10
Output:
01
Explanation:
We get the output by converting 1's in S
to 0 and 0s to 1

  TC: O(N)
  SC: O(1)

   code 1:

class Solution{
public:
    string onesComplement(string S,int N){
        string ans = "";
        // for every character in S
        for(int i = 0;i<N;i++)
        {
            // if character at i is 0 then add character 1 to ans
            if(S[i] == '0')
                ans = ans + '1';
            // if character at i is 1 then add character 0 to ans
            else
                ans = ans + '0';
        }
        return ans;
    }
};

Alternative method:

class Solution{ 
public:
   string onesComplement(string s,int n){
        for(int i=0;i<n;i++)
        s[i]^=1;
        return s;
    }
};

2's Complement means traverse from right to left and first 1, after we get first 1 then all bits after 1, flip that is make 1 to 0 and 0 to 1.
  
  // C++ program to print 1's and 2's complement of
// a binary number
  
//   Time Complexity: O(n)
//   Auxiliary Space: O(1)
    
#include <bits/stdc++.h>
using namespace std;

// Returns '0' for '1' and '1' for '0'
char flip(char c) {return (c == '0')? '1': '0';}

// Print 1's and 2's complement of binary number
// represented by "bin"
void printOneAndTwosComplement(string bin)
{
    int n = bin.length();
    int i;

    string ones, twos;
    ones = twos = "";

    //  for ones complement flip every bit
    for (i = 0; i < n; i++)
        ones += flip(bin[i]);

    //  for two's complement go from right to left in
    //  ones complement and if we get 1 make, we make
    //  them 0 and keep going left when we get first
    //  0, make that 1 and go out of loop
    twos = ones;
    for (i = n - 1; i >= 0; i--)
    {
        if (ones[i] == '1')
            twos[i] = '0';
        else
        {
            twos[i] = '1';
            break;
        }
    }

    // If No break : all are 1  as in 111  or  11111;
    // in such case, add extra 1 at beginning
    if (i == -1)
        twos = '1' + twos;


    cout << "1's complement: " << ones << endl;
    cout << "2's complement: " << twos << endl;
}

// Driver program
int main()
{
    string bin = "1100";
    printOneAndTwosComplement(bin);
    return 0;
}
