/*
Logic:
We traverse the linked list with a pointer (curr).  
- If the current node's value equals the next node's value,  
  we skip the next node by adjusting the pointer (curr->next = curr->next->next).  
- Otherwise, we move curr forward.  
This way, all duplicates are removed in a single pass.

Time Complexity: O(n) → Each node is visited once.  
Space Complexity: O(1) → No extra space used, only pointers.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL) {
            if(curr->val == curr->next->val) {
                curr->next = curr->next->next; // skip duplicate node
            } else {
                curr = curr->next; // move forward if no duplicate
            }
        }
        return head; // return updated list without duplicates
    }
};
