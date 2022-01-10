Check whether a number is Perfect Number or not
Problem Statement: Perfect Number. Write a program to find whether a number is a perfect number or not.

A perfect number is defined as a number that is the sum of its proper divisors ( all its positive divisors excluding itself). 

Examples:

Example 1:
Input: n=6
Output: 6 is a perfect number

Example 2:
Input: n=15
Output: 15 is not a perfect number

Example 3:
Input: n=28
Output: 28 is a perfect number
Reason:
For 6 and 28 , the sum of their proper divisors (1+2+3) and (1+4+7+14) is equal to the respective numbers and for 15 it is not.
Solution:

Solution 1: Basic
Intuition:

We can find the proper divisors of a given number. If their sum is equal to the given number then it is a perfect number.

Approach:

1. We initialise a sum to 0.
2. We can set a loop to iterate from 1 to n-1.
3. In every iteration we check if n is divisible by i, if it is we add it to our sum.
4. After the loop is over, we check whether the given number is equal to our sum, if it is then we the given number is a perfect number, otherwise not.
  
Code:

#include <iostream>

using namespace std;

bool isPerfect(int n) {

  int sum = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (n % i == 0)
      sum = sum + i;
  }
  if (sum == n)
    return true;
  else return false;
}

int main() {
  // your code goes here
  bool ex1 = isPerfect(6);
  bool ex2 = isPerfect(15);
  bool ex3 = isPerfect(28);

  if (ex1 == true) {
    cout << "6 is a perfect number" << endl;
  } else cout << "6 is not a perfect number" << endl;

  if (ex2 == true) {
    cout << "15 is a perfect number" << endl;
  } else cout << "15 is not a perfect number" << endl;

  if (ex3 == true) {
    cout << "28 is a perfect number" << endl;
  } else cout << "28 is not a perfect number" << endl;

  return 0;
}


// Output:

// 6 is a perfect Number

// 15 is not a perfect Number

// 28 is a perfect Number

Time Complexity: O(N)
Reason: We iterate from 1 to n-1.

Space Complexity: O(1)
Reason: We are not using any extra space.
  

Solution 2: Efficient Solution

We can use this elegant mathematical property that if n is divisible by k, then n will be also divisible by (n/k).

For example, 28 is divisible by 4, also 28 is divisible by (28/4)=7

In this way, we can reduce our search space from (1 … n-1) to (1… √n ).

Approach:

1. We initialise a sum to 0.
2. We can set a loop to iterate from 1 to √n.
3. In every iteration we check if n is divisible by i, if it is we add it and (n/i) to our sum.
4. After the loop is over, we check whether the given number is equal to our sum, if it is then we the given number is a perfect number, otherwise not.
Note: Please note that if ( i* i ) == n or i==1 r, then we will add only i to the sum as we don’t want to add i two times/ add the number itself to the sum.

Code:

#include <iostream>
using namespace std;


bool isPerfect(int n){
    
    int sum=0;
    for(int i = 1; i*i <= n; i++){
        if(n%i==0)
            if(i*i==n || i==1)
                sum =sum + i;
            else sum = sum+ i + n/i;
    }
    if(sum==n)
        return true;
    else return false;
}

int main() {
	// your code goes here
	bool ex1 = isPerfect(6);
	bool ex2 = isPerfect(15);
	bool ex3 = isPerfect(28);
	
	if(ex1== true){
	    cout<<"6 is a perfect number"<<endl;
	}
	else cout<<"6 is not a perfect number"<<endl;
	
	if(ex2== true){
	    cout<<"15 is a perfect number"<<endl;
	}
	else cout<<"15 is not a perfect number"<<endl;
	
	if(ex3== true){
	    cout<<"28 is a perfect number"<<endl;
	}
	else cout<<"28 is not a perfect number"<<endl;
	
	return 0;
}


// Output:

// 6 is a perfect number
// 15 is not a perfect number
// 28 is a perfect number

Time Complexity: O(√N)
Reason: We iterate from 1 to √n.

Space Complexity: O(1)
Reason: We are  not using any extra space
