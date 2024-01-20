// https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size();

        // Arrays to store the left and right indices of the nearest smaller element for each element.
        vector<int> left(length, -1);
        vector<int> right(length, length);

        // Stack to track indices of elements in the array.
        stack<int> stk;

        // Find the left indices of the nearest smaller element for each element.
        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        // Reset the stack for the next iteration.
        stk = stack<int>();

        // Find the right indices of the nearest smaller element for each element.
        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        // Calculate the sum based on the left and right indices.
        ll sum = 0;

        for (int i = 0; i < length; ++i) {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};
