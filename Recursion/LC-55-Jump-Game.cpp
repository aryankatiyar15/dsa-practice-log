class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;

        // Start the recursive check from index 0
        return solve(nums, index);
    }

    // Recursive function to check if we can reach the end from a given index
    bool solve(vector<int> &nums, int index) {
        int n = nums.size();

        // Base Case: If we've reached the last index, return true
        if (index == n - 1) return true;

        // Edge Case: If we go out of bounds, return false
        if (index >= n) return false;

        // Try all possible jumps from current index (from 1 to nums[index])
        for (int jump = 1; jump <= nums[index]; jump++) {
            
            // If any path from index + jump leads to the end, return true
            if (solve(nums, index + jump)) return true;
        }

        // If none of the jumps worked, return false
        return false;
    }
};

/*
 WHY THIS GIVES TLE (Time Limit Exceeded):

→ This is a plain recursive solution that checks all possible paths from each index.
→ It does not store or reuse the results of overlapping subproblems.
→ That leads to exponential time complexity: O(2^n) in the worst case.
→ As a result, it performs redundant computations and fails for large inputs (TLE on platforms like LeetCode).

 NOTE :

→ An optimized DP solution is implemented and saved in:
   Dynamic Programming/LC-55-Jump-Game.cpp
*/
