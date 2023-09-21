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
    bool hasPathSum(TreeNode* root, int targetSum) {
        target_sum = targetSum;
        traverse(root);

        return result;
    }

   private:
    int target_sum = 0;
    int curr_sum = 0;
    bool result = false;
    void traverse(TreeNode* root) {
        if (result == true) {
            return;
        }
        if (root == nullptr) {
            return;
        }

        curr_sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (curr_sum == target_sum) {
                result = true;
                return;
            }
        }
        traverse(root->left);
        traverse(root->right);
        curr_sum -= root->val;
    }
};

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            return true;
        }

        bool is_left_ok = hasPathSum(root->left, targetSum - root->val);
        bool is_right_ok = hasPathSum(root->right, targetSum - root->val);
        return is_left_ok || is_right_ok;
    }
};