class Solution {
public:
    int delta(string one, string two){
        int count = 0;
        for(int i = 0;i < one.size();i++){
            if(one[i] != two[i]){
                count++;
            }
        }
        return count;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);

        unordered_map<string, int> dist;
        dist[startGene] = 0;

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            for(string candidate : bank){
                if(dist.find(candidate) == dist.end() && delta(candidate, curr) <= 1){
                    dist[candidate] = dist[curr] + 1;
                    q.push(candidate);
                }
            }
        }
        for(auto current : dist){
            if(current.first == endGene){
                return current.second;
            }
        }
        return -1;
    }
};