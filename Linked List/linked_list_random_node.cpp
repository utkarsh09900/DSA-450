Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
  
  Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.


Best Solution link:
https://leetcode.com/problems/linked-list-random-node/discuss/1671967/2-ways-JavaC%2B%2BPythonJavaScript-oror-Easy-for-mind-to-Accept-it

Best Solution 2:

#)Intuition :-

One way to solve this question can be that, we first traverse the entire linkedlist and thus we get to know the length of linkedlist .After ths we just call a random node with the help of rand( )%length .
The second way is not something that comes with intuition it's something that needs to be informed and this method is the famous reservoir sampling method .
The Reservoir sampling method:-

*)It's not a tough algo it's just that we usually don't know this . So before starting let's discuss a bit about probability .

1. When we read the first node head, if the stream ListNode stops here, we can just return the head->val. The probability of picking here is 1/1 .
2. When we goto second node we can decide if we replace the result r or not. The possibility is 1/2. So now we need to genereate a random number between 0 & 1 and if it is equals to 1 replace r with the current node else we don't traumantize r, so it's value is till the value of head .
3. Now let's goto third node and we can decide if we can replace the result r or not . The probability of picking the third node will be 1/3 . and not picking up will be 2/3 . So now we generate a random number between 0-to-2 if the result is 2 then we replace r with the value of indexed node 2
We need to continue this till the end of list node .
4. To conclude, if we have n different balls than the equal probability of picking any one of them will be 1/n .
Now that's it, this is what reservoir sampling method looks like, told you its easy ;)
  
  Optimal Code:

class Solution {
public:

    ListNode* u;
    Solution(ListNode* head) {
        u = head;
    }
    
    int getRandom() {
        int index = 1;
        int res = 0;
        ListNode* curr = u;
        while(curr){
            if(rand() % index == 0){
                res = curr->val;
            }
            index++;
            curr = curr->next;
        }
        return res;
    }
};

Code Using Extra Space :

class Solution {
public:
    vector<int> res; 
    Solution(ListNode* head) { 
        while(head){ // Storing all the values by iterating over the LinkedList
            res.push_back(head->val);
            head=head->next;
        }
    }
    
    int getRandom() { 
        //rand() will generate a random number b/w 0 & RAND_MAX
        //then take modulo of LinkedList size with Array size. So, the range become 0 to n - 1
        //why we doing that as we have to return array value
        return res[rand()%res.size()];
    }
};
