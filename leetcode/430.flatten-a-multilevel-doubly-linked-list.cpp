#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

class Node {
public:
    int val;
    Node *prev, *next, *child;
};

class Solution0 {
public:
    Node* flatten(Node* head, Node* rest = nullptr) {
        if(!head) return head;  
        head->next = flatten(head->child, flatten(head->next, rest));
        if(head->next) head->next->prev = head;
        head->child = nullptr;
        return head;        
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* orig = head;
        stack<Node*> stk;
        while(head->next || head->child || !stk.empty()){
            // since this node doesn't have a next and child, pop
            // from the prev heads and add
            if(!head->next && !head->child){
                head->next = stk.top(), stk.pop();
                head->next->prev = head;
            }
            // keep moving forward till the node has next but doesn't have a child
            while(head->next && !head->child) head = head->next;
            
            // save the next if present to be used later and start processing the child
            if(head->next) stk.push(head->next);
            if(!head->child) continue;
            head->next = head->child;
            head->next->prev = head;
            head->child = nullptr;
        }

        return orig;
    }
};

// O(2n) worst case complexity.
// Whenever we find a child connect its last node in straight chain 
// with the next node of cur.(hence flattening only one level at a time).
class Solution {
public:
    Node* flatten(Node* head) {
        for(auto cur = head; cur; cur = cur->next){
            if(cur->child){
                auto cur_next = cur->next;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = nullptr;

                auto child = cur->next;
                while(child->next) child = child->next;

                child->next = cur_next;
                if(cur_next) cur_next->prev = child;
            }
        }

        return head;
    }
};

int main(){
    
    return 0;
}