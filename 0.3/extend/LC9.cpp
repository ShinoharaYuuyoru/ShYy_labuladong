class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int x_temp = x;
        long long int y = 0;
        while (x_temp != 0) {
            int digit = x_temp % 10;
            y = y * 10 + digit;
            x_temp = x_temp / 10;
        }
        return y == x;
    }
};
