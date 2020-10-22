#include <bits/stdc++.h>
using namespace std;

class CustomStack {
    int cap;
    vector<int> stk, add;
public:
    CustomStack(int maxSize) {
        cap = maxSize;
        add.assign(cap,0);
    }
    
    void push(int x) {
        if(stk.size()>=cap) return;
        stk.push_back(x);
    }
    
    int pop() {
        if(stk.empty()) return -1;
        int idx = stk.size()-1;
        int out = stk[idx] + add[idx];
        stk.pop_back();
        
        if(idx>0)
            add[idx-1]+=add[idx];
        
        add[idx] = 0;
        return out;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)stk.size());
        if(k>0) add[k-1]+=val;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}