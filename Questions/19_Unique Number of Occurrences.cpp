// https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17

class Solution {
public:
    
    bool uniqueOccurrences(vector<int>& arr) {
        // Map to store the frequency of each element
        map<int, int> mp1;

        // Map to store the frequency of occurrences
        map<int, int> mp2;

        // Count the frequency of each element in 'arr'
        for (auto i : arr) {
            mp1[i]++;
        }

        // Check the frequency of occurrences
        for (auto i : mp1) {
            mp2[i.second]++;

            // If the same frequency is encountered more than once, return false
            if (mp2[i.second] > 1) {
                return false;
            }
        }

        // All occurrences are unique, return true
        return true;
    }
};
