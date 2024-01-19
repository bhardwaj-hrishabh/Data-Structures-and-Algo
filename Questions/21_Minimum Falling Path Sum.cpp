// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size();

        // Initialize a 2D vector 'dp' to store the minimum falling path sum values
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // If there is only one row in the input, return the single element as the result
        if (n == 1) return nums[0][0];

        // Dynamic programming to calculate the minimum falling path sum
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // Calculate the minimum falling path sum at position (i, j)
                if (j < n && j > 1)
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + nums[i - 1][j - 1];
                if (j == n)
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + nums[i - 1][j - 1];
                if (j == 1)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + nums[i - 1][j - 1];
            }
        }

        // Find the minimum falling path sum in the last row of the 'dp' matrix
        int mini = INT_MAX;
        for (int i = 1; i <= n; i++) {
            mini = min(mini, dp[n][i]);
        }

        // Return the minimum falling path sum as the result
        return mini;
    }
};
