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
    int diameterOfBinaryTree(TreeNode* root) {
        max_depth(root);
        return max_diameter;
    }

   private:
    int max_diameter = 0;
    int max_depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_max_depth = max_depth(root->left);
        int right_max_depth = max_depth(root->right);
        int curr_diameter = (left_max_depth - 1) + 1 + 1 + (right_max_depth - 1);
        max_diameter = max(max_diameter, curr_diameter);

        return 1 + max(left_max_depth, right_max_depth);
    }
};