// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {
        // Base cases: If there are 0 or 1 stairs, there is only one way (0 steps or 1 step).
        if (n <= 2)
            return n;

        // Initialize variables to keep track of previous two results and current result
        int prev2 = 1; // Number of ways to climb 1 stair
        int prev1 = 2; // Number of ways to climb 2 stairs
        int curr;      // Variable to store the current result

        // Loop to calculate the number of ways to climb stairs for values greater than 2
        for (int i = 3; i <= n; i++) {
            // The number of ways to climb 'i' stairs is the sum of ways to climb 'i-1' and 'i-2' stairs
            curr = prev1 + prev2;

            // Update the previous two results for the next iteration
            prev2 = prev1;
            prev1 = curr;
        }

        // The final result is the number of ways to climb 'n' stairs
        return curr;
    }
};
