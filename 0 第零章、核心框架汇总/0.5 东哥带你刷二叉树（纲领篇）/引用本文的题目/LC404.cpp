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

// Traverse
class Solution {
   public:
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root, false);
        return res;
    }

   private:
    int res = 0;

    void traverse(TreeNode* root, bool is_left) {
        if (root == nullptr) {
            return;
        }

        if (is_left) {
            if (root->left == nullptr && root->right == nullptr) {
                res += root->val;
            }
        }
        traverse(root->left, true);
        traverse(root->right, false);
    }
};

// Divide
class Solution {
   public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_res = sumOfLeftLeaves(root->left);
        int right_res = sumOfLeftLeaves(root->right);

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            return left_res + right_res + root->left->val;
        } else {
            return left_res + right_res;
        }
    }
};