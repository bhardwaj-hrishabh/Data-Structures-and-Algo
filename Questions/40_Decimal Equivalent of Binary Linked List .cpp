// https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1



class Solution
{
    public:
        
        long long unsigned int decimalValue(Node *head) {
            // Initialize modulo value for handling large numbers
            long mod = 1e9 + 7;
        
            long long unsigned int ans = 0;
        
            // Traverse the linked list while head is not NULL
            while (head) {
                // Update the result using bitwise left shift and addition
                // Formula: (ans * 2 % mod + head->next) % mod
                // Explanation: 
                // 1. Multiply the current result by 2 to perform a bitwise left shift (ans * 2)
                // 2. Calculate modulo of the result to prevent overflow (ans * 2 % mod)
                // 3. Add the current bit value represented by head->next (head->next)
                // 4. Calculate modulo of the updated result again to prevent overflow ((ans * 2 % mod + head->data) % mod)
                ans = (ans * 2 % mod + head->data) % mod;
        
                // Move to the next node in the linked list
                head = head->next;
            }
        

            return ans;
        }

};
