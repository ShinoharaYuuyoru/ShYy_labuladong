class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }

        memo = vector<vector<int> >(m + 1, vector<int>(n + 1, -1));
        return dp(s1, 0, s2, 0, s3);
    }

   private:
    vector<vector<int> > memo;

    bool dp(string& s1, int i, string& s2, int j, string& s3) {
        int k = i + j;
        if (k == s3.size()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j] == 1 ? true : false;
        }

        bool res = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            res = dp(s1, i + 1, s2, j, s3);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            res = res || dp(s1, i, s2, j + 1, s3);
        }

        memo[i][j] = (res == true) ? 1 : 0;
        return res;
    }
};