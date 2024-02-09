// https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09 



class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(); // Number of elements in nums
        int maxi = 1; // Maximum size of the divisible subset
        int num = -1; // Last element added to the divisible subset
        vector<int> v; // Result vector to store the divisible subset
        sort(nums.begin(), nums.end()); // Sort the input array
        
        // Dynamic programming array to store the size of the largest divisible subset ending at each index
        vector<int> dp(n, 1);
        
        // Iterate through each element in the input array
        for(int i = 1; i < n; i++) {
            // Compare the current element with all previous elements
            for(int j = 0; j < i; j++) {
                // If nums[i] is divisible by nums[j], update dp[i] to dp[j] + 1 if it's larger
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    // Update the maximum size of the divisible subset
                    if(maxi < dp[i]) {
                        maxi = dp[i];
                    }
                }
            }
        }
        
        // Traverse the dynamic programming array in reverse order to find the elements in the divisible subset
        for(int i = n - 1; i >= 0; i--) {
            // If dp[i] is equal to the maximum size of the divisible subset and nums[i] is divisible by num or num is uninitialized
            if(maxi == dp[i] && (num == -1 || num % nums[i] == 0)) {
                // Add nums[i] to the result vector
                v.push_back(nums[i]);
                // Decrement the maximum size of the divisible subset
                maxi--;
                // Update num to nums[i]
                num = nums[i];
            }
        }
        
        return v; // Return the result vector containing the largest divisible subset
    }
};
