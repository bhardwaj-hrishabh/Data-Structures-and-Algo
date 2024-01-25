// https://leetcode.com/problems/longest-common-subsequence/description/


class Solution {
    vector<vector<int>> dp; // Initialize a 2D vector for memoization of subproblem solutions.
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.length(), n = t2.length(); // Get the lengths of the input strings.
        dp.resize(m + 1, vector<int>(n + 1, 0)); // Resize the 2D vector to store solutions for subproblems.

        // Iterate over the lengths of substrings of t1 and t2 to find the longest common subsequence.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t1[i - 1] == t2[j - 1]) { // If the characters match:
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // Increment the length of the common subsequence.
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]); // If characters don't match, update based on previous subproblems.
                }
            }
        }
        return dp[m][n]; // Return the length of the longest common subsequence.
    }
};
