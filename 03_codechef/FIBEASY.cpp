#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
using ll = long long unsigned int;

void p_vec(vector<ll> v){
    for(auto i= v.begin(); i!=v.end(); i++){
        cout<<*i<<endl;
    }
}

void p_vec_i(vector<int> v){
    for(auto i= v.begin(); i!=v.end(); i++){
        cout<<*i<<endl;
    }
}


class Solution {
public:
    vector<int> find_easyfib(vector<int> nums){

        int max_num = *max_element(nums.begin(), nums.end());
        int floor_log_max = floor(log2(max_num));
        int num, floor_log_num;
        vector<int> out;
        vector<ll> cache(floor_log_max+1, -1);
        cache[0] = 0;
        cache[1] = 1;

        // Create fib seq once 
        vector<ll> seq = get_fib(max_num);
        // find mod of nums
        for(int i=0; i<seq.size(); i++){
            seq[i] = seq[i]%10;        
        }

        // for every num find res
        for(auto n = nums.begin(); n!=nums.end(); n++){
            num = *n;
            floor_log_num = floor(log2(num));

            if (cache[floor_log_num]==-1){
                // find the ans and store
                // vector<ll> temp(seq.begin(),seq.begin()+floor(num)+1); // copy till req length into temp
                vector<ll> temp;
                for(int i=0; i<num; i++){
                    if ((i%2))
                        temp.push_back(seq[i]);
                }
                
                while(temp.size()>1){
                    temp = reduce(temp); 
                }
                cache[floor_log_num] = temp[0];
            }
            out.push_back(cache[floor_log_num]);

        }
        return out;
    }

    vector<ll> get_fib(ll y){
        ll a = 0;
        ll b = 1;
        ll res;
        vector<ll> out;
        out.push_back(a);
        if (y==1) return out; 
        out.push_back(b);
        if (y==2) return out;


        for(int i=2; i<y; i++){
            res = a + b;
            a = b;
            b = res;
            out.push_back(res);
        }

        return out;
    }

    vector<ll> reduce(vector<ll> & out){
        vector<ll> res;
        for(int i=0; i<out.size(); i++){
            if ((i%2))
                res.push_back(out[i]);
        }
        return res;
    }


};

int main(){
    Solution s;
    // // cout<<s.find_easyfib(60);
    int t, y;
    scanf("%d", &t);
    vector<int> nums;


    while(t--){
        scanf("%d", &y);
        nums.push_back(y);
    }
    // p_vec_i(nums);

    vector<int> out = s.find_easyfib(nums);
    
    for(auto i = out.begin(); i!=out.end(); i++){
        printf("%d\n",*i);
    }

    
}