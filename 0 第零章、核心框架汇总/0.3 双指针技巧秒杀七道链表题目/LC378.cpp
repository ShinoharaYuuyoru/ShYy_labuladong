class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < matrix.size(); i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int k_c = 0;
        int res = 0;
        while (!pq.empty() && k_c < k) {
            vector<int> curr = pq.top();
            pq.pop();
            res = curr[0];
            k_c++;

            int curr_i = curr[1], curr_j = curr[2];
            if (curr_j + 1 < matrix.size()) {
                pq.push({matrix[curr_i][curr_j + 1], curr_i, curr_j + 1});
            }
        }
        return res;
    }
};