class Solution {
   public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }

   private:
    vector<vector<string>> res;
    deque<string> track;

    void backtrack(string &s, int start) {
        if (start == s.length()) {
            res.push_back(vector<string>(track.begin(), track.end()));
        }

        for (int i = start; i < s.length(); i++) {
            if (!is_palidrome(s, start, i)) {
                continue;
            } else {
                track.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1);
                track.pop_back();
            }
        }
    }

    bool is_palidrome(string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};