// https://leetcode.com/problems/leaf-similar-trees/description/

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

    void inorder(TreeNode* root, vector<int>& v) {
        if (root != NULL) {
            // Traverse left subtree
            inorder(root->left, v);
            
            // If the current node is a leaf node (both left and right children are NULL), add its value to the vector
            if (root->left == NULL && root->right == NULL) {
                v.push_back(root->val);
            }

            // Traverse right subtree
            inorder(root->right, v);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        return v1 == v2;
    }
};
