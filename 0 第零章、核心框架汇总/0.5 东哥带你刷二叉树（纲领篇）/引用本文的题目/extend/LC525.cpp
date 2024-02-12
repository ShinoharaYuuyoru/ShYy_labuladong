class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        vector<int> pre_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                pre_sum[i + 1] = pre_sum[i] - 1;
            } else {
                pre_sum[i + 1] = pre_sum[i] + 1;
            }
        }

        int res = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < pre_sum.size(); i++) {
            if (hash.count(pre_sum[i]) != 0) {
                res = max(res, i - hash[pre_sum[i]]);
            } else {
                hash[pre_sum[i]] = i;
            }
        }
        return res;
    }
};