// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Create an unordered_map to store the frequency of each element in 'nums'
        unordered_map<int, int> mp;
        int count  = 0;

        // Loop through the elements in 'nums'
        for(int i = 0; i<nums.size(); i++){
            // If the element is not found in the map, increment the counter
            if(mp.find(nums[i]) == mp.end())
                count++;

            // Increment the frequency of the current element in the map
            mp[nums[i]]++;
        }

        vector<int> temp;
        vector<vector<int>>ans;

        // Continue until all unique elements are used
        while(count > 0){
            // Clear the temporary vector for a new row
            temp.clear();
            
            // Iterate through the elements in the map
            for (auto &it : mp) {
                // If the frequency of an element is non-zero
                if (it.second != 0) {
                    // Add the element to the current row, decrement its frequency
                    temp.push_back(it.first);
                    it.second--;
                    // If the frequency becomes zero, decrement the counter
                    if (it.second == 0)
                        count--;
                }
            }
            // Add the current row to the result matrix
            ans.push_back(temp);
        }

        return ans;
    }
};
