class Solution {
private:
    int helper(int index, vector<pair<int, int>>& cont, int k, int n, unordered_map<int, int>& cache){
        if(index == n){
            return 1;
        }
        if(cache.find(index) != cache.end()){
            return cache[index];
        }
        
        int skip = helper(index + 1, cont, k, n, cache);
        int take = (1 << cont[index].second) - 1;
        if(index + 1 < n && cont[index + 1].first - cont[index].first == k){
            take *= helper(index + 2, cont, k, n, cache);
        } else {
            take *= helper(index + 1, cont, k, n, cache);
        }
        return cache[index] = skip + take;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        map<int, map<int,int>> mapp;
        for(auto ele : nums){
            mapp[ele%k][ele]++;
        }
        int res = 1;
        for(auto freq : mapp){
            vector<pair<int,int>> pair(freq.second.begin(), freq.second.end());
            unordered_map<int, int> cache;
            res *= helper(0, pair, k, pair.size(), cache);
        }
        return res - 1;
    }
};