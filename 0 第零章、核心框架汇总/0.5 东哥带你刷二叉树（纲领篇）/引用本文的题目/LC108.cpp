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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_bst(nums, 0, nums.size() - 1);
    }

   private:
    TreeNode* build_bst(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build_bst(nums, left, mid - 1);
        root->right = build_bst(nums, mid + 1, right);
        return root;
    }
};