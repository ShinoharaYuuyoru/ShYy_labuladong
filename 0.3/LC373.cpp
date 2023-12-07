class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int k_c = 0;

        priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int>, vector<int>)>> pq(
            [](vector<int> a, vector<int> b) {
                int sum1 = a[0] + a[1];
                int sum2 = b[0] + b[1];
                if (sum1 == sum2) {
                    return a[0] > b[0];
                } else {
                    return sum1 > sum2;
                }
            });
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i], nums2[0], 0});
        }
        while (k_c < k && !pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            res.push_back({curr[0], curr[1]});
            k_c++;

            int curr_p2 = curr[2];
            if (curr_p2 < nums2.size() - 1) {
                pq.push({curr[0], nums2[curr_p2 + 1], curr_p2 + 1});
            }
        }
        return res;
    }
};