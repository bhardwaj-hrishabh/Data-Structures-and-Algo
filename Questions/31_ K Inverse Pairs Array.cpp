//https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27



class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1000000007; // Define modulo constant

        // Initialize a 2D vector for dynamic programming
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

        // Iterate through 'n' and 'k' to compute the number of arrays with k inverse pairs
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j == 0) {
                    // Base case: If k is 0, there is only one array (sorted in ascending order)
                    dp[i][j] = 1;
                } else {
                    // Compute the value for dp[i][j] based on the recurrence relation
                    int val = (dp[i - 1][j] + MOD - (j - i >= 0 ? dp[i - 1][j - i] : 0)) % MOD;
                    dp[i][j] = (dp[i][j - 1] + val) % MOD;
                }
            }
        }

        // Return the computed value for dp[n][k]
        // Adjust the result by subtracting dp[n][k-1] to handle cases where k > 0
        return (dp[n][k] + MOD - (k > 0 ? dp[n][k - 1] : 0)) % MOD;
    }
};
