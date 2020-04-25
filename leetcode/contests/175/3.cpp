#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class TweetCounts {
    unordered_map<string, set<int>> record;
    unordered_map<string, int> timeDiv = {
        {"minute", 60},
        {"hour", 60*60},
        {"day", 60*60*24},
    };
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        int curStart = min(curStart, time);
        int curEnd = min(curEnd, time);
        record[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        // set<int> tempTime;
        // auto beg = record[tweetName].lower_bound(startTime);
        // while(beg!=record[tweetName].end() && (*beg)>=startTime && (*beg)<endTime){
        //     tempTime.insert(*beg);
        // }
        
        const int div = timeDiv[freq];
        // int parts = ceil(endTime - startTime + 1);   

        vi out;
        for(int st = startTime; st<=endTime; st+=div){
            int cnt = 0;
            int ed = min(endTime, st+div-1);

            auto beg = record[tweetName].lower_bound(st);
            while(beg!=record[tweetName].end() && (*beg)>=st && (*beg)<=ed){
                ++cnt;
                ++beg;
            }
            out.push_back(cnt);
        }
        
        return out;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

int main(){
    vi out;
    TweetCounts obj;
    TweetCounts tweetCounts;
    tweetCounts.recordTweet("tweet3", 0);
    tweetCounts.recordTweet("tweet3", 60);
    tweetCounts.recordTweet("tweet3", 10);                             // All tweets correspond to "tweet3" with recorded times at 0, 10 and 60.
    out = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); print(out); // return [2]. The frequency is per minute (60 seconds), so there is one interval of time: 1) [0, 60> - > 2 tweets.
    out = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); print(out); // return [2, 1]. The frequency is per minute (60 seconds), so there are two intervals of time: 1) [0, 60> - > 2 tweets, and 2) [60,61> - > 1 tweet.
    tweetCounts.recordTweet("tweet3", 120);                            // All tweets correspond to "tweet3" with recorded times at 0, 10, 60 and 120.
    out = tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210); print(out);  // return [4]. The frequency is per hour (3600 seconds), so there is one interval of time: 1) [0, 211> - > 4 tweets.

    tweetCounts.recordTweet("tweet3", 24*60*60);                             // All tweets correspond to "tweet3" with recorded times at 0, 10 and 60.
    out = tweetCounts.getTweetCountsPerFrequency("day", "tweet3", 0, 24*60*60); print(out); // return [2, 1]. The frequency is per minute (60 seconds), so there are two intervals of time: 1) [0, 60> - > 2 tweets, and 2) [60,61> - > 1 tweet.
    
    return 0;
}

