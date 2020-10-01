#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class Solution {
public:
    bool carPooling(vector<vector<int>>& ts, int cap) {
        map<int,int> stops;
        for(auto &t: ts) stops[t[1]]+=t[0], stops[t[2]]-=t[0];
        for(auto &p: stops){
            if((cap-=p.second)<0)
                return 0;
        }
        return 1;
    }
};


const int nax = 1001;
class Solution1 {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        vector<int> stops(nax);
        for(auto &trip:  trips) stops[trip[1]]+=trip[0], stops[trip[2]]-=trip[0];
        // + val means fill the bus i.e decrease cap, else opp
        for(int i=0; i<nax && cap>=0; ++i) cap-=stops[i];
        return cap>=0;
    }
};


class Solution0 {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(auto &trip: trips){
            trip = {trip[1], trip[2], trip[0]};
        }
        sort(trips.begin(), trips.end());
        
        int inBus = 0;
        multiset<vi> bus; // {ed, cnt}
        for(auto &trip: trips){
            int st = trip[0], ed = trip[1], cnt = trip[2];
            while(!bus.empty() && (*bus.begin())[0]<=st){
                inBus-=(*bus.begin())[1];
                bus.erase(bus.begin());
            }
            if(inBus+cnt>capacity) return false;
            inBus+=cnt;
            bus.insert({ed, cnt});            
        }
        return true;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}