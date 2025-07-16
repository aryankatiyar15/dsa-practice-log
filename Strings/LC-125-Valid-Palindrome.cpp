class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        // Traverse from both ends toward the center
        while (start <= end) {
            
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[start])) {
                start++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            // Compare characters in a case-insensitive manner
            if (tolower(s[start]) != tolower(s[end])) {
                return false; // Mismatch found, not a palindrome
            }

            // Move inward
            start++;
            end--;
        }

        // If we complete the loop, it's a valid palindrome
        return true;
    }
};
