class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ticket_num = tickets.size();

        for (auto& ticket : tickets) {
            string src = ticket[0];
            string dst = ticket[1];
            graph[src].push_back(dst);
        }

        for (auto& route : graph) {
            sort(route.second.begin(), route.second.end());
            used_ticket[route.first] = vector<int>(route.second.size(), 0);
        }

        curr_res.push_back("JFK");
        backtrack("JFK");
        return res;
    }

   private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, vector<int>> used_ticket;
    int ticket_num = 0;

    vector<string> curr_res;
    vector<string> res;

    void backtrack(string curr_airport) {
        if (res.empty() == false) {
            return;
        }

        if (curr_res.size() == ticket_num + 1) {
            res = curr_res;
            return;
        }

        vector<string>& dsts = graph[curr_airport];
        for (int i = 0; i < dsts.size(); i++) {
            if (used_ticket[curr_airport][i] == 0) {
                if (i > 0 && used_ticket[curr_airport][i - 1] == false && dsts[i] == dsts[i - 1]) {
                    continue;
                }
                curr_res.push_back(dsts[i]);
                used_ticket[curr_airport][i] = 1;
                backtrack(dsts[i]);
                used_ticket[curr_airport][i] = 0;
                curr_res.pop_back();
            }
        }
    }
};