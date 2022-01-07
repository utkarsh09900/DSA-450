Approach 1:

TC: O(N logN)
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
    // Get lengths of both strings
    int n1 = a.length();
    int n2 = b.length();
 
    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
        return false;
 
    // Sort both the strings
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    // Compare sorted strings
    for (int i = 0; i < n1; i++)
        if (a[i] != b[i])
            return false;
    
    return true;
  }
};


Approach 2:
(Count characters)

Method 2 (Count characters) 
1. This method assumes that the set of possible characters in both strings is small. In the following implementation, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters. 

2. Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
3. Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
4. Compare count arrays. If both count arrays are same, then return true.
  
  TC:O(N)
  SC:O(N)
    
    // C++ program to check if two strings
    // are anagrams of each other
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

/* function to check whether two strings are anagram of
each other */
bool areAnagram(char* str1, char* str2)
{
	// Create 2 count arrays and initialize all values as 0
	int count1[NO_OF_CHARS] = { 0 };
	int count2[NO_OF_CHARS] = { 0 };
	int i;

	// For each character in input strings, increment count
	// in the corresponding count array
	for (i = 0; str1[i] && str2[i]; i++) {
		count1[str1[i]]++;
		count2[str2[i]]++;
	}

	// If both strings are of different length. Removing
	// this condition will make the program fail for strings
	// like "aaca" and "aca"
	if (str1[i] || str2[i])
		return false;

	// Compare count arrays
	for (i = 0; i < NO_OF_CHARS; i++)
		if (count1[i] != count2[i])
			return false;

	return true;
}

/* Driver code*/
int main()
{
	char str1[] = "geeksforgeeks";
	char str2[] = "forgeeksgeeks";

	// Function Call
	if (areAnagram(str1, str2))
		cout << "The two strings are anagram of each other";
	else
		cout << "The two strings are not anagram of each "
				"other";

	return 0;
}

3. Optimal Solution:

TC:O(N)
SC:O(String length)

Using Single Array:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
    int arr[26] = {0};
    
    if(a.length() != b.length())
        return 0;
    
    for(auto x : a)
        arr[x - 'a']++;
    
    for(auto y : b)
        arr[y - 'a']--;
        
    for(int i = 0; i < 26; i++){
        if(arr[i] > 0)
            return 0;
    }
    return 1;    
 
}

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends

