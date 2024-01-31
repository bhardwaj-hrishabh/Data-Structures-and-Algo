// https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); // Initialize result vector with zeros
        stack<int> s; // Stack to store indices

        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current temperature is higher than the temperature at the index on top of the stack
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int prevIndex = s.top(); // Get the index of the temperature at the top of the stack
                s.pop(); // Pop the index from the stack
                result[prevIndex] = i - prevIndex; // Calculate the number of days until warmer temperature and update result
            }
            s.push(i); // Push the current index onto the stack
        }

        return result; // Return the result vector containing the number of days until warmer temperature for each day
    }
};
