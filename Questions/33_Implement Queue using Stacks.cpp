// https://leetcode.com/problems/implement-queue-using-stacks/description/



class MyQueue {
public:
    stack<int> s; // Main stack

    MyQueue() {
        
    }

    void push(int x) {
        stack<int> temp; // Temporary stack

        // Transfer elements from main stack to temporary stack
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }

        s.push(x); // Push the new element onto the main stack

        // Transfer elements back from temporary stack to main stack
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        int result = s.top(); // Get the top element of the main stack
        s.pop(); // Remove the top element
        return result; // Return the top element
    }

    int peek() {
        return s.top(); // Return the top element of the main stack
    }

    bool empty() {
        return s.empty(); // Check if the main stack is empty
    }
};
