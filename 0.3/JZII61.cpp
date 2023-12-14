class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i] + nums2[0],
                     nums1[i],
                     0});
        }

        int i = 0;
        while (i < k && !pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            res.push_back({curr[1],
                           nums2[curr[2]]});
            i++;

            if (curr[2] < nums2.size() - 1) {
                pq.push({curr[1] + nums2[curr[2] + 1],
                         curr[1],
                         curr[2] + 1});
            }
        }
        return res;
    }
};