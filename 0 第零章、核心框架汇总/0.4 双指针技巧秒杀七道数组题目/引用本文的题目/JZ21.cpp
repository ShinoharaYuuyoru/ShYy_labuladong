class Solution {
   public:
    vector<int> trainingPlan(vector<int>& actions) {
        int slow = 0, fast = 1;
        while (fast < actions.size()) {
            if (actions[fast] % 2 == 1) {
                actions[slow] = actions[slow] ^ actions[fast];
                actions[fast] = actions[slow] ^ actions[fast];
                actions[slow] = actions[slow] ^ actions[fast];
                slow++;
            }
            fast++;
        }
        return actions;
    }
};