// LC1823 - Find the Winner of the Circular Game
// Solved using the classic Josephus Problem (recursive version)

class Solution {
public:
    // Main function to be called: returns the winner's number (1-based)
    int findTheWinner(int n, int k) {
        // The Josephus function returns 0-based index; we add 1 to make it 1-based
        return josephus(n, k) + 1;
    }

private:
    // Recursive Josephus function:
    // - n: number of people
    // - k: every k-th person will be removed
    // Returns: the 0-based position of the winner
    int josephus(int n, int k) {
        // Base case: only one person remains
        if (n == 1) return 0;

        // Recursive case:
        // The position returned by josephus(n - 1, k) is adjusted by adding k and modulo n
        return (josephus(n - 1, k) + k) % n;
    }
};
