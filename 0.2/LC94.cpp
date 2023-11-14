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
    vector<int> inorderTraversal(TreeNode* root) {
        inorder_traverse(root);

        return inorder;
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