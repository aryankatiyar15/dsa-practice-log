class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        // Create a memo table where dp[i] represents the min jumps needed from index i
        vector<int> dp(n, -1);

        // Start solving from index 0
        return solve(nums, 0, dp);
    }

    int solve(vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();

        // Base case: If we're already at the last index, no more jumps needed!
        if (index >= n - 1) return 0;

        // If already computed, reuse the result
        if (dp[index] != -1) return dp[index];

        int minJumps = INT_MAX;

        // Try all jumps from 1 to nums[index]
        for (int jump = 1; jump <= nums[index]; jump++) {
            int nextIndex = index + jump;

            // Stay within bounds
            if (nextIndex < n) {
                int subProblem = solve(nums, nextIndex, dp);

                // Update the minimum jumps if this path is better
                if (subProblem != INT_MAX) {
                    minJumps = min(minJumps, 1 + subProblem);
                }
            }
        }

        // Store the result in dp table for future reference
        return dp[index] = minJumps;
    }
};
