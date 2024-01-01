// https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort greed factor and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());


        int count = 0;
        int i=0, j=0;


        while(i < g.size() && j < s.size()){
            //If the current cookie is large enough, satisfy the child
            if(g[i] <= s[j]){
                count++;
                i++;
            }
            // Move to the next cookies, regardless of whether it satisfies the current child
            j++;
        }
        return count;
    }
};
