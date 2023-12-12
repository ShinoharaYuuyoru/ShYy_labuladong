class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int i = 0, j = nums.size() - 1, k = nums.size() - 1;
        while (i <= j) {
            int num_left_square = nums[i] * nums[i];
            int num_right_square = nums[j] * nums[j];
            if (num_left_square > num_right_square) {
                res[k] = num_left_square;
                i++;
                k--;
            } else {
                res[k] = num_right_square;
                j--;
                k--;
            }
        }

        return res;
    }
};