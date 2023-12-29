class Solution {
   public:
    bool isPalindrome(string s) {
        string ss;
        for (auto c : s) {
            if (isalnum(c)) {
                ss.push_back(tolower(c));
            }
        }

        int left = 0, right = ss.size() - 1;
        while (left < right) {
            if (ss[left] != ss[right]) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};