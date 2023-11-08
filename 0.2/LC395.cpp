class Solution {
   public:
    int longestSubstring(string s, int k) {
        if (k == 1) {
            return s.size();
        }
        if (s.size() < k) {
            return 0;
        }

        int res = 0;
        for (int n = 0; n < 26; n++) {
            int temp_res = longet_substring_with_n_char(s, k, n + 1);
            res = temp_res > res ? temp_res : res;
        }

        return res;
    }

    int longet_substring_with_n_char(string s, int k, int n) {
        int max = 0;

        int curr_n = 0;
        vector<int> table(26);
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (table[s[right] - 'a'] == 0) {
                curr_n++;
            }
            table[s[right] - 'a']++;
            right++;

            while (curr_n > n) {
                table[s[left] - 'a']--;
                if (table[s[left] - 'a'] == 0) {
                    curr_n--;
                }
                left++;
            }

            if (curr_n == n) {
                bool check = true;
                for (int i = 0; i < 26; i++) {
                    if (table[i] == 0) {
                        continue;
                    } else {
                        if (table[i] < k) {
                            check = false;
                            break;
                        }
                    }
                }
                if (check == true) {
                    max = (right - left) > max ? (right - left) : max;
                }
            }
        }

        return max;
    }
};