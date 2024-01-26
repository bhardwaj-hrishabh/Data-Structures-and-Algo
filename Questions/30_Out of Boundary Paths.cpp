//https://leetcode.com/problems/out-of-boundary-paths/description/



class Solution {
public:
    int M = 1e9 + 7; // Define modulo constant for calculations

    // Recursive function to solve the problem
    int solve(int n, int m, int maxMove, int startRow, int startColumn) {

        // Base case: if the current position is out of bounds, return 1
        if (startColumn < 0 || startColumn >= n || startRow < 0 || startRow >= m)
            return 1;

        // Initialize variables to store the number of paths in each direction
        int up = 0, down = 0, left = 0, right = 0;

        // Recursive calls to explore each direction if maximum moves are remaining
        if (maxMove > 0) up = solve(n, m, maxMove - 1, startRow - 1, startColumn);
        if (maxMove > 0) down = solve(n, m, maxMove - 1, startRow + 1, startColumn);
        if (maxMove > 0) left = solve(n, m, maxMove - 1, startRow, startColumn - 1);
        if (maxMove > 0) right = solve(n, m, maxMove - 1, startRow, startColumn + 1);

        // Return the sum of paths in all directions modulo M
        return (up + down + left + right) % M;
    }

    // Function to find the number of paths
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // Call the solve function to find the number of paths
        return solve(n, m, maxMove, startRow, startColumn);
    }
};
