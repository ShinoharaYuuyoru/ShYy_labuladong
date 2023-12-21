class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum < target) {
                left++;
            } else if (sum == target) {
                res[0] = left;
                res[1] = right;
                break;
            } else {
                right--;
            }
        }

        return res;
    }
};