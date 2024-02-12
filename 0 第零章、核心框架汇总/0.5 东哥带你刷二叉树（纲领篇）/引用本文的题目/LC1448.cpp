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
    int goodNodes(TreeNode* root) {
        traverse(root, INT_MIN);
        return good_nodes_num;
    }

   private:
    int good_nodes_num = 0;

    void traverse(TreeNode* root, int max_val) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= max_val) {
            good_nodes_num++;
        }
        int new_max_val = max(root->val, max_val);
        traverse(root->left, new_max_val);
        traverse(root->right, new_max_val);
    }
};