// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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
    int ans = 0;

    void solution(TreeNode* root, int minVal, int maxVal) {
        // Base case: If the current node is null, return
        if (!root)
            return;

        // Update ans with the maximum difference between current node value and ancestor extremes
        ans = max(ans, max(abs(minVal - root->val), abs(maxVal - root->val)));

        // Update minVal and maxVal based on the current node's value
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        // Recursively traverse the left and right subtrees
        solution(root->left, minVal, maxVal);
        solution(root->right, minVal, maxVal);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
      
        int minVal = root->val;
        int maxVal = root->val;
        solution(root, minVal, maxVal);
        return ans;
    }

};
