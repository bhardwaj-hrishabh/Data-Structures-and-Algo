// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk; // Stack to store operands

        for(int i = 0; i < tokens.size(); i++) {
            string token = tokens[i]; // Current token

            if(token.size() > 1 || isdigit(token[0])) { // If the token is a number (operand)
                stk.push(stoi(token)); // Push the operand onto the stack
                continue; // Continue to the next iteration
            }

            // If the token is an operator
            int num2 = stk.top(); // Get the second operand from the top of the stack
            stk.pop(); // Pop the second operand
            int num1 = stk.top(); // Get the first operand from the top of the stack
            stk.pop(); // Pop the first operand

            int result = 0; // Variable to store the result of the operation

            // Perform the operation based on the operator
            if(token == "+") {
                result = num1 + num2;
            } else if(token == "-") {
                result = num1 - num2;
            } else if(token == "*") {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }

            stk.push(result); // Push the result of the operation onto the stack
        }

        return stk.top(); // Return the final result from the top of the stack
    }
};
