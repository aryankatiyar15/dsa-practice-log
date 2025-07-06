class Solution {
public:
    // This function checks if there's a subset with the given sum
    bool subset_sum(vector<int> arr, int sum, int n) {
        // Creating a 2D DP table, dp[i][j] = true means sum j is possible with first i elements
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // A sum of 0 is always possible with any number of elements (by choosing none)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table using bottom-up approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    // Option 1: Include current element
                    // Option 2: Exclude current element
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    // Current element too big to include, skip it
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer is whether sum is possible using all n elements
        return dp[n][sum];
    }

    // Main function: checks if array can be partitioned into two equal subsets
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        // Step 1: Find total sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // If sum is odd, can't split into two equal parts
        if (sum % 2 != 0)
            return false;

        // Step 2: Check if there's a subset with sum = totalSum / 2
        return subset_sum(nums, sum / 2, n);
    }
};
