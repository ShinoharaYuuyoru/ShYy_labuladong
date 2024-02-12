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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool root_deleted = traverse(root, target);
        if (root_deleted) {
            return nullptr;
        } else {
            return root;
        }
    }

   private:
    bool traverse(TreeNode* root, int target) {
        if (root == nullptr) {
            return true;
        }

        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return true;
        }
        bool left_child_deleted = traverse(root->left, target);
        if (left_child_deleted) {
            root->left = nullptr;
        }
        bool right_child_deleted = traverse(root->right, target);
        if (right_child_deleted) {
            root->right = nullptr;
        }
        if (left_child_deleted && right_child_deleted && root->val == target) {
            return true;
        }
        return false;
    }
};

// Optimized.
class Solution {
   public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) {
            return nullptr;
        }

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }
        return root;
    }
};