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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start >= pre_end) {
            return nullptr;
        }

        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);

        int root_idx_in_inorder = in_start;
        for (int i = in_start; i < in_end; i++) {
            if (inorder[i] == root_val) {
                root_idx_in_inorder = i;
                break;
            }
        }
        int left_tree_size = root_idx_in_inorder - in_start + 1;

        root->left = build(preorder, pre_start + 1, pre_start + left_tree_size, inorder, in_start, root_idx_in_inorder);
        root->right = build(preorder, pre_start + left_tree_size, pre_end, inorder, root_idx_in_inorder + 1, in_end);

        return root;
    }
};