// https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string temp = "123456789"; // Define a string containing all possible digits in sequential order
        vector<int> ans; // Initialize a vector to store the sequential digits within the given range
        int digitsLow = to_string(low).size(); // Calculate the number of digits in the lower bound 'low'
        int digitsHigh = to_string(high).size(); // Calculate the number of digits in the upper bound 'high'

        // Iterate over the possible number of digits within the given range
        for (int i = digitsLow; i <= digitsHigh; i++) {
            // Iterate over the starting index 'j' within the string 'temp'
            // Note: We use '9 - i' as the upper limit for 'j' to ensure that we don't exceed the bounds of 'temp'
            for (int j = 0; j <= 9 - i; j++) {
                // Extract a substring of length 'i' starting from index 'j' in the string 'temp'
                // Convert the substring into an integer 'num'
                int num = stoi(temp.substr(j, i));
                
                // Check if the extracted number 'num' falls within the given range [low, high]
                if (num >= low && num <= high) {
                    // If 'num' is within the range, add it to the result vector 'ans'
                    ans.push_back(num);
                }
            }
        }

        return ans; // Return the vector containing sequential digits within the given range
    }
};
