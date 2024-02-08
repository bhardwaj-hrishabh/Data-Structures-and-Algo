// https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08 


class Solution {
public:
    // Function to check if a number is a perfect square
    bool isPerfectSquare(int num) {
        int sqrtNum = sqrt(num); // Calculate the square root of the number

        return sqrtNum * sqrtNum == num; // Check if the square of the square root equals the original number
    }

    // Function to find the least number of perfect square numbers that sum up to n
    int numSquares(int n) {
        // Check if n is already a perfect square
        if (isPerfectSquare(n)) {
            return 1; // If n is a perfect square, return 1 because n itself is the answer
        }

        // Iterate through all possible perfect square numbers less than or equal to n
        for (int i = 1; i * i <= n; i++) {
            // Check if n - i^2 (where i is a perfect square) is also a perfect square
            if (isPerfectSquare(n - i * i)) {
                return 2; // If n - i^2 is a perfect square, return 2 because it can be expressed as the sum of two perfect squares (i^2 and (n - i^2))
            }
        }

        // Reduce n by removing all factors of 4
        while (n % 4 == 0) {
            n /= 4;
        }

        // If n leaves a remainder of 7 when divided by 8, return 4
        if (n % 8 == 7) {
            return 4;
        }

        return 3; // If none of the above conditions are met, return 3 as the least number of perfect square numbers
    }
};
