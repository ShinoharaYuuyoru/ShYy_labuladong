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
// Hash all values and filter.
class Solution {
   public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);

        vector<int> res;
        int max_freq = 0;
        for (auto h : hash) {
            int num = h.first;
            int freq = h.second;
            if (freq > max_freq) {
                res.clear();
                res.push_back(num);
                max_freq = freq;
            } else if (freq == max_freq) {
                res.push_back(num);
            } else {
                ;
            }
        }

        return res;
    }

   private:
    unordered_map<int, int> hash;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        hash[root->val]++;
        traverse(root->left);
        traverse(root->right);
    }
};

// Use BST property, count mode(the most frequently occurred element) during the traversal.
class Solution {
   public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return res;
    }

   private:
    TreeNode* pre;
    vector<int> res;
    int curr_cnt = 0;
    int max_cnt = 0;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        traverse(root->left);
        if (pre == nullptr) {
            res.push_back(root->val);
            curr_cnt = 1;
            max_cnt = 1;
        } else {
            if (root->val == pre->val) {
                curr_cnt++;
                if (curr_cnt > max_cnt) {
                    res.clear();
                    res.push_back(root->val);
                    max_cnt = curr_cnt;
                } else if (curr_cnt == max_cnt) {
                    res.push_back(root->val);
                } else {
                    ;
                }
            } else {
                curr_cnt = 1;
                if (curr_cnt == max_cnt) {
                    res.push_back(root->val);
                }
            }
        }
        pre = root;
        traverse(root->right);
    }
};