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
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

// 720ms. Spend too long but not TLE.
class FindElements {
   public:
    FindElements(TreeNode* root) {
        tree = root;
        if (tree != nullptr) {
            tree->val = 0;
            recover_tree(tree);
        }
    }

    bool find(int target) {
        find_flag = false;
        traverse(tree, target);
        return find_flag;
    }

   private:
    TreeNode* tree;
    bool find_flag = false;
    void recover_tree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr) {
            root->left->val = 2 * root->val + 1;
        }
        if (root->right != nullptr) {
            root->right->val = 2 * root->val + 2;
        }
        recover_tree(root->left);
        recover_tree(root->right);
    }

    void traverse(TreeNode* root, int target) {
        if (root == nullptr) {
            return;
        }
        if (find_flag == true) {
            return;
        }

        if (root->val == target) {
            find_flag = true;
            return;
        }
        traverse(root->left, target);
        traverse(root->right, target);
    }
};

// Optimized with unordered_set.
class FindElements {
   public:
    FindElements(TreeNode* root) {
        recover_tree(root, 0);
    }

    bool find(int target) {
        return (bool)(values.count(target));
    }

   private:
    unordered_set<int> values;
    void recover_tree(TreeNode* root, int value) {
        if (root == nullptr) {
            return;
        }

        root->val = value;
        values.insert(value);

        recover_tree(root->left, 2 * value + 1);
        recover_tree(root->right, 2 * value + 2);
    }
};