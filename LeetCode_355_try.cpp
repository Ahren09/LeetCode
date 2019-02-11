struct User{
    int id;
    set<int>followees;
    map<int,int>m_tweets;
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() :count(0), timeId(0){}
    
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        std::pair<int,int> p;
        p.first=userId;
        p.second=tweetId;
        tweets.insert(pair<int,pair<int,int>>(timeId,p));
        users[userId].m_tweets.insert(pair<int,int>(timeId++,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> newsfeed;
        for(int i=1;i<=10 && timeId-i>=0 ;i++)
        {
            int followeeId=tweets[timeId-i].first;
            if(users[userId].followees.find(followeeId)!=users[userId].followees.end()
               ||userId == tweets[timeId-i].first)
                newsfeed.push_back(tweets[timeId-i].second);
        }
        return newsfeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].followees.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            users[followerId].followees.erase(followeeId);
    }
    
private:
    int count,timeId;
    map<int,User> users; //userId maps to User
    map<int,pair<int,int>>tweets; //userId maps to tweetId
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
