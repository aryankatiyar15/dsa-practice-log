class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 'prev' will keep track of the node we already reversed
        ListNode* prev = NULL;

        // 'nxt' will temporarily store the next node to visit
        ListNode* nxt = NULL;

        // 'curr' will move through the linked list starting at head
        ListNode* curr = head;

        // Loop until we reach the end of the list
        while (curr != NULL) {
            // Step 1: Save the next node before breaking the link
            nxt = curr->next;

            // Step 2: Reverse the current node's pointer
            curr->next = prev;

            // Step 3: Move 'prev' one step forward (to current)
            prev = curr;

            // Step 4: Move 'curr' one step forward (to next)
            curr = nxt;
        }

        // 'prev' will now be pointing to the new head of the reversed list
        return prev;

        /*
        Time Complexity: O(n)  
        -> We traverse each node exactly once.

        Space Complexity: O(1)  
        -> We only use a few extra pointers (prev, nxt, curr), no extra memory proportional to input.
        */
    }
};
