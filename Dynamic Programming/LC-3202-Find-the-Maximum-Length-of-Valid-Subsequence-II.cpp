class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1; // at least each number is a valid subsequence

        // dp[i][mod] stores the longest valid subsequence ending at i with that mod
        vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1; // init: each number is a subsequence of length 1
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;

                // If we already have a valid seq ending at j with this mod, extend it
                int len = dp[j].count(mod) ? dp[j][mod] + 1 : 2; // either extend or start new pair
                dp[i][mod] = max(dp[i][mod], len);

                ans = max(ans, dp[i][mod]); // update the overall best
            }
        }

        return ans;
    }
};
