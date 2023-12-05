class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> s_ugly_num(n + 1, 0);
        vector<long long int> curr_ugly_nums(primes.size(), 1);
        vector<int> p_n(primes.size(), 1);

        int p = 1;
        while (p <= n) {
            long long int min_s_ugly = *min_element(curr_ugly_nums.begin(), curr_ugly_nums.end());
            s_ugly_num[p] = min_s_ugly;
            p++;
            for (int i = 0; i < curr_ugly_nums.size(); i++) {
                if (curr_ugly_nums[i] == min_s_ugly) {
                    curr_ugly_nums[i] = (long long int)s_ugly_num[p_n[i]] * primes[i];
                    p_n[i]++;
                }
            }
        }
        return s_ugly_num[n];
    }
};

// Priority queue.
class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> s_ugly(n + 1);

        priority_queue<vector<long long int>, vector<vector<long long int> >, greater<vector<long long int> > > pq;
        for (int i = 0; i < primes.size(); i++) {
            pq.push({1, primes[i], 1});
        }

        int p = 1;
        while (p <= n) {
            vector<long long int> tuple = pq.top();
            pq.pop();
            long long int product = tuple[0];
            long long int prime = tuple[1];
            long long int p_n = tuple[2];
            if (product > s_ugly[p - 1]) {
                s_ugly[p] = product;
                p++;
            }

            pq.push({(long long int)s_ugly[p_n] * prime, prime, p_n + 1});
        }
        return s_ugly[n];
    }
};