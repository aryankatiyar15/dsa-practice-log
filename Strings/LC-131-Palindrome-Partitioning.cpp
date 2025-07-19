class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result; // Stores all the valid palindrome partitions
        vector<string> path;           // Current partition path
        partition(s, 0, path, result); // Start recursive backtracking from index 0
        return result;
    }

private:
    // Recursive helper function to explore partitions
    void partition(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        int n = s.length();
        
        // If we've reached the end of the string, we found a valid partition
        if (start == n) {
            result.push_back(path); // Add the current path to the result
        } else {
            // Try all possible substrings starting from 'start' index
            for (int i = start; i < n; i++) {
                // Check if substring s[start..i] is a palindrome
                if (isPalindrome(s, start, i)) {
                    // If yes, include it in the path
                    path.push_back(s.substr(start, i - start + 1));
                    // Recurse to explore further partitioning from index i+1
                    partition(s, i + 1, path, result);
                    // Backtrack and remove the last added substring
                    path.pop_back();
                }
            }
        }
    }

    // Utility function to check if the substring s[l..r] is a palindrome
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false; // Not a palindrome if mismatch found
            }
        }
        return true;
    }
};
