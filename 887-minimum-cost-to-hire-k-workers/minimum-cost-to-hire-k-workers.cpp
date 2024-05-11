class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> pairs;
        for(int i = 0;i < quality.size();i++){
            pairs.push_back({(double)wage[i]/ quality[i], quality[i]});
        }

        sort(pairs.begin(), pairs.end(), [](pair<double,int> a, pair<double,int> b){
            return a.first < b.first;
        });

        priority_queue<int> pq;
        int total_quality = 0;
        double res = INT_MAX;
        for(auto pair : pairs){
            double rate = pair.first;
            int quality = pair.second;
            pq.push(quality);
            total_quality += quality; 

            if(pq.size() > k){
                total_quality -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                res = min(
                    res,
                    rate * total_quality
                );
            }
        }
        return res;
    }
};