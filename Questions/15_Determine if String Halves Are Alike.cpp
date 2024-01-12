// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int cntLeftVow = 0;
        int cntRightVow = 0;
        
        // Convert all characters to lowercase for case-insensitive comparison
        for (auto& x : s) { 
            x = tolower(x); 
        }

        // Count vowels in the left half of the string
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u')
                cntLeftVow++;
        }

        // Count vowels in the right half of the string
        for(int i = s.length() / 2; i < s.length(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u')
                cntRightVow++;
        }

        // Check if the counts of vowels in both halves are equal
        if(cntLeftVow == cntRightVow)
            return true;
        return false;
    }

};
