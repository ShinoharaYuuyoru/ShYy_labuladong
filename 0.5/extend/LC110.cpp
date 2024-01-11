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
    bool isBalanced(TreeNode* root) {
        tree_depth(root);
        return res;
    }

   private:
    bool res = true;
    int tree_depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (res == false) {
            return 0;
        }

        int left_depth = tree_depth(root->left);
        int right_depth = tree_depth(root->right);
        if (abs(left_depth - right_depth) > 1) {
            res = false;
        }
        return max(left_depth, right_depth) + 1;
    }
};