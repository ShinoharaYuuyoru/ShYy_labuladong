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
// Divide
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);
        return max(left_max_depth, right_max_depth) + 1;
    }
};

// Traverse
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        traverse(root, 1);
        return max_depth;
    }

   private:
    int max_depth = 0;

    void traverse(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            max_depth = max(max_depth, depth);
        }
        traverse(root->left, depth + 1);
        traverse(root->right, depth + 1);
    }
};