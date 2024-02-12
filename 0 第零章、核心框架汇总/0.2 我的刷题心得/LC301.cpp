class Solution {
   public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.empty() == true) {
            return res;
        }

        ss = s;
        traverse(0);

        int max_len = 0;
        for (auto curr_s : res) {
            if (curr_s.size() > max_len) {
                max_len = curr_s.size();
            }
        }
        unordered_set<string> hashmap;
        for (auto curr_s : res) {
            if (curr_s.size() == max_len) {
                hashmap.insert(curr_s);
            }
        }

        return vector<string>(hashmap.begin(), hashmap.end());
    }

   private:
    string ss;
    vector<string> res;
    string curr;

    void traverse(int idx) {
        if (idx == ss.size()) {
            if (is_curr_valid() == true) {
                res.push_back(curr);
            }
            return;
        }

        char c = ss[idx];
        if (c == '(') {
            // reserve
            curr.push_back(c);
            traverse(idx + 1);
            // remove
            curr.pop_back();
            traverse(idx + 1);
        } else if (c == ')') {
            if (is_curr_valid() == true) {
                // must remove
                traverse(idx + 1);
            } else {
                // reserve
                curr.push_back(c);
                traverse(idx + 1);
                // remove
                curr.pop_back();
                traverse(idx + 1);
            }
        } else {
            curr.push_back(c);
            traverse(idx + 1);
            curr.pop_back();
        }
    }

    bool is_curr_valid() {
        int stk = 0;
        for (auto c : curr) {
            if (c == '(') {
                stk++;
            } else if (c == ')') {
                stk--;
                if (stk < 0) {
                    return false;
                }
            } else {
                continue;
            }
        }

        if (stk == 0) {
            return true;
        } else {
            return false;
        }
    }
};
