class Solution {
public:
    // Function to compute the Shortest Common Supersequence (SCS)
    // using the Longest Common Subsequence (LCS) table for reconstruction
    string LCS(string str1, string str2, int m, int n) {
        string s = "";

        // Create a 2D DP table for storing LCS lengths
        int t[m+1][n+1];

        // Base case: if either string is empty, LCS is 0
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }

        // Fill the LCS DP table
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i-1] == str2[j-1]) {
                    // Characters match: include in LCS
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    // No match: take the max from top or left cell
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        // Now reconstruct the Shortest Common Supersequence from the DP table
        int i = m, j = n;

        // Traverse backwards through the table to build the result string
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                // If characters match, it’s part of both strings, add once
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(t[i-1][j] > t[i][j-1]) {
                // Character from str1 is not in LCS, add it
                s.push_back(str1[i-1]);
                i--;
            }
            else {
                // Character from str2 is not in LCS, add it
                s.push_back(str2[j-1]);
                j--;
            }
        }

        // Add remaining characters from str1 (if any)
        while(i > 0) {
            s.push_back(str1[i-1]);
            i--;
        }

        // Add remaining characters from str2 (if any)
        while(j > 0) {
            s.push_back(str2[j-1]);
            j--;
        }

        // Reverse the constructed string to get the correct order
        reverse(s.begin(), s.end());

        return s;
    }

    // Main function that returns the Shortest Common Supersequence
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        string ans = LCS(str1, str2, m, n);
        return ans;
    }
};
