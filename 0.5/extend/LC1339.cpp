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
    int maxProduct(TreeNode* root) {
        traverse(root);
        dc(root);
        return (int)(max_product % 1000000007);
    }

   private:
    long long int tree_sum = 0;
    long long int max_product = LLONG_MIN;
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        tree_sum += root->val;
        traverse(root->left);
        traverse(root->right);
    }

    long long int dc(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        long long int left_tree_sum = dc(root->left);
        long long int right_tree_sum = dc(root->right);
        max_product = max(max_product, (tree_sum - left_tree_sum) * left_tree_sum);
        max_product = max(max_product, (tree_sum - right_tree_sum) * right_tree_sum);

        return (root->val + left_tree_sum + right_tree_sum);
    }
};

// Optimized.
class Solution {
   public:
    int maxProduct(TreeNode* root) {
        tree_sum = get_tree_sum(root);
        get_tree_sum(root);
        return (int)(res % 1000000007);
    }

   private:
    long long int tree_sum = 0;
    long long int res;

    long long int get_tree_sum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        long long int left_sum = get_tree_sum(root->left);
        long long int right_sum = get_tree_sum(root->right);
        long long int root_sum = left_sum + right_sum + root->val;
        res = max(res, (tree_sum - root_sum) * root_sum);
        return root_sum;
    }
};