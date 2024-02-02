// https://www.geeksforgeeks.org/problems/implement-atoi/1


int atoi(string s) {
    // Your code here

    bool neg = 0; // Initialize a boolean variable to track if the number is negative

    // Check if the first character of the string is a minus sign '-'
    if (s[0] == '-')
        neg = 1; // If true, set the boolean variable 'neg' to true (indicating the number is negative)

    int num = 0, st; // Initialize an integer variable to store the converted number and a starting index variable

    // Set the starting index 'st' based on the sign of the number (0 if positive, 1 if negative)
    st = (neg == 0) ? 0 : 1;

    // Iterate over the characters in the string starting from the starting index 'st'
    for (int i = st; i < s.length(); i++) {
        // Check if the current character is a digit (0-9)
        if (s[i] >= '0' && s[i] <= '9') {
            // If true, update the number by multiplying the current number by 10 and adding the digit value
            num = (num * 10) + (s[i] - '0');
        } else {
            // If the current character is not a digit, return -1 (indicating invalid input)
            return -1;
        }
    }

    // Return the final converted number with the correct sign based on 'neg'
    return (neg == 0) ? num : -num;
}
