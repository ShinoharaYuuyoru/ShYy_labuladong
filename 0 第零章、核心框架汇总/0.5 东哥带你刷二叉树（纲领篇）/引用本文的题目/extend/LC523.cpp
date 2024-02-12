class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Find i, j -> (pre_sum[j] - pre_sum[i]) % k == 0 && j - i >= 2.
        //  (pre_sum[j] - pre_sum[i]) % k == 0 -> pre_sum[j] % k == pre_sum[i] % k.

        vector<int> pre_sum(nums.size() + 1, 0);
        for (unsigned int i = 0; i < nums.size(); i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }

        unordered_map<int, int> hash;
        for (unsigned int i = 0; i < pre_sum.size(); i++) {
            int key = pre_sum[i] % k;
            if (hash.count(key) == 0) {
                hash[key] = i;  // Set mininum index.
            }
        }

        for (unsigned int i = 0; i < pre_sum.size(); i++) {
            int need = pre_sum[i] % k;
            if (hash.count(need) != 0) {
                if (i - hash[need] >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
};