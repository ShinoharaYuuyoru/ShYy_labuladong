class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1;
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
                res++;
            }
            fast++;
        }
        return res;
    }
};