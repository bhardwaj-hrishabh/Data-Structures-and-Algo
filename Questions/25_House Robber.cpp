// https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Base cases for small inputs
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        // Initialize an array to store the maximum robbery amount at each house
        vector<int> dp(n, 0);

        // Initialize the first two elements of the array based on the base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Dynamic Programming loop to fill in the rest of the array
        for (int i = 2; i < n; ++i) {
            // The maximum robbery amount at the current house is the maximum of:
            // 1. The amount robbed at the previous house (dp[i-1])
            // 2. The amount robbed two houses ago plus the current house's value (dp[i-2] + nums[i])
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        // Return the maximum robbery amount at the last house
        return dp[n-1];
    }
};
