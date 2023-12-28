class Solution {
   public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l_max = 0, r_max = 0;
        int l_p = 0, r_p = height.size() - 1;
        while (l_p < r_p) {
            int curr_area = min(height[l_p], height[r_p]) * (r_p - l_p);
            res = max(res, curr_area);

            if (height[l_p] < height[r_p]) {
                l_p++;
            } else {
                r_p--;
            }
        }
        return res;
    }
};