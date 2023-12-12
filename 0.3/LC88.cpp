// Best solution.
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, p = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[p] = nums1[i];
                i--;
                p--;
            } else {
                nums1[p] = nums2[j];
                j--;
                p--;
            }
        }

        // Only nums2 may remain.
        while (j >= 0) {
            nums1[p] = nums2[j];
            j--;
            p--;
        }
    }
};

// Copy original nums1.
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_real(nums1.begin(), (nums1.begin() + m));

        int i = 0, j = 0, k = 0;
        while (1) {
            if (i == m) {
                while (j < n) {
                    nums1[k] = nums2[j];
                    j++;
                    k++;
                }
                break;
            }
            if (j == n) {
                while (i < m) {
                    nums1[k] = nums1_real[i];
                    i++;
                    k++;
                }
                break;
            }

            if (nums1_real[i] < nums2[j]) {
                nums1[k] = nums1_real[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
    }
};