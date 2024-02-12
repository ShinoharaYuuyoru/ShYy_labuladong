// O(n2). TLE.
class Solution {
   public:
    int trap(vector<int>& height) {
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            int l_max = 0, r_max = 0;
            for (int j = 0; j <= i; j++) {
                l_max = max(l_max, height[j]);
            }
            for (int j = i; j < height.size(); j++) {
                r_max = max(r_max, height[j]);
            }

            res += min(l_max, r_max) - height[i];
        }
        return res;
    }
};

// O(n). Optimized with LUT, AC.
class Solution {
   public:
    int trap(vector<int>& height) {
        int res = 0;

        vector<int> l_max_v(height.size()), r_max_v(height.size());
        int curr_l_max = 0, curr_r_max = 0;
        int l_p = 0, r_p = height.size() - 1;
        while (l_p < height.size()) {
            curr_l_max = max(curr_l_max, height[l_p]);
            l_max_v[l_p] = curr_l_max;
            l_p++;

            curr_r_max = max(curr_r_max, height[r_p]);
            r_max_v[r_p] = curr_r_max;
            r_p--;
        }

        for (int i = 0; i < height.size(); i++) {
            res += min(l_max_v[i], r_max_v[i]) - height[i];
        }
        return res;
    }
};

// T O(n), S O(1). AC
class Solution {
   public:
    int trap(vector<int>& height) {
        int res = 0;
        int l_max = 0, r_max = 0;
        int l_p = 0, r_p = height.size() - 1;
        while (l_p < r_p) {
            l_max = max(l_max, height[l_p]);
            r_max = max(r_max, height[r_p]);

            if (l_max < r_max) {
                res += l_max - height[l_p];
                l_p++;
            } else {
                res += r_max - height[r_p];
                r_p--;
            }
        }
        return res;
    }
};