/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
   public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this->target = target;

        traverse(original, cloned);
        return res;
    }

   private:
    TreeNode* target;
    TreeNode* res = nullptr;
    void traverse(TreeNode* original_root, TreeNode* cloned_root) {
        if (original_root == nullptr) {
            return;
        }

        if (res != nullptr) {
            return;
        }

        if (original_root == this->target) {
            res = cloned_root;
            return;
        }

        traverse(original_root->left, cloned_root->left);
        traverse(original_root->right, cloned_root->right);
    }
};