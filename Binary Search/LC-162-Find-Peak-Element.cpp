/*
Problem: Find Peak Element (LeetCode 162)

🔹 Logic:
We need to find a "peak element" such that nums[i] > nums[i-1] and nums[i] > nums[i+1].
Binary search works here because:
- If nums[mid] < nums[mid+1], then the peak must lie on the right side.
- Else, the peak lies on the left side (including mid).
We keep narrowing down until low == high, which gives the peak index.

Example:  
Input: nums = [1,2,1,3,5,6,4]  
Output: 5 (nums[5] = 6 is a peak)  

Time Complexity: O(log n) – binary search halves the search space.  
Space Complexity: O(1) – only variables used.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while(low < high) {
            mid = (low + high) / 2;
            if(nums[mid] < nums[mid+1]) {
                low = mid + 1;  // peak is on the right
            } else {
                high = mid;     // peak is on the left (or mid)
            }
        }
        return high; // or return low, since low == high
    }
};
