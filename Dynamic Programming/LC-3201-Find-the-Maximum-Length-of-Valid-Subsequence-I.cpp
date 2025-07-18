class Solution {
public:
    // dp[idx][targetParity + 1][taken][lastParity]
    // idx: current index in nums
    // targetParity: expected parity of adjacent sums (0 for even, 1 for odd, -1 if not set yet)
    // taken: whether we’ve started picking elements (0 = not yet, 1 = yes)
    // lastParity: parity (even/odd) of the last picked number (0 = even, 1 = odd)
    int dp[200005][3][2][2];

    // Recursive DP function to explore all valid subsequences
    int solve(vector<int>& nums, int idx, int targetParity, bool taken, int lastParity) {
        // Base Case: Reached end of array
        if (idx == nums.size()) return 0;

        // Check memoization table to avoid recomputation
        int& res = dp[idx][targetParity + 1][taken][lastParity];
        if (res != -1) return res;

        // Option 1: Skip current element
        int skip = solve(nums, idx + 1, targetParity, taken, lastParity);

        // Option 2: Try taking the current element if allowed
        int take = 0;
        int currentParity = nums[idx] % 2;  // 0 = even, 1 = odd

        if (!taken) {
            // First element — take freely and establish the sequence
            take = 1 + solve(nums, idx + 1, -1, true, currentParity);
        } else {
            // Check if sum of last and current element matches required parity
            int sumParity = (lastParity + currentParity) % 2;
            if (targetParity == -1 || sumParity == targetParity) {
                // Valid choice — extend subsequence
                take = 1 + solve(nums, idx + 1, sumParity, true, currentParity);
            }
        }

        // Store and return max of skipping or taking current element
        return res = max(skip, take);
    }

    // Driver function: initialize dp and launch recursion
    int maximumLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp)); // 🧽 Reset DP table
        return solve(nums, 0, -1, false, 0); // 🎬 Start recursion with no prior picks
    }
};
