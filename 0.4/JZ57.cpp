class Solution {
   public:
    vector<int> twoSum(vector<int>& price, int target) {
        vector<int> res(2);
        int left = 0, right = price.size() - 1;
        while (left < right) {
            int sum = price[left] + price[right];
            if (sum < target) {
                left++;
            } else if (sum == target) {
                res[0] = price[left];
                res[1] = price[right];
                break;
            } else {
                right--;
            }
        }
        return res;
    }
};