class Twitter {
   public:
    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        all_user_post[userId].push_back(make_pair(post_time, tweetId));
        post_time++;
        post_by_user[tweetId] = userId;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> user_following_list = following_list[userId];
        user_following_list.push_back(userId);

        priority_queue<pair<int, int>, vector<pair<int, int> >, function<bool(pair<int, int>, pair<int, int>)> > pq(
            [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
        for (int i = 0; i < user_following_list.size(); i++) {
            vector<pair<int, int> > user_post = all_user_post[user_following_list[i]];
            if (user_post.size() != 0) {
                for (int j = 0; j < user_post.size(); j++) {
                    pq.push(user_post[j]);
                }
            }
        }
        vector<int> feed;
        int feed_counter = 0;
        while (feed_counter < 10 && !pq.empty()) {
            pair<int, int> curr_post = pq.top();
            pq.pop();
            feed.push_back(curr_post.second);
            feed_counter++;
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (find(following_list[followerId].begin(), following_list[followerId].end(), followeeId) == following_list[followerId].end()) {
            following_list[followerId].push_back(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (find(following_list[followerId].begin(), following_list[followerId].end(), followeeId) != following_list[followerId].end()) {
            following_list[followerId].erase(find(following_list[followerId].begin(), following_list[followerId].end(), followeeId));
        }
    }

   private:
    int post_time = 0;
    unordered_map<int, vector<int> > following_list;
    unordered_map<int, vector<pair<int, int> > > all_user_post;
    unordered_map<int, int> post_by_user;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */