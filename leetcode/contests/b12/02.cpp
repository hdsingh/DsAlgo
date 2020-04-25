#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}


class Leaderboard {
    vector<int> board;
public:
    Leaderboard() {
        board.clear();
        board.resize(10050, 0);
    }
    
    void addScore(int playerId, int score) {
        board[playerId]+=score;
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto score: board){
            pq.push(score);
            if(pq.size()>K) pq.pop();
        }
        int sum = 0;
        
        while(!pq.empty()){
            sum+=pq.top(); 
            pq.pop();
        }
        return sum;
    }
    
    void reset(int playerId) {
        board[playerId]=0;
    }
};


int main(){
    Leaderboard leaderboard;
    leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
    leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
    leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
    leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
    leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
    cout<<leaderboard.top(1)<<endl;           // returns 73;
    leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
    leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
    leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
    cout<<leaderboard.top(3)<<endl;           // returns 141 = 51 + 51 + 39;

    return 0;
}