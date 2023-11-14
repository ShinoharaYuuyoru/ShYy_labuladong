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
    vector<int> preorderTraversal(TreeNode* root) {
        preorder_traverse(root);

        return preorder;
    }

   private:
    vector<int> preorder;

    void preorder_traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        preorder.push_back(root->val);
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
};