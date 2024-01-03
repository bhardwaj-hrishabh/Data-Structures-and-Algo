// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRow = 0;
        int currRow = 0;
        int sum = 0;

        // Iterate through each row of the bank
        for(int i = 0; i<bank.size(); i++){
            // Reset the current count of security devices for each row
            currRow = 0;

            // Iterate through each column of the current row
            for(int j = 0; j < bank[0].size(); j++){
                if(bank[i][j] == '1'){
                    currRow++; // Count the number of security devices in the current row
                }
            }

            // If there are security devices in the current row
            if(currRow != 0){
                // Accumulate the product of current count and previous count
                sum += currRow * prevRow;
                prevRow = currRow;// Update the previous count for the next iteration
            }
        }
        // Return the total number of laser
        return sum;
    }
};
