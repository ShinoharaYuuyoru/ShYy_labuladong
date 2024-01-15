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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        traverse(root, {}, 0, targetSum);
        return res;
    }

   private:
    vector<vector<int>> res;

    void traverse(TreeNode* root, vector<int> curr_list, int curr_sum, int target_sum) {
        if (root == nullptr) {
            return;
        }

        int sum = curr_sum + root->val;
        curr_list.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target_sum) {
                res.push_back(curr_list);
                return;
            }
        }

        traverse(root->left, curr_list, sum, target_sum);
        traverse(root->right, curr_list, sum, target_sum);
    }
};