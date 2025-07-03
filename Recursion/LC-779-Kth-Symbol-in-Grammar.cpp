// LeetCode 779 - Kth Symbol in Grammar
// Problem:
// In a special grammar, we start with 0.
// Every 0 becomes "01", and every 1 becomes "10" in the next row.
// Given row n and position k (1-indexed), find the kth symbol.

// Example: 
// n = 1:     0
// n = 2:     0 1
// n = 3:     0 1 1 0                   
// n = 4:     0 1 1 0 1 0 0 1
// and so on...

// Approach:
// - Each row is built recursively from the previous one.
// - The first half of the row is the same as the previous row.
// - The second half is the flipped version. 
// - So we use recursion and check if k is in the first or second half.

class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case: row 1, only one symbol which is 0
        if (n == 1) return 0;

        // Midpoint of current row
        int mid = pow(2, n - 1) / 2;

        if (k <= mid) {
            // If k is in the first half, it's the same as in the previous row
            return kthGrammar(n - 1, k);
        } else {
            // If in the second half, it's the flipped version
            return !kthGrammar(n - 1, k - mid);
        }
    }
};
