// https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03



class Solution {
public:
    
    int solve(vector<int>& arr, int k, vector<int>& dp, int i) {
        int n = arr.size();
        
        // Base case: If the current index is at the end of the array, return 0
        if (i == arr.size()) 
            return 0;
        
        // If the result for the current index is already calculated, return it
        if (dp[i] != -1)
            return dp[i];
        
        int ans = INT_MIN; 
        int maxans = INT_MIN; 
        int len = 0;
        
        // Iterate over the next k elements or until the end of the array
        for (int j = i; j < min(i + k, n); j++) {
            len++; // Increment the length of the current subarray
            ans = max(ans, arr[j]); // Update the maximum value encountered in the current subarray
            int sum = len * ans + solve(arr, k, dp, j + 1); // Calculate the sum of the current subarray and recursively call solve for the remaining elements
            maxans = max(maxans, sum); // Update the maximum sum of subarrays found so far
        }
        
        // Memoize the result for the current index
        return dp[i] = maxans;
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Initialize a vector to store the results for each index
        vector<int> dp(arr.size() + 1, -1);
        
        // Call the solve function to find the maximum sum after partitioning
        return solve(arr, k, dp, 0);
    }
};
