// GFG - Tower of Hanoi
// for small test cases you can print the steps for the disk movements else it will give TLE

class Solution {
public:
    int moves = 0; // Keeps track of total moves made during the process

    // Recursive helper function to solve Tower of Hanoi
    void solve(int n, int from, int to, int aux) {
        // Base Case: If there's only one disk, directly move it to the destination
        if (n == 1) {
            // cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
            moves++; // Count this move
            return;
        }

        // Step 1: Move top n-1 disks from 'from' rod to 'aux' rod using 'to' rod
        solve(n - 1, from, aux, to);

        // Step 2: Move the nth (largest) disk from 'from' rod to 'to' rod
        // cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
        moves++; // Count this move

        // Step 3: Move the n-1 disks from 'aux' rod to 'to' rod using 'from' rod
        solve(n - 1, aux, to, from);
    }

    // Main function to initiate the Tower of Hanoi process
    int towerOfHanoi(int n, int from, int to, int aux) {
        moves = 0;            // Reset move counter before starting
        solve(n, from, to, aux); // Begin solving the puzzle
        return moves;         // Return the total number of moves made
    }
};
