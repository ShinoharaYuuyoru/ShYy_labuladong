class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 1;
        int dup_flag = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
                dup_flag = 0;
            } else {
                if (dup_flag == 0) {
                    slow++;
                    nums[slow] = nums[fast];
                    dup_flag = 1;
                }
            }

            fast++;
        }

        return slow + 1;
    }
};