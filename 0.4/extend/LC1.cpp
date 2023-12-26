class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            auto check = table.find(diff);
            if (check != table.end()) {
                return {i, check->second};
            } else {
                table[nums[i]] = i;
            }
        }
        return vector<int>{};
    }
};