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
    int sumRootToLeaf(TreeNode* root) {
        backtrack(root, 0);
        return sum;
    }

   private:
    int sum = 0;

    void backtrack(TreeNode* root, int num) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            sum += (num << 1) + root->val;
            return;
        }

        int curr_num = (num << 1) + root->val;
        backtrack(root->left, curr_num);
        backtrack(root->right, curr_num);
    }
};