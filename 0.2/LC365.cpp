// DFS. SO(Stack Overflow).
class Solution {
   public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity == 0) {
            return true;
        }

        traverse(0, jug1Capacity, 0, jug2Capacity, targetCapacity);

        return res;
    }

   private:
    bool res = false;
    unordered_set<int64_t> visited;

    void traverse(int jug1_curr, int jug1_capa, int jug2_curr, int jug2_capa, int target) {
        int64_t hash = (int64_t)jug1_curr * (jug2_capa + 1) + jug2_curr;
        if (visited.find(hash) != visited.end()) {
            return;
        } else {
            visited.insert(hash);
        }

        if (res == true) {
            return;
        }
        if (jug1_curr == target || jug2_curr == target || jug1_curr + jug2_curr == target) {
            res = true;
            return;
        }

        traverse(jug1_capa, jug1_capa, jug2_curr, jug2_capa, target);
        traverse(jug1_curr, jug1_capa, jug2_capa, jug2_capa, target);
        traverse(0, jug1_capa, jug2_curr, jug2_capa, target);
        traverse(jug1_curr, jug1_capa, 0, jug2_capa, target);
        int get_min = min(jug1_curr, jug2_capa - jug2_curr);
        traverse(jug1_curr - get_min, jug1_capa, jug2_curr + get_min, jug2_capa, target);
        get_min = min(jug2_curr, jug1_capa - jug1_curr);
        traverse(jug1_curr + get_min, jug1_capa, jug2_curr - get_min, jug2_capa, target);
    }
};

// DFS. Optimized with stack. AC.
class Solution {
   public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }

        if (jug1Capacity == 0 || jug2Capacity == 0) {
            if (targetCapacity == 0) {
                return true;
            } else {
                if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity) {
                    return true;
                }
            }
        }

        stack<pair<int, int> > stk;
        unordered_set<int64_t> visited;

        stk.emplace(0, 0);
        while (stk.empty() == false) {
            pair<int, int> curr_state = stk.top();
            stk.pop();
            int jug1_curr = curr_state.first;
            int jug2_curr = curr_state.second;
            int64_t hash = (int64_t)jug1_curr * (jug2Capacity + 1) + jug2_curr;
            if (visited.find(hash) != visited.end()) {
                continue;
            } else {
                visited.insert(hash);
            }

            if (jug1_curr == targetCapacity ||
                jug2_curr == targetCapacity ||
                (jug1_curr + jug2_curr) == targetCapacity) {
                return true;
            }

            stk.emplace(jug1Capacity, jug2_curr);
            stk.emplace(jug1_curr, jug2Capacity);
            stk.emplace(0, jug2_curr);
            stk.emplace(jug1_curr, 0);
            int get_min = min(jug1_curr, jug2Capacity - jug2_curr);
            stk.emplace(jug1_curr - get_min, jug2_curr + get_min);
            get_min = min(jug2_curr, jug1Capacity - jug1_curr);
            stk.emplace(jug1_curr + get_min, jug2_curr - get_min);
        }
        return false;
    }
};

// Original BFS. TLE.
class Solution {
   public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        queue<pair<int, int> > q;
        unordered_set<int64_t> visited;

        q.emplace(0, 0);
        visited.insert((int64_t)0 * (jug2Capacity + 1) + 0);
        while (q.empty() == false) {
            int jug1_curr = q.front().first;
            int jug2_curr = q.front().second;
            q.pop();
            if (jug1_curr == targetCapacity ||
                jug2_curr == targetCapacity ||
                (jug1_curr + jug2_curr == targetCapacity)) {
                return true;
            }

            vector<pair<int, int> > next_states;
            next_states.push_back(make_pair(jug1Capacity, jug2_curr));
            next_states.push_back(make_pair(jug1_curr, jug2Capacity));
            next_states.push_back(make_pair(0, jug2_curr));
            next_states.push_back(make_pair(jug1_curr, 0));
            int get_min = min(jug1_curr, jug2Capacity - jug2_curr);
            next_states.push_back(make_pair(jug1_curr - get_min, jug2_curr + get_min));
            get_min = min(jug2_curr, jug1Capacity - jug1_curr);
            next_states.push_back(make_pair(jug1_curr + get_min, jug2_curr - get_min));

            for (auto next_state : next_states) {
                int64_t hash = (int64_t)next_state.first * (jug2Capacity + 1) + next_state.second;
                if (visited.find(hash) != visited.end()) {
                    continue;
                } else {
                    q.push(next_state);
                    visited.insert(hash);
                }
            }
        }
        return false;
    }
};

// Optimized BFS. AC.
class Solution {
   public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        queue<pair<int, int> > q;
        unordered_set<int64_t> visited;

        q.emplace(0, 0);
        visited.insert((int64_t)0 * (jug2Capacity + 1) + 0);
        while (q.empty() == false) {
            int jug1_curr = q.front().first;
            int jug2_curr = q.front().second;
            q.pop();
            if (jug1_curr == targetCapacity ||
                jug2_curr == targetCapacity ||
                (jug1_curr + jug2_curr == targetCapacity)) {
                return true;
            }

            int64_t next_hash;
            next_hash = (int64_t)jug1Capacity * (jug2Capacity + 1) + jug2_curr;
            if (visited.find(next_hash) == visited.end()) {
                q.push(make_pair(jug1Capacity, jug2_curr));
                visited.insert(next_hash);
            }

            next_hash = (int64_t)jug1_curr * (jug2Capacity + 1) + jug2Capacity;
            if (visited.find(next_hash) == visited.end()) {
                q.push(make_pair(jug1_curr, jug2Capacity));
                visited.insert(next_hash);
            }

            next_hash = (int64_t)0 * (jug2Capacity + 1) + jug2_curr;
            if (visited.find(next_hash) == visited.end()) {
                q.push(make_pair(0, jug2_curr));
                visited.insert(next_hash);
            }

            next_hash = (int64_t)jug1_curr * (jug2Capacity + 1) + 0;
            if (visited.find(next_hash) == visited.end()) {
                q.push(make_pair(jug1_curr, 0));
                visited.insert(next_hash);
            }

            int get_min = min(jug1_curr, jug2Capacity - jug2_curr);
            next_hash = (int64_t)(jug1_curr - get_min) * (jug2Capacity + 1) + (jug2_curr + get_min);
            if (visited.find(next_hash) == visited.end()) {
                q.push(make_pair(jug1_curr - get_min, jug2_curr + get_min));
                visited.insert(next_hash);
            }

            get_min = min(jug2_curr, jug1Capacity - jug1_curr);
            next_hash = (int64_t)(jug1_curr + get_min) * (jug2Capacity + 1) + (jug2_curr - get_min);
            if (visited.find(next_hash) == visited.end()) {
                q.push(make_pair(jug1_curr + get_min, jug2_curr - get_min));
                visited.insert(next_hash);
            }
        }
        return false;
    }
};

// Math. Bézout's Lemma. AC.
class Solution {
   public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }

        if (jug1Capacity == 0 || jug2Capacity == 0) {
            if (targetCapacity == 0) {
                return true;
            } else {
                if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity) {
                    return true;
                }
            }
        }

        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};
