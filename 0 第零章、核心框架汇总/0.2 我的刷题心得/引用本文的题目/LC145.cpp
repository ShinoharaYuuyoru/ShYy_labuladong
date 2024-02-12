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
    vector<int> postorderTraversal(TreeNode* root) {
        postorder_traverse(root);

        return postorder;
    }

   private:
    vector<int> postorder;

    void postorder_traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        postorder_traverse(root->left);
        postorder_traverse(root->right);
        postorder.push_back(root->val);
    }
};