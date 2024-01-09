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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        int root_val = preorder[0];
        int i = 0;
        for (; i < preorder.size(); i++) {
            if (preorder[i] > root_val) {
                break;
            }
        }
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + i);
        vector<int> right_preorder(preorder.begin() + i, preorder.end());
        TreeNode* left_root = bstFromPreorder(left_preorder);
        TreeNode* right_root = bstFromPreorder(right_preorder);

        TreeNode* curr_root = new TreeNode(root_val);
        curr_root->left = left_root;
        curr_root->right = right_root;
        return curr_root;
    }
};