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
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        get_zigzag(root->left, 0, 1);
        get_zigzag(root->right, 1, 1);

        return max_zigzag;
    }

   private:
    int max_zigzag = 0;

    void get_zigzag(TreeNode* root, int l_or_r, int zigzag) {
        if (root == nullptr) {
            return;
        }

        max_zigzag = max(max_zigzag, zigzag);

        if (l_or_r == 0) {
            get_zigzag(root->left, 0, 1);
            get_zigzag(root->right, 1, zigzag + 1);
        } else {
            get_zigzag(root->left, 0, zigzag + 1);
            get_zigzag(root->right, 1, 1);
        }
    }
};