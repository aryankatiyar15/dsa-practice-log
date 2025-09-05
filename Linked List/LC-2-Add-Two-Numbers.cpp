/*

 Logic:
We are given two linked lists where each node contains a single digit in reverse order.  
We need to add the two numbers and return the sum as a new linked list.

1. Use a dummy node to simplify handling of the head.
2. Traverse both lists simultaneously, adding corresponding digits plus any carry.
3. Create a new node with value = (sum % 10), and update carry = sum / 10.
4. Move forward in both lists if nodes exist.
5. After the loop, if carry > 0, add one more node.
6. Return the next of dummy (actual head of the new list).

 Example:  
Input: l1 = [2,4,3], l2 = [5,6,4]  
Output: [7,0,8]  (since 342 + 465 = 807)

 Time Complexity: O(max(m, n)) – we traverse the longer list fully.  
 
 Space Complexity: O(1) – apart from the output list, no extra space.

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        ListNode* temp1 = l1;           
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 != NULL || temp2 != NULL) {
            int sum = carry;

            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }

        if(carry) {
            curr->next = new ListNode(carry);
        }

        return dummyNode->next;
    }
};
