// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23


class Solution {
public:
    // Function to find the maximum length of a concatenated string with unique characters
    int maxLength(vector<string>& arr) {
        int result = 0;
        // Start DFS with an empty path and index 0
        dfs(arr, "", 0, result);
        return result;
    }

private:
    // Depth-first search function to explore all possible combinations
    void dfs(const vector<string>& arr, const string& path, int idx, int& result) {
        // Check if the current path has unique characters
        if (isUniqueChars(path)) {
            // Update the result with the maximum length found so far
            result = max(result, static_cast<int>(path.length()));
        }

        // If reached the end of the array or path has duplicate characters, return
        if (idx == arr.size() || !isUniqueChars(path)) {
            return;
        }

        // Explore all possible combinations by appending strings from the array
        for (int i = idx; i < arr.size(); i++) {
            dfs(arr, path + arr[i], i + 1, result);
        }
    }

    // Helper function to check if a string has unique characters
    bool isUniqueChars(const string& s) {
        unordered_set<char> set;
        // Iterate through characters in the string
        for (char c : s) {
            // If character is already in the set, it's not unique
            if (set.count(c)) {
                return false;
            }
            // Add character to the set
            set.insert(c);
        }
        // All characters are unique
        return true;
    }
};
