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
    int pseudoPalindromicPaths(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        traverse(root);
        return res;
    }

   private:
    int res = 0;
    unordered_set<int> hash;

    void traverse(TreeNode* root) {
        if (hash.count(root->val) == 1) {
            hash.erase(root->val);
        } else {
            hash.insert(root->val);
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (hash.size() == 0 || hash.size() == 1) {
                res++;
            }
        } else {
            if (root->left != nullptr) {
                traverse(root->left);
            }
            if (root->right != nullptr) {
                traverse(root->right);
            }
        }
        if (hash.count(root->val) == 1) {
            hash.erase(root->val);
        } else {
            hash.insert(root->val);
        }
    }
};

// Optimized with vector
class Solution {
   public:
    int pseudoPalindromicPaths(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        traverse(root);
        return res;
    }

   private:
    int res = 0;
    vector<int> hash = vector<int>(10, 0);

    void traverse(TreeNode* root) {
        if (hash[root->val] == 1) {
            hash[root->val] = 0;
        } else {
            hash[root->val] = 1;
        }

        if (root->left == nullptr && root->right == nullptr) {
            int sum = 0;
            for (unsigned int i = 0; i < 10; i++) {
                sum += hash[i];
            }
            if (sum == 0 || sum == 1) {
                res++;
            }
        } else {
            if (root->left != nullptr) {
                traverse(root->left);
            }
            if (root->right != nullptr) {
                traverse(root->right);
            }
        }

        if (hash[root->val] == 1) {
            hash[root->val] = 0;
        } else {
            hash[root->val] = 1;
        }
    }
};

// More optimized with bit operation.
//  `(n & (n - 1))` to check if `n == 0` or `n` has only one `1` bit.
class Solution {
   public:
    int pseudoPalindromicPaths(TreeNode* root) {
        traverse(root);
        return res;
    }

   private:
    int res = 0;
    int hash = 0;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        hash = hash ^ (1 << root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if ((hash & (hash - 1)) == 0) {
                res++;
            }
        }

        traverse(root->left);
        traverse(root->right);
        hash = hash ^ (1 << root->val);
    }
};