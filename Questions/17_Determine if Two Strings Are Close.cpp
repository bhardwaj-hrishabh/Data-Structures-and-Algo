// https://leetcode.com/problems/determine-if-two-strings-are-close/description/


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Check if the lengths of the two words are equal
        if (word1.length() != word2.length()) {
            return false;
        }

        // Initialize frequency maps and character sets for both words
        unordered_map<char, int> freq1, freq2;
        unordered_set<char> chars1, chars2;

        // Populate frequency map and character set for word1
        for (char c : word1) {
            freq1[c]++;
            chars1.insert(c);
        }

        // Populate frequency map and character set for word2
        for (char c : word2) {
            freq2[c]++;
            chars2.insert(c);
        }

        // Check if the sets of characters are the same
        if (chars1 != chars2) {
            return false;
        }

        // Check if the frequency maps are the same after sorting
        vector<int> freqCount1, freqCount2;
        for (const auto& entry : freq1) {
            freqCount1.push_back(entry.second);
        }

        for (const auto& entry : freq2) {
            freqCount2.push_back(entry.second);
        }

        // Sort the frequency counts for both words
        sort(freqCount1.begin(), freqCount1.end());
        sort(freqCount2.begin(), freqCount2.end());

        // Check if the sorted frequency counts are the same
        return freqCount1 == freqCount2;
    }
};
