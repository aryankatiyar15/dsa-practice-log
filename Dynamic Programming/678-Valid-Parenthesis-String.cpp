// Tabulation-based solution to check if a string with '(', ')' and '*' is valid
class Solution {
public:
    bool checkValidString(string s) {
        // dp[i][j] represents: Is it possible to balance the string from index i with j unmatched '('
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        
        // Base case: At the end of the string, zero unmatched '(' means valid
        dp[s.size()][0] = 1;

        // Process the string from the end to the beginning
        for (int ind = s.size() - 1; ind >= 0; ind--) {
            // Try all possible opening bracket counts
            for (int open = 0; open < s.size(); open++) {
                bool valid = false;

                if (s[ind] == '*') {
                    // Try '*'' as '(', ')', or empty
                    valid |= dp[ind + 1][open + 1]; // Treat as '('
                    if (open > 0) valid |= dp[ind + 1][open - 1]; // Treat as ')'
                    valid |= dp[ind + 1][open]; // Treat as empty
                } else if (s[ind] == '(') {
                    valid |= dp[ind + 1][open + 1]; // Add a new '('
                } else { // s[ind] == ')'
                    if (open > 0) valid |= dp[ind + 1][open - 1]; // Match with a previous '('
                }

                dp[ind][open] = valid;
            }
        }

        // We return whether we can balance the whole string with zero unmatched '(' at the start
        return dp[0][0];
    }
};
