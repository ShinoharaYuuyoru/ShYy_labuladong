class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> ugly_list(n + 1, 0);
        int p2 = 1, p3 = 1, p5 = 1;
        int ugly_2 = 1, ugly_3 = 1, ugly_5 = 1;

        int i = 1;
        while (i <= n) {
            int min_val = min(min(ugly_2, ugly_3), ugly_5);
            ugly_list[i] = min_val;
            i++;

            if (min_val == ugly_2) {
                ugly_2 = ugly_list[p2] * 2;
                p2++;
            }
            if (min_val == ugly_3) {
                ugly_3 = ugly_list[p3] * 3;
                p3++;
            }
            if (min_val == ugly_5) {
                ugly_5 = ugly_list[p5] * 5;
                p5++;
            }
        }
        return ugly_list[n];
    }
};

class Solution {
   public:
    int nthUglyNumber(int n) {
        priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
        pq.push(1);
        int i = 1;
        int last_ugly = 0;
        while (i <= n) {
            long long int curr = pq.top();
            pq.pop();
            if (curr == last_ugly) {
                continue;
            }
            last_ugly = curr;
            i++;

            long long int mul_2 = curr * 2;
            long long int mul_3 = curr * 3;
            long long int mul_5 = curr * 5;
            pq.push(mul_2);
            pq.push(mul_3);
            pq.push(mul_5);
        }
        return last_ugly;
    }
};