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

// BST in-order traverse, which is the ascending order.
class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size() - 1);
    }

    TreeNode* build_tree(vector<int>& nums, int left_margin, int right_margin) {
        if (left_margin > right_margin) {
            return nullptr;
        }

        int mid = (left_margin + right_margin) / 2;
        TreeNode* left_tree_root = build_tree(nums, left_margin, mid - 1);
        TreeNode* root = new TreeNode(nums[curr]);
        curr++;
        TreeNode* right_tree_root = build_tree(nums, mid + 1, right_margin);
        root->left = left_tree_root;
        root->right = right_tree_root;
        return root;
    }

   private:
    int curr = 0;
};

// Divide and conquer to build BST directly.
class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size());
    }

    TreeNode* build_tree(vector<int>& nums, int left_margin, int right_margin) {
        if (left_margin == right_margin) {
            return nullptr;
        }

        int mid = (left_margin + right_margin) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build_tree(nums, left_margin, mid);
        root->right = build_tree(nums, mid + 1, right_margin);
        return root;
    }
};