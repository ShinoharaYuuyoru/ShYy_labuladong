class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res(k);
        int l_p = 0, r_p = arr.size() - 1;
        while (r_p - l_p + 1 > k) {
            int l_abs = abs(arr[l_p] - x);
            int r_abs = abs(arr[r_p] - x);
            if (l_abs <= r_abs) {
                r_p--;
            } else {
                l_p++;
            }
        }
        for (int i = 0; i < res.size(); i++) {
            res[i] = arr[l_p];
            l_p++;
        }
        return res;
    }
};

// Binary search
class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start_p = bs_left_bound(arr, x);

        vector<int> res;
        int l_p = start_p - 1, r_p = start_p;
        while (r_p - l_p - 1 < k) {
            if (l_p == -1) {
                r_p++;
            } else if (r_p == arr.size()) {
                l_p--;
            } else {
                if (x - arr[l_p] <= arr[r_p] - x) {
                    l_p--;
                } else {
                    r_p++;
                }
            }
        }

        for (int i = 0; i < k; i++) {
            res.push_back(arr[l_p + 1]);
            l_p++;
        }
        return res;
    }

   private:
    int bs_left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};