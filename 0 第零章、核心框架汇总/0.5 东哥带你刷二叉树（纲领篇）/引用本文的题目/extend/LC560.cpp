// O(n2).
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        part_sum.resize(nums.size() + 1);
        for (unsigned int i = 0; i < nums.size(); i++) {
            part_sum[i + 1] = part_sum[i] + nums[i];
        }

        int res = 0;
        for (unsigned int i = 0; i < part_sum.size(); i++) {
            for (unsigned int j = i + 1; j < part_sum.size(); j++) {
                if (part_sum[j] - part_sum[i] == k) {
                    res++;
                }
            }
        }
        return res;
    }

   private:
    vector<int> part_sum;
};

// O(n). Optimized with hash.
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        unordered_map<int, int> hash;
        hash[0] = 1;
        int pre_sum = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {
            pre_sum += nums[i];

            int need = pre_sum - k;
            if (hash.count(need) != 0) {
                res += hash[need];
            }

            if (hash.count(pre_sum) == 0) {
                hash[pre_sum] = 1;
            } else {
                hash[pre_sum]++;
            }
        }

        return res;
    }
};