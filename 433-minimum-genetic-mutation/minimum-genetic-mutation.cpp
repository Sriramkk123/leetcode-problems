class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if(bankSet.count(endGene) < 1){
            return -1;
        }

        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({startGene, 0});
        visited.insert(startGene);
        string possibles = "ACGT";
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            string word = curr.first;
            int moves = curr.second;
            for(int i = 0;i < word.size();i++){
                char og = word[i];
                for(int j = 0;j < possibles.size();j++){
                    word[i] = possibles[j];
                    if(bankSet.count(word) >= 1){
                        if(word == endGene){
                            return moves + 1;
                        }
                        if(visited.count(word) < 1){
                            visited.insert(word);
                            q.push({ word, moves + 1});
                        }
                    }
                }
                word[i] = og;
            }
        }
        return -1;
    }
};