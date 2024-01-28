// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/?envType=daily-question&envId=2024-01-28


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        map<int, int> mp; // Map to store the frequency of cumulative sums
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // Calculate cumulative sum
            if(sum == k) { // If current cumulative sum equals target k
                count++; // Increment count
            }
            if(mp.find(sum - k) != mp.end()) { // If there exists a cumulative sum such that (sum - k) equals some previously encountered cumulative sum
                count += mp[sum - k]; // Increment count by the frequency of that sum
            }
            mp[sum]++; // Update frequency of current cumulative sum
        }
        return count; // Return total count of subarrays with sum equal to k
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        // Iterate through each row as starting row
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> sum(matrix[0].size(), 0); // Initialize vector to store cumulative sums of elements in each column
            // Iterate through each row from starting row to end
            for(int j = i; j < matrix.size(); j++) {
                // Calculate cumulative sum of elements in each column within the range [i, j]
                for(int k = 0; k < matrix[0].size(); k++) {
                    sum[k] += matrix[j][k];
                }
                // Add count of subarrays with sum equal to target within the current range [i, j]
                count += subarraySum(sum, target);
            }
        }
        return count; // Return total count of submatrices with sum equal to target
    }
};
