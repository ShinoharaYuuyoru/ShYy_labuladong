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
    int maxDepth(TreeNode* root) {
        traverse(0, root);
        return max_depth;
    }

   private:
    int max_depth = 0;

    void traverse(int depth, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        depth++;
        if (depth > max_depth) {
            max_depth = depth;
        }
        traverse(depth, root->left);
        traverse(depth, root->right);
    }
};

class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }
};