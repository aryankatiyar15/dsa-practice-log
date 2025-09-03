// Approach: Length Difference Method
// - First, calculate the lengths of both lists (l1 and l2)
// - Advance the pointer of the longer list by the difference in lengths
// - Now both pointers are equally far from the intersection
// - Traverse both lists together until they meet (or reach NULL if no intersection)
//
// Time Complexity: O(m + n) → m = length of list A, n = length of list B
//   (One pass to count lengths + one pass to align + one pass to find intersection)
// Space Complexity: O(1) → Only a few pointers and counters used

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        int l1 = 0, l2 = 0;

        // Count lengths of both lists
        while(curr1 != NULL) {
            l1++;
            curr1 = curr1->next;
        }
        while(curr2 != NULL) {
            l2++;
            curr2 = curr2->next;
        }

        curr1 = headA;
        curr2 = headB;

        // Align the start points by skipping extra nodes in longer list
        if(l1 > l2) {
            int diff = l1 - l2;
            for(int i = 0; i < diff; i++) {
                curr1 = curr1->next;
            }
        } else {
            int diff = l2 - l1;
            for(int i = 0; i < diff; i++) {
                curr2 = curr2->next;
            }
        }

        // Move both pointers together until they meet
        while(curr1 != curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return curr1; // Either intersection node or NULL
    }
};
