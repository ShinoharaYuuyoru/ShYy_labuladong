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
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return max_sum_bst;
    }

   private:
    int max_sum_bst = 0;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        check_bst_and_calc(root);
        // traverse(root->left);
        // traverse(root->right);
    }

    // vector, [0] is_bst, [1] tree_max_val, [2] tree_min_val, [3] bst_sum
    vector<int> check_bst_and_calc(TreeNode* root) {
        if (root == nullptr) {
            return {1, INT_MIN, INT_MAX, 0};
        }

        vector<int> left_calc = check_bst_and_calc(root->left);
        vector<int> right_calc = check_bst_and_calc(root->right);
        vector<int> res(4);
        if ((left_calc[0] == 1 && right_calc[0] == 1) &&
            root->val > left_calc[1] && root->val < right_calc[2]) {
            res[0] = 1;
            res[1] = max(right_calc[1], root->val);
            res[2] = min(left_calc[2], root->val);
            res[3] = root->val + left_calc[3] + right_calc[3];
            max_sum_bst = max(max_sum_bst, res[3]);
        } else {
            res[0] = 0;
        }
        return res;
    }
};