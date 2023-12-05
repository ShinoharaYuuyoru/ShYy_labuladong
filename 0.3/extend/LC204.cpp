// TLE. O(n * sqrt(n))
class Solution {
   public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime(i) == true) {
                res++;
            }
        }

        return res;
    }

   private:
    bool is_prime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

// AC. Strict O(nlog logn); loose O(nlogn)
class Solution {
   public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i] == true) {
                res++;
                for (long long int j = (long long int)i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return res;
    }
};