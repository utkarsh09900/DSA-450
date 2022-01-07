Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. The characters in the strings are in lowercase.

 

Example 1:

Input:
geeksforgeeks
forgeeksgeeks
Output: 
1
Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.
 

Example 2:

Input:                                          TC:O(N)
                                                SC:O(N)
mightandmagic
andmagicmigth
Output: 
0
Explanation: Here with any amount of
rotation s2 can't be obtained by s1.
  
  
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if(s1.length()!=s2.length())
            return false;
        else
        {
            //we concatenate first string to itself and check if other 
            //string occurs in it as substring. If yes, then it 
            //is rotated version and we return true else false.
            string concated=s1+s1;
            if(concated.find(s2)!=string::npos)
                return true;
            else
                return false;
        }
    }

};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends
