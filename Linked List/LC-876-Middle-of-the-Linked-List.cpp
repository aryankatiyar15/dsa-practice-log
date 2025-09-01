class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Approach: Slow & Fast Pointer (Tortoise-Hare technique)
        // - Slow moves 1 step at a time
        // - Fast moves 2 steps at a time
        // - When fast reaches the end, slow will be at the middle
        
        // Time Complexity: O(n) → We traverse the list once
        // Space Complexity: O(1) → No extra data structures used

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // Middle node of the linked list
    }
};
