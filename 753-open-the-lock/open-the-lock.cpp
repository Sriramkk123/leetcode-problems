class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadEndSet(deadends.begin(), deadends.end());
        if(deadEndSet.find("0000") != deadEndSet.end()){
            return -1;
        }
        string pattern = "0000";
        unordered_set<string> visited;
        int minMoves = 0;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto current = q.front();
                q.pop();

                if (current == target) {
                    return minMoves;
                }
                for (int i = 0; i < 4; i++) {
                    char temp = current[i];
                    current[i] = temp == '9' ? '0' : temp + 1;
                    if (visited.find(current) == visited.end() &&
                        deadEndSet.find(current) == deadEndSet.end()) {
                        visited.insert(current);
                        q.push(current);
                    }
                    current[i] = temp == '0' ? '9' : temp - 1;
                    if (visited.find(current) == visited.end() &&
                        deadEndSet.find(current) == deadEndSet.end()) {
                        visited.insert(current);
                        q.push(current);
                    }
                    current[i] = temp;
                }
            }
            minMoves++;
        }
        return -1;
    }
};