/*
 Problem: Search a 2D Matrix II (LeetCode 240 style, but can also solve LC 74 differently)

 Logic (my thought process):
We are given a matrix with these properties:
1. Each row is sorted in ascending order.
2. Each column is sorted in ascending order.

This gives us a neat trick:  
Start from the top-right corner and eliminate one row or one column in each step.

Steps:
1. Begin at (0, cols-1) → top-right cell.
2. If matrix[i][j] == target → found, return true.
3. If matrix[i][j] > target → move left (since all numbers below are even bigger).
4. If matrix[i][j] < target → move down (since all numbers left are even smaller).
5. Continue until we either find target or go out of bounds.

Example:  
Matrix = [ [1,3,5,7], [10,11,16,20], [23,30,34,60] ], target = 16  
Start at (0,3) = 7 → 7 < 16 → move down  
(1,3) = 20 → 20 > 16 → move left  
(1,2) = 16 → found 

⏱ Time Complexity: O(m + n) → worst case we move across one row and one column.  
💾 Space Complexity: O(1) → only two pointers used.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int i = 0, j = col - 1;  // start from top-right corner

        while (i < row && j >= 0) {
            if (matrix[i][j] == target)  // found target
                return true;

            if (matrix[i][j] > target)   // current too big → move left
                j--;
            else                         // current too small → move down
                i++;
        }
        return false; // not found in matrix
    }
};
