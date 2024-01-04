//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/ 

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int result = 0;

        // Count the frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it : mp){
            int freq = it.second;

            // If the frequency is 1, it's not possible
            if(freq == 1)
                return -1;

            else if(freq == 2 || freq == 3)
                result++;

            // Calculate operations based on the frequency
            else{
                if(freq %3 == 0){
                    result += (freq/3);
                }
                // If the remainder is 1 or 2 after dividing by 3
                else{
                    result += (freq/3) + 1;
                }
            }

        }
        return result;
    }
};
