// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15

class Solution {
public:
   vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Create a map to store the counts of matches for each player
        map<int, pair<int, int>> mp;

        // Count the matches for each player
        for(auto i : matches){
            mp[i[0]].first++;     // Count wins for player i[0]
            mp[i[1]].second++;    // Count losses for player i[1]
        }

        // Initialize a 2D vector to store the winners and losers
        vector<vector<int>> ans(2);

        // Iterate through the map to determine winners and losers
        for(auto [i, v] : mp){
            if(v.second == 0) 
                ans[0].push_back(i); // Player i has no losses, add to winners
            else if(v.second == 1) 
                ans[1].push_back(i); // Player i has one loss, add to losers
        }

        // Return the result vector containing winners and losers
        return ans;
    }

};
