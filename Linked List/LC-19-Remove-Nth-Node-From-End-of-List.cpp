class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node before head to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Pointer to calculate total length of the linked list
        ListNode* current = head;
        int length = 0;

        // Step 1: Find the total length of the list
        while (current != NULL) {
            length++;
            current = current->next;
        }

        // Step 2: Reset current to dummy (so we can move before the target node)
        current = dummy;

        // Step 3: Move (length - n) steps forward to reach the node before the one to delete
        length = length - n;
        while (length > 0) {
            length--;
            current = current->next;
        }

        // Step 4: Skip the target node
        current->next = current->next->next;

        // Return the new head (dummy->next, since head might be removed)
        return dummy->next;

        /*
        Time Complexity: O(n)
        -> First loop to calculate length: O(n)
        -> Second traversal to reach (length-n): O(n)
        -> Overall = O(n).

        Space Complexity: O(1)
        -> Only extra variables and a dummy node used, no extra memory proportional to input size.
        */
    }
};
