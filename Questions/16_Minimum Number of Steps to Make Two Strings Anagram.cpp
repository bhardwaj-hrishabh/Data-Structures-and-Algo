//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/ 

class Solution {
public:
    int minSteps(string s, string t) {
        if (s.length() != t.length()) {
            // Strings must be of the same length
            return -1;
        }

        // Count the occurrences of each character in both strings
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        for (char c : t) {
            charCount[c]--;
        }

        // Calculate the minimum number of steps needed
        int steps = 0;
        for (const auto& entry : charCount) {
            steps += abs(entry.second);
        }

        // Divide by 2 because each step involves replacing one character in t
        return steps / 2;
    }
};
