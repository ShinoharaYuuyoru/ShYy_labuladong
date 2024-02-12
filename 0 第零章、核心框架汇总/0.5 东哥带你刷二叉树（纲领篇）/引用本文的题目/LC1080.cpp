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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool root_status = backtrack(root, 0, limit);
        if (root_status == false) {
            return nullptr;
        }
        return root;
    }

   private:
    bool backtrack(TreeNode* root, int sum, int limit) {
        if (root == nullptr) {
            return false;
        }

        int curr_sum = sum + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (curr_sum < limit) {
                return false;
            } else {
                return true;
            }
        }

        bool left_status = backtrack(root->left, curr_sum, limit);
        if (left_status == false) {
            root->left = nullptr;
        }
        bool right_status = backtrack(root->right, curr_sum, limit);
        if (right_status == false) {
            root->right = nullptr;
        }
        if (left_status == false && right_status == false) {
            return false;
        }

        return true;
    }
};

class Solution {
   public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (limit - root->val > 0) {
                return nullptr;
            } else {
                return root;
            }
        }

        TreeNode* left_node = sufficientSubset(root->left, limit - root->val);
        TreeNode* right_node = sufficientSubset(root->right, limit - root->val);
        if (left_node == nullptr && right_node == nullptr) {
            return nullptr;
        }
        root->left = left_node;
        root->right = right_node;
        return root;
    }
};