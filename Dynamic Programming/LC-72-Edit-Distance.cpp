class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        // Creating a 2D DP table to store edit distances
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: converting word1[0...i] to empty string (all deletions)
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }

        // Base case: converting empty string to word2[0...j] (all insertions)
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        // Filling the DP table with optimal substructure logic
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, no operation needed
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Otherwise, take the min of insert, delete, or replace
                    dp[i][j] = min({
                        dp[i - 1][j - 1], // Replace
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j]      // Delete
                    }) + 1; // One operation added
                }
            }
        }

        //Final answer: min operations to convert word1 to word2
        return dp[m][n];
    }
};
