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
    int pathSum(TreeNode* root, int targetSum) {
        target_sum = targetSum;
        pre_sum_count[0] = 1;

        traverse(root);
        return res;
    }

   private:
    unordered_map<long long int, int> pre_sum_count;
    long long int pre_sum = 0;
    int target_sum = 0;
    int res = 0;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        pre_sum += root->val;

        if (pre_sum_count.count(pre_sum - target_sum) != 0) {
            res += pre_sum_count[pre_sum - target_sum];
        }

        if (pre_sum_count.count(pre_sum) == 0) {
            pre_sum_count[pre_sum] = 1;
        } else {
            pre_sum_count[pre_sum]++;
        }

        traverse(root->left);
        traverse(root->right);

        pre_sum_count[pre_sum]--;
        pre_sum -= root->val;
    }
};