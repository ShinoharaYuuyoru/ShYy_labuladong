class Solution {
   public:
    int countHighestScoreNodes(vector<int>& parents) {
        build_tree(parents);
        traverse(0);

        return res;
    }

   private:
    int node_num = 0;
    vector<vector<int> > tree;
    long long int max_score = 0;
    int res = 0;

    void build_tree(vector<int>& parents) {
        node_num = parents.size();
        tree.resize(node_num, vector<int>(2, -1));

        for (int i = 0; i < node_num; i++) {
            if (parents[i] == -1) {
                continue;
            } else {
                if (tree[parents[i]][0] == -1) {
                    tree[parents[i]][0] = i;
                } else {
                    tree[parents[i]][1] = i;
                }
            }
        }
    }

    int traverse(int root) {
        if (root == -1) {
            return 0;
        }

        int left_tree_node_num = traverse(tree[root][0]);
        int right_tree_node_num = traverse(tree[root][1]);

        int root_node_num = left_tree_node_num + right_tree_node_num + 1;
        int remain_node_num = node_num - root_node_num;

        long long int score = 1;
        if (left_tree_node_num != 0) {
            score *= left_tree_node_num;
        }
        if (right_tree_node_num != 0) {
            score *= right_tree_node_num;
        }
        if (remain_node_num != 0) {
            score *= remain_node_num;
        }

        if (score > max_score) {
            max_score = score;
            res = 1;
        } else if (score == max_score) {
            res++;
        } else {
            ;
        }

        return root_node_num;
    }
};