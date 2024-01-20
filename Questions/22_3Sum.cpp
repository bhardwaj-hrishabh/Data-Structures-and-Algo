// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Initialize the result vector to store triplets.
        sort(nums.begin(), nums.end()); // Sort the input array to simplify the solution.

        for(int i = 0; i < nums.size() - 1; i++) {
            int low = i + 1, high = nums.size() - 1; // Set two pointers, 'low' and 'high'.

            while(low < high) {
                if(nums[i] + nums[low] + nums[high] < 0) {
                    low++; // Move 'low' pointer to the right to increase the sum.
                }
                else if(nums[i] + nums[low] + nums[high] > 0) {
                    high--; // Move 'high' pointer to the left to decrease the sum.
                }
                else {
                    // Found a triplet with sum 0, add it to the result vector.
                    ans.push_back({nums[i], nums[low], nums[high]});

                    // Skip duplicate elements to avoid duplicate triplets.
                    int tempIndex = low;
                    int tempIndex2 = high;
                    while(low < high && nums[low] == nums[tempIndex])
                        low++;
                    while(low < high && nums[high] == nums[tempIndex2])
                        high--;
                }
            }

            // Skip duplicate elements for the outer loop to avoid duplicate triplets.
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return ans; // Return the vector containing all unique triplets.
    }
};
