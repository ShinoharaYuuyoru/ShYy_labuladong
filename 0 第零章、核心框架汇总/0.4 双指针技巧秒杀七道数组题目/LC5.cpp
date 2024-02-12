class Solution {
   public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            string res_odd = get_max_palidrome_size(s, i, i);
            string res_even = get_max_palidrome_size(s, i, i + 1);
            if (res_odd.size() > res.size()) {
                res = res_odd;
            }
            if (res_even.size() > res.size()) {
                res = res_even;
            }
        }
        return res;
    }

    string get_max_palidrome_size(string s, int l, int r) {
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r]) {
                break;
            }
            l--;
            r++;
        }
        return s.substr(l + 1, (r - 1) - (l + 1) + 1);
    }
};