// Problem: Detect Loop in Linked List (GFG)
// Approach: Floyd’s Cycle Detection Algorithm (Tortoise & Hare)
// - Use two pointers: slow (1 step at a time) and fast (2 steps at a time)
// - If there is a cycle, the fast and slow pointers will eventually meet
// - If fast reaches NULL, then no cycle exists
//
// Time Complexity: O(n) → At most one full traversal of the list
// Space Complexity: O(1) → Only two pointers used, no extra memory

class Solution {
  public:
    bool detectLoop(Node* head) {
        Node* fast = head;
        Node* slow = head;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) return true; // Cycle detected
        }
        
        return false; // No cycle
    }
};
