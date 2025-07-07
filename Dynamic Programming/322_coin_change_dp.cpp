class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // Initialize a DP table of size (n+1) x (amount+1)
        // t[i][j] will represent the minimum number of coins needed to make amount 'j' using first 'i' coins
        vector<vector<int>> t(n + 1, vector<int>(amount + 1, 0));

        // If we have 0 coins, we can't form any amount except 0 → mark as "infinity" (amount+1 as a dummy infinity)
        for (int j = 0; j <= amount; j++)
            t[0][j] = amount + 1;

        // If the amount is 0, we need 0 coins regardless of how many coin types we have
        for (int i = 0; i <= n; i++)
            t[i][0] = 0;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    // We have 2 choices:
                    // 1. Include this coin (so we add 1 and look back by coin's value)
                    // 2. Exclude this coin (take previous result)
                    t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                } else {
                    // Can't include this coin, carry forward the previous result
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        // If result is greater than amount, that means it's not possible to form the amount
        return t[n][amount] > amount ? -1 : t[n][amount];
    }
};
