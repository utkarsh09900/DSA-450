 BRUTE FORCE

Method 1: This is a simple method that takes O(n3) time to arrive at the result.

Approach: The naive approach runs three loops and check one by one that sum of three elements is zero or not. If the sum of three elements is zero then print elements otherwise print not found.
Algorithm: 
1. Run three nested loops with loop counter i, j, k
2. The first loops will run from 0 to n-3 and second loop from i+1 to n-2 and the third loop from j+1 to n-1. The loop counter represents the three elements of the triplet.
3. Check if the sum of elements at i’th, j’th, k’th is equal to zero or not. If yes print the sum else continue.
  
  TC: 0(N^3)
  SC: O(1)
  
  #include<bits/stdc++.h>
using namespace std;

// Prints all triplets in arr[] with 0 sum
void findTriplets(int arr[], int n)
{
    bool found = false;
    for (int i=0; i<n-2; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                if (arr[i]+arr[j]+arr[k] == 0)
                {
                    cout << arr[i] << " "
                         << arr[j] << " "
                         << arr[k] <<endl;
                    found = true;
                }
            }
        }
    }

    // If no triplet with 0 sum found in array
    if (found == false)
        cout << " not exist "<<endl;

}

// Driver code
int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    findTriplets(arr, n);
    return 0;
}


METHOD 2: USING HASHMAP
Approach: This involves traversing through the array. For every element arr[i], find a pair with sum “-arr[i]”. This problem reduces to pair sum and can be solved in O(n) time using hashing.

Algorithm: 

1. Create a hashmap to store a key-value pair.
2. Run a nested loop with two loops, the outer loop from 0 to n-2 and the inner loop from i+1 to n-1
3. Check if the sum of ith and jth element multiplied with -1 is present in the hashmap or not
4. If the element is present in the hashmap, print the triplet else insert the j’th element in the hashmap.
  
  TC:O(N^2)
  SC:O(N) 
    
    #include<bits/stdc++.h>
using namespace std;

// function to print triplets with 0 sum
void findTriplets(int arr[], int n)
{
    bool found = false;

    for (int i=0; i<n-1; i++)
    {
        // Find all pairs with sum equals to
        // "-arr[i]"
        unordered_set<int> s;
        for (int j=i+1; j<n; j++)
        {
            int x = -(arr[i] + arr[j]);
            if (s.find(x) != s.end())
            {
                printf("%d %d %d\n", x, arr[i], arr[j]);
                found = true;
            }
            else
                s.insert(arr[j]);
        }
    }

    if (found == false)
        cout << " No Triplet Found" << endl;
}

// Driver code
int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    findTriplets(arr, n);
    return 0;
}

APPROACH 3: OPTIMAL SOLN - TWO POINTER ALGORITHM

TC:O(N^2)
SC:O(1)
  
  // C++ program to find triplets in a given
// array whose sum is zero
#include<bits/stdc++.h>
using namespace std;

// function to print triplets with 0 sum
void findTriplets(int arr[], int n)
{
    bool found = false;

    // sort array elements
    sort(arr, arr+n);

    for (int i=0; i<n-1; i++)
    {
        // initialize left and right
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == 0)
            {
                // print elements if it's sum is zero
                printf("%d %d %d\n", arr[i], arr[l], arr[r]);
                l++;
                r--;
                found = true;
                  break;
            }

            // If sum of three elements is less
            // than zero then increment in left
            else if (arr[i] + arr[l] + arr[r] < 0)
                l++;

            // if sum is greater than zero than
            // decrement in right side
            else
                r--;
        }
    }

    if (found == false)
        cout << " No Triplet Found" << endl;
}

// Driven source
int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    findTriplets(arr, n);
    return 0;
}
  
