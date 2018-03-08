#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

struct Cmp
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
class Twitter {
private:
    int id = 0;
    std::unordered_map<int, std::list<std::pair<int, int>>> userTweets;
    std::unordered_map<int, std::unordered_set<int>> subscribeMap;
    std::unordered_map<int, std::unordered_set<int>> fanMap;
    std::unordered_map<int, std::map<int, std::pair<int, int>, Cmp>> feedsMap;

public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_front(std::make_pair(id++, tweetId));

        const auto iter = fanMap.find(userId);
        if(iter != fanMap.end())
        {
            for(int fanId : iter->second)
            {
                std::cout<<fanId<<std::endl;
                feedsMap[fanId].insert(std::make_pair(id - 1, std::make_pair(userId, tweetId)));
            }
        }
        feedsMap[userId].insert(std::make_pair(id - 1, std::make_pair(userId, tweetId)));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        std::unordered_set<int> subs{userId};
        auto iter = subscribeMap.find(userId);
        if(iter != subscribeMap.end())
        {
            subs.insert(iter->second.begin(), iter->second.end());
        }

        auto jter = feedsMap.find(userId);
        if(jter != feedsMap.end())
        {
            int cnt = 0;
            for(const auto& p : jter->second)
            {
                if(subs.find(p.second.first) != subs.end())
                {
                    res.push_back(p.second.second);
                    ++cnt;
                }
                if(cnt == 10) break;
            }
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(subscribeMap[followerId].find(followeeId) == subscribeMap[followerId].end())
        {
            subscribeMap[followerId].insert(followeeId);
            fanMap[followeeId].insert(followerId);

            auto iter = userTweets.find(followeeId);
            if(iter != userTweets.end())
            {
                int cnt = 0;
                for(const auto& p : iter->second)
                {
                    feedsMap[followerId].insert(std::make_pair(p.first, std::make_pair(followeeId, p.second)));
                    ++cnt;
                    if(cnt == 10) break;
                }
            }
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(subscribeMap.find(followerId) != subscribeMap.end() &&
           subscribeMap[followerId].find(followeeId) != subscribeMap[followerId].end())
        {
            subscribeMap[followerId].erase(followeeId);
            fanMap[followeeId].erase(followerId);
        }
    }
};


int main() {
    //Solution s;
    Twitter a;
    a.postTweet(1, 5);
    a.getNewsFeed(1);
    a.follow(1, 2);
    a.postTweet(2, 6);
    std::cout<<a.getNewsFeed(1).size()<<std::endl;
}
