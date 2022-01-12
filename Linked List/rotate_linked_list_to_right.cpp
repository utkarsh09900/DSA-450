61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
TC: O(N)
SC: O(1)

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) 
     {
        if(head == NULL || head->next == NULL|| k==0)
            return head; 
        ListNode* curr = head;
        int size =1;
        while(curr->next != NULL) {
            size++;
            curr = curr->next;
        }
        //loop the list
        curr->next=head;
        //handle the case of k>size
        k = k%size;
        //find the node to break the loop at
        for(int i=0; i<size-k; i++) {
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};
