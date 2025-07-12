class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Create a DP array to track whether each index is reachable from the start
        vector<bool> dp(n, false); 
        
        // Step 2: The first index is always reachable (we start here)
        dp[0] = true;

        // Step 3: Loop through every index in the array
        for (int index = 0; index < n; index++) {
            
            // Step 4: If the current index is reachable
            if (dp[index]) {
                
                // Step 5: Try all possible jumps from this index within the range nums[index]
                for (int jump = 1; jump <= nums[index]; jump++) {
                    
                    // Step 6: If the new index is inside the array bounds, mark it as reachable
                    if (index + jump < n) {
                        dp[index + jump] = true;
                    }
                }
            }
        }

        // Step 7: If the last index is marked reachable, return true
        return dp[n - 1];
    }
};
