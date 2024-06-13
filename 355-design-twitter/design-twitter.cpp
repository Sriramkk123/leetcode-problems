class Twitter {
private:
    int time;
    unordered_map<int, set<int>> followersMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>> pq;
        followersMap[userId].insert(userId);

        auto followers = followersMap[userId];
        for(auto follower : followers){
            int size = tweetMap[follower].size() - 1;
            if(size >= 0){
                auto tweet = tweetMap[follower].back();
                int tim = tweet.first;
                int twetId = tweet.second;

                pq.push({tim, twetId, follower, size - 1});
            }
        }

        int ind = 0;
        while(!pq.empty() && ind < 10){
            auto curr = pq.top();
            pq.pop();

            int tweetToAppend = curr[1];
            res.push_back(tweetToAppend);

            int followeeId = curr[2];
            int index = curr[3];
            if(index >= 0){
                auto nextTwet = tweetMap[followeeId][index];
                pq.push({nextTwet.first, nextTwet.second, followeeId, index - 1});
            }

            ind++;
        }        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followersMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followersMap[followerId].find(followeeId) != followersMap[followerId].end()){
            followersMap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */