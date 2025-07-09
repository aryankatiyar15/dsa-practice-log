class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Total sum of all elements in the array
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Let's say S1 - S2 = target and S1 + S2 = total
        // => S1 = (target + total) / 2
        // If this is not possible (odd or negative), no solution exists
        if ((target + total) % 2 != 0 || abs(target) > total)
            return 0;

        int sum = (target + total) / 2;

        // dp[i][j] will store the number of ways to reach sum 'j' using first 'i' elements
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // There's always one way to make sum 0 — by choosing nothing!
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        // Build the table row by row
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                // Can we include the current number nums[i - 1]?
                if (nums[i - 1] <= j) {
                    // Include it or skip it — sum of both choices
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    // Too big to include — we have no choice but to skip it
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The final answer is number of ways to make 'sum' using all elements
        return dp[n][sum];
    }
};
