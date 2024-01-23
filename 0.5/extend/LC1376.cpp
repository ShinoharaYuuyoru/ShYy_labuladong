class Solution {
   public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < manager.size(); i++) {
            manage_employees[manager[i]].push_back(i);
        }

        return divide(headID, informTime);
    }

   private:
    unordered_map<int, vector<int>> manage_employees;
    int divide(int headID, vector<int>& informTime) {
        int max_cost_time = 0;
        if (manage_employees.find(headID) != manage_employees.end()) {
            vector<int> employees = manage_employees[headID];
            for (int i = 0; i < employees.size(); i++) {
                max_cost_time = max(max_cost_time, divide(employees[i], informTime));
            }
        }

        return informTime[headID] + max_cost_time;
    }
};