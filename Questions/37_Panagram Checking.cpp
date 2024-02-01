// https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1



class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        set<char> ans; // Create a set to store unique characters
    
        // Iterate over each character in the string.
        for(auto i:s){
            // Check if the character is an alphabet (either lowercase or uppercase).
            if((i >= 'a' && i <= 'z') || (i >= 'A' && i<= 'Z')){
                ans.insert(tolower(i)); // Insert the lowercase version of the character into the set.
            }
        }
        
        // Check if the size of the set is equal to 26 (number of alphabets).
        if(ans.size() == 26){
            return true; // Return true if the string is a Pangram.
        }
        return false; // Return false if the string is not a Pangram.
    }
};
