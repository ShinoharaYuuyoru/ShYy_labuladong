class Solution {
   public:
    bool isPalindrome(string s) {
        string proc;
        for (auto c : s) {
            if (isalnum(c)) {
                proc.push_back(tolower(c));
            }
        }

        if (proc.size() == 0) {
            return true;
        }
        unsigned int left = 0;
        unsigned int right = proc.size() - 1;
        while (left < right) {
            if (proc[left] != proc[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};