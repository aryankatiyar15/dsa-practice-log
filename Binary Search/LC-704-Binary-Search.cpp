/*

Logic:
We are given a sorted array and a target value.  
We need to find the index of the target using binary search.

1. Initialize two pointers: start = 0, end = n-1.
2. While start <= end:
   - Find mid = start + (end - start)/2 (to avoid overflow).
   - If nums[mid] == target, return mid.
   - If target > nums[mid], move right (start = mid+1).
   - Else move left (end = mid-1).
3. If target not found, return -1.

Example:  
Input: nums = [-1,0,3,5,9,12], target = 9  
Output: 4  

Time Complexity: O(log n) – search space halves each step.  
Space Complexity: O(1) – constant extra space used.

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
};
