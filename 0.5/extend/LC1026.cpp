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
// Traverse, backtrack
class Solution {
   public:
    int maxAncestorDiff(TreeNode* root) {
        backtrack(root);
        return res;
    }

   private:
    int res = 0;
    vector<int> ancestors;

    void backtrack(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        for (auto num : ancestors) {
            int diff = abs(root->val - num);
            if (diff > res) {
                res = diff;
            }
        }

        ancestors.push_back(root->val);
        backtrack(root->left);
        backtrack(root->right);
        ancestors.pop_back();
    }
};

// Divide
class Solution {
   public:
    int maxAncestorDiff(TreeNode* root) {
        get_tree_min_max(root);
        return res;
    }

   private:
    int res = 0;

    pair<int, int> get_tree_min_max(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(INT_MAX, INT_MIN);
        }

        pair<int, int> left_min_max = get_tree_min_max(root->left);
        pair<int, int> right_min_max = get_tree_min_max(root->right);
        int root_min = min(root->val, min(left_min_max.first, right_min_max.first));
        int root_max = max(root->val, max(left_min_max.second, right_min_max.second));
        res = max(res, max(root_max - root->val, root->val - root_min));
        return make_pair(root_min, root_max);
    }
};