#include <algorithm>
#include <iostream>
#include <deque>
#include <limits.h>
// #include <bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

int main(){
    int t;
    int n;
    int p;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        deque<int> q;
        q.push_back(INT_MAX);
        int good = 0;
        for(int i=0; i<n; i++){
            scanf("%d ", &p);
            auto it_cmin = min_element(q.begin(), q.end());
            
            if(p<*it_cmin) good+=1;

            q.push_back(p);
            if(q.size()>5) q.pop_front();
        }
        printf("%d\n", good);
    }
}

// 1. Push INT_MAX into dq;
// 2. before entering an element find a min_element from q
// 3. if curr_p < min_element then good+=1
// 4. push element maintaing q size as 5