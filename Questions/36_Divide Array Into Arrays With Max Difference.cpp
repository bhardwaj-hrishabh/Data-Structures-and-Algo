// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the input vector 'nums' in ascending order
        vector<vector<int>> ans; // Initialize a 2D vector 'ans' to store the divided arrays

        for(int i = 0; i < nums.size()-2; i += 3) { // Iterate over 'nums' with a step size of 3
            if((nums[i + 2] - nums[i]) <= k) { // Check if the difference between the third and first elements of the current group is less than or equal to 'k'
                ans.push_back({nums[i], nums[i + 1], nums[i + 2]}); // If the condition is met, add the current group as a vector to 'ans'
            } else {
                return {}; // If the condition is not met, return an empty vector (indicating no valid groups)
            }
        }
        return ans; // Return the divided arrays stored in 'ans'
    }
};
