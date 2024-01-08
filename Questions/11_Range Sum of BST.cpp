// https://leetcode.com/problems/range-sum-of-bst/description/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
      if (!root)
          return 0;
  
      // Determine if the current node's value is within the specified range
      int currVal = (root->val >= low && root->val <= high) ? root->val : 0;
  
      // Recursively calculate the sum for the left and right subtrees
      int leftSum = rangeSumBST(root->left, low, high);
      int rightSum = rangeSumBST(root->right, low, high);
  
      // Return the sum of values within the range for the current subtree
      return currVal + leftSum + rightSum;
  }
};
