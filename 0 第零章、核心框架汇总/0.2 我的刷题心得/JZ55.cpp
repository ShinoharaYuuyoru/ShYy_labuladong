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

// DAV
class Solution {
   public:
    int calculateDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth = calculateDepth(root->left);
        int right_depth = calculateDepth(root->right);

        return 1 + max(left_depth, right_depth);
    }
};

// Back tracking
class Solution {
   public:
    int calculateDepth(TreeNode* root) {
        traverse(root);
        return max_depth;
    }

   private:
    int curr_depth = 0;
    int max_depth = 0;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        curr_depth++;
        max_depth = max(max_depth, curr_depth);
        traverse(root->left);
        traverse(root->right);
        curr_depth--;
    }
};