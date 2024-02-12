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
    int sumNumbers(TreeNode* root) {
        traverse(root, 0);
        return sum;
    }

   private:
    int sum = 0;

    void traverse(TreeNode* root, int base_val) {
        if (root == nullptr) {
            return;
        }

        int curr_val = base_val * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += curr_val;
            return;
        }
        traverse(root->left, curr_val);
        traverse(root->right, curr_val);
    }
};