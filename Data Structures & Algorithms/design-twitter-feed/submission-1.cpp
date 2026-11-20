class Twitter {
private:
    int timestamp;

    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq;

        following[userId].insert(userId);

        for (int followee : following[userId]) {
            if (!tweets[followee].empty()) {
                int index = tweets[followee].size() - 1;

                auto [time, id] = tweets[followee][index];

                pq.push({time, followee, index});
            }
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [time, followee, index] = pq.top();
            pq.pop();

            feed.push_back(tweets[followee][index].second);

            if (index > 0) {
                index--;

                pq.push({
                    tweets[followee][index].first,
                    followee,
                    index
                });
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};