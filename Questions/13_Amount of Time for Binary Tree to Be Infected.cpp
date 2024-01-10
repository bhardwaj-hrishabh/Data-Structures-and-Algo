// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDistance = 0;

    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return maxDistance;
    }

    int traverse(TreeNode* root, int start) {
        // Initialize a variable to store the depth
        int depth = 0;

        // Base case: If the current node is nullptr, return 0 depth
        if (root == nullptr) {
            return depth;
        }

        // Recursively traverse the left and right subtrees
        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        // Check conditions based on the value of the current node
        if (root->val == start) {
            // If the current node matches the start value, update maxDistance and set depth to -1
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        } else if (leftDepth >= 0 && rightDepth >= 0) {
            // If both left and right subtrees are valid, calculate depth
            depth = max(leftDepth, rightDepth) + 1;
        } else {
            // If one subtree is invalid, calculate distance and update maxDistance
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            // Update depth based on the smaller subtree
            depth = min(leftDepth, rightDepth) - 1;
        }

        // Return the calculated depth
        return depth;
    }
};
