class Solution {
   public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        visited.resize(n);
        for (auto e : edges) {
            links[e[0]].push_back(e[1]);
            links[e[1]].push_back(e[0]);
            visited[e[0]] = 0;
            visited[e[1]] = 0;
        }
        this->has_apple = hasApple;

        traverse(0);

        return step;
    }

   private:
    vector<bool> has_apple;
    unordered_map<int, vector<int>> links;
    vector<int> visited;
    int step = 0;

    bool traverse(int curr) {
        if (visited[curr] == 1) {
            return false;
        }
        visited[curr] = 1;
        bool do_save = false;
        if (links.find(curr) != links.end()) {
            for (auto child : links[curr]) {
                bool temp = traverse(child);
                if (temp == true) {
                    step += 2;
                    do_save = true;
                }
            }
        }

        if (has_apple[curr] == true) {
            return true;
        }

        if (do_save == true) {
            return true;
        } else {
            return false;
        }
    }
};