class NumArray {
   public:
    NumArray(vector<int>& nums) {
        part_sum.resize(nums.size() + 1);
        part_sum[0] = 0;
        for (unsigned int i = 1; i < nums.size() + 1; i++) {
            part_sum[i] = part_sum[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right) {
        return part_sum[right + 1] - part_sum[left];
    }

   private:
    vector<int> part_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */