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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }

        inorder_traverse(root);

        int left = 0;
        int right = inorder.size() - 1;
        while (left < right) {
            int left_val = inorder[left];
            int right_val = inorder[right];
            int sum = left_val + right_val;
            if (sum < k) {
                left++;
            } else if (sum == k) {
                return true;
            } else {
                right--;
            }
        }

        return false;
    }

    void inorder_traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder_traverse(root->left);
        inorder.push_back(root->val);
        inorder_traverse(root->right);
    }

   private:
    vector<int> inorder;
};