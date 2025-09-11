/*
 * ALGORITHM: Check if Array is Sorted and Rotated
 * 
 * LOGIC:
 * - A valid rotated sorted array can have at most 1 "break point"
 * - Break point = position where current element > next element
 * - 0 breaks: already sorted (no rotation)
 * - 1 break: properly rotated once
 * - 2+ breaks: invalid (cannot be rotated sorted array)
 * 
 * KEY INSIGHT: Must check wrap-around (last element vs first element)
 * 
 * COMPLEXITY ANALYSIS:
 * - Time: O(n) - single pass through array
 * - Space: O(1) - only using constant extra space
 */

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;  // Track number of break points
        
        // Check each element against next (with wrap-around)
        for (int i = 0; i < nums.size(); i++) {
            // Compare current with next element (wraps to index 0 at end)
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                count++;
                
                // Early termination: more than 1 break = invalid
                if (count > 1) return false;
            }
        }
        
        return true;  // 0 or 1 break = valid
    }
};
