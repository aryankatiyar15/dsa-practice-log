/*
Problem: Rotate List (LeetCode 61)

 Logic:
We need to rotate the linked list to the right by k positions.
1. First, calculate the length of the list and also keep track of the last node.
2. Reduce k using modulo (k = k % length), because rotating length times gives the same list.
3. If k becomes 0, simply return the original head.
4. Find the new tail node at position (length - k). Its next node will be the new head.
5. Connect the last node to the old head to make it circular.
6. Break the link from newTail to newHead to finalize rotation.
7. Return newHead.



Time Complexity: O(n) – we traverse the list a couple of times.  
Space Complexity: O(1) – only pointers are used.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
            return head;
        
        ListNode* last = head;
        int length = 1;
        while(last->next != NULL) {
            length++;
            last = last->next;
        }

        k = k % length;
        if(k == 0) return head;

        ListNode* newTail = head;
        for(int i=1; i<length-k; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        last->next = head;
        newTail->next = NULL;

        return newHead;
    }
};
