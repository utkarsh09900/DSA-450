Given a binary string, count number of substrings that start and end with 1.
  
  algo:
1. Count the number of 1’s. Let the count of 1’s be m. 
2. Return m(m - 1) / 2 .
  
  Why? m(m-1)/2 only??
  Ans:
  Out of all the 1's in the string, you need to choose 2 1's so that 1st is for startting of substring and the second is for ending of the substring!
  So, out of n 1's you should choose 2 1's and also thing to note here is that you can't choose the opposite(last as first and first as last char of substring)
  So it boils down a combination question:
      nC2
     => n! / (n-2)! * 2!
     => n(n-1)/2
        
//         TC: O(N)
//         SC: O(1)
        
  class Solution
{
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a){
        
        int m=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]=='1')
                m++;
        }
        return (m*(m-1))/2;
    }

};
