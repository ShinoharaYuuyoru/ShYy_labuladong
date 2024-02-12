class Solution {
   public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.size() == 0) {
            return {};
        }

        ss = s;
        traverse(0);

        unordered_set<string> hash;
        int max_size = 0;
        for (auto str : res) {
            if (str.size() > max_size) {
                max_size = str.size();
                hash.clear();
                hash.insert(str);
            } else if (str.size() == max_size) {
                hash.insert(str);
            } else {
                continue;
            }
        }
        return {hash.begin(), hash.end()};
    }

   private:
    string ss;
    vector<string> res;
    string curr;

    void traverse(int index) {
        if (index == ss.size()) {
            if (check_curr_is_valid() == true) {
                res.push_back(curr);
            }
            return;
        }

        char curr_c = ss[index];
        if (curr_c == '(') {
            traverse(index + 1);
            curr.push_back(curr_c);
            traverse(index + 1);
            curr.pop_back();
        } else if (curr_c == ')') {
            if (check_curr_is_valid() == true) {
                traverse(index + 1);
            } else {
                traverse(index + 1);
                curr.push_back(curr_c);
                traverse(index + 1);
                curr.pop_back();
            }
        } else {
            curr.push_back(curr_c);
            traverse(index + 1);
            curr.pop_back();
        }
    }

    bool check_curr_is_valid() {
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