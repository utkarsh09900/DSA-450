Optimal Solution
Take two Node pointers and initialise them to head of the linked list.
Iterate through the linked list as follows:
In each iteration move the slow pointer by one node and fast by two nodes(if they exist).
If at some point of time a fast pointer becomes NULL, this means the linked list has some endpoint, hence it is not circular.
If at some point in time slow and fast pointers become equals then this means the linked list contains a loop.
Now in order to determine whether the linked list is circular or not, check the point at which slow and fast pointers become equal and are also equal to the head of the linked list.
If it is equal to head then the given linked list is circular.
If it is not then the given linked list is not circular.
Eg. In the linked list given below:

  Here, the head is the pointer to the node with data = 1, now initialise slow and fast with head.

In this, after the 1st iteration, slow will start point to the node with data = 2, and fast will start point to the node with data = 3.
After the 2nd iteration, slow will start point to the node with data = 3, and fast will start point to the node with data = 1.
After the 3rd iteration, slow will start point to the node with data = 4, and fast will start point to the node with data = 3.
After the 4th iteration, slow will start point to the node with data = 1, and fast will start point to the node with data = 1.
At this point, slow and fast pointers, start pointing to the same node which is the same as head, hence this linked list is circular.
Time Complexity
O(N), where N is the length of the linked list.

 

As in cases where the linked list is a straight-chain, in that case, the fast pointer reaches the end of the linked list in N/2 steps. And if a linked list contains a loop, then in that case slow and fast pointers will become equal after some iterations.

At the meeting node of slow and fast pointers, the steps taken by both pointers should be the same. Let’s say they meet after K steps, then the required steps taken by both pointers will also be K. K may take values up to N. Hence this will take O(N) order of time.

Space Complexity
O(1).

 

As we are using constant extra memory.
  
  
  /*
		Time Complexity: O(N)
		Space Complexity: O(1),
		
		where N is the length of the given Linked List.
*/


bool isCircular(Node * head) {
    // If head is already NULL, then it is the circular linked list
    // with length zero.
    if (head == NULL) {
        return true;
    }

    // If next pointer of head is already NULL, then it the linear linked
    // list of length 1, hence we return false here.
    if (head -> next == NULL) {
        return false;
    }

    // Initialising slow and fast pointers with head.
    Node * slow = head, * fast = head;

    // Iterating through the linkedlist till, fast doesn't reach end of 
    // linked list or slow pointer will not become equal to fast pointer.
    while (fast != NULL && fast -> next != NULL) {

        // Moving slow pointer by one step.
        slow = slow -> next;
        // Moving fast pointer by two steps.
        fast = fast -> next -> next;

        // Checking if updated slow and fast pointer values are same or not.
        if (slow == fast) {
            break;
        }

    }

    // After completing the traversal, if slow and fast pointers meet and 
    // the node of meeting is node pointed by head, then linkedlist is circular.
    if (slow == fast && slow == head) {
        return true;
    }

    // If linkedlist is not circular, then return false.
    return false;
}
