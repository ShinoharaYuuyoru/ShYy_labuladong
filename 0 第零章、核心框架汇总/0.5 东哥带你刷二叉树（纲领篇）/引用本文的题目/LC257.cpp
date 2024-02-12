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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<string> left_str = binaryTreePaths(root->left);
        vector<string> right_str = binaryTreePaths(root->right);
        string temp = to_string(root->val);

        vector<string> all_str = left_str;
        all_str.insert(all_str.end(), right_str.begin(), right_str.end());

        if (all_str.size() == 0) {
            all_str.push_back(temp);
        } else {
            for (auto& str : all_str) {
                str = temp + "->" + str;
            }
        }

        // vector<string> all_str;
        // if(left_str.size() == 0 && right_str.size() == 0){
        //     all_str.push_back(temp);
        // }
        // else{
        //     string tt = temp + "->";
        //     for(auto s : left_str){
        //         all_str.push_back(tt + s);
        //     }
        //     for(auto s : right_str){
        //         all_str.push_back(tt + s);
        //     }
        // }

        return all_str;
    }
};