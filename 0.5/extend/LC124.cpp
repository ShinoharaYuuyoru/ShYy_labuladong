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
    int maxPathSum(TreeNode* root) {
        sub_tree_max_sum(root);
        return max_path_sum;
    }

    int sub_tree_max_sum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_max_path_sum = max(0, sub_tree_max_sum(root->left));
        int right_max_path_sum = max(0, sub_tree_max_sum(root->right));

        if (left_max_path_sum + root->val + right_max_path_sum > max_path_sum) {
            max_path_sum = left_max_path_sum + root->val + right_max_path_sum;
        }
        return max(left_max_path_sum, right_max_path_sum) + root->val;
    }

   private:
    int max_path_sum = (0 - __INT32_MAX__) - 1;
};