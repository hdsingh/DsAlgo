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
template <class T, class U> void print_m(unordered_map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class UndergroundSystem {
    int stnCount;
    unordered_map<string, int> recStnId;
    unordered_map<int, pair<int,int>> recId; // id, <stnId, time>
    unordered_map<int, unordered_map<int,pair<double, int>>> recAvg;
    // from, to, avg, size
public:
    UndergroundSystem() {
        recId.clear(); recStnId.clear(); recAvg.clear();
        stnCount = 0;
    }
    
    void checkIn(int id, string stn, int t) {
        int stnId = findStnId(stn);
        recId[id] = {stnId, t};
    }
    
    void checkOut(int id, string stn, int t) {
        int stnId = findStnId(stn);
        int prevT = recId[id].second; int prevStnId = recId[id].first;
        recId.erase(id);

        int dif = t - prevT;
        // deb3(prevStnId,stnId,dif);
        pair<double,int> cur = {0.0,0};
        if(recAvg.count(prevStnId) && recAvg[prevStnId].count(stnId))
            cur = recAvg[prevStnId][stnId];
        
        double prevAvg = cur.first; int prevSize = cur.second;

        double newAvg = prevAvg  + (dif - prevAvg)/(prevSize+1);
        recAvg[prevStnId][stnId] = {newAvg, prevSize + 1};   
    }
    
    double getAverageTime(string startStation, string endStation) {
        int prevId = recStnId[startStation];
        int curId = recStnId[endStation];
        return recAvg[prevId][curId].first;
    }

    int findStnId(const string &stn){
        if(recStnId.count(stn))
            return recStnId[stn];
        
        recStnId[stn] = stnCount++;
        return recStnId[stn];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */


int main(){
    UndergroundSystem undergroundSystem; double t;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    t = undergroundSystem.getAverageTime("Paradise", "Cambridge");       // return 14.0. There was only one travel from "Paradise" (at time 8) to "Cambridge" (at time 22)
    deb(t);
    t = undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.0. There were two travels from "Leyton" to "Waterloo", a customer with id=45 from time=3 to time=15 and a customer with id=27 from time=10 to time=20. So the average time is ( (15-3) + (20-10) ) / 2 = 11.0
    deb(t);
    undergroundSystem.checkIn(10, "Leyton", 24);
    t = undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.0
    deb(t);
    undergroundSystem.checkOut(10, "Waterloo", 38);
    t = undergroundSystem.getAverageTime("Leyton", "Waterloo");
    deb(t);
    // print_m(undergroundSystem.recStnId);
    return 0;
}