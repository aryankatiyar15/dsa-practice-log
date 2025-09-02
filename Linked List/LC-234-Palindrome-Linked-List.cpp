class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Pointer to traverse the list from the start
        ListNode* first = head;

        // Stack will be used to reverse values for comparison
        stack<int> st;

        // Step 1: Push all node values into the stack
        while (first != NULL) {
            st.push(first->val);
            first = first->next;
        }

        // Step 2: Reset pointer back to head for comparison
        first = head;

        // Step 3: Compare list values with stack top (LIFO order)
        while (first != NULL && st.top() == first->val) {
            st.pop();               // Remove matched element from stack
            first = first->next;    // Move to next node
        }

        // If stack is empty → all values matched → palindrome
        return st.empty();

        /*
        Time Complexity: O(n)
        -> First loop traverses all nodes (O(n)).
        -> Second loop also traverses all nodes (O(n)).
        -> Overall = O(n).

        Space Complexity: O(n)
        -> We store all node values in a stack, which takes O(n) space.
        */
    }
};
