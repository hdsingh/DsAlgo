// https://www.codechef.com/NOV19B/problems/CAMC
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

int main(){
    int t,n,m, diff;
	scanf("%d\n", &t);
	while(t--){
		scanf("%d ", &n);
		scanf("%d\n",&m);
 
		vector<int> A(n+1);
		for(int i=1; i<n; i++){
			scanf("%d ", &A[i]);
		}
		scanf("%d\n", &A[n]);

        vi sub;
        int diff;
        int min_diff = INT_MAX;
		for(int i=1; i<=n-m+1; i++){
            for(int j=i+1; j<=n-m+2; j+=m){
                sub.clear();
                sub.push_back(A[i]);

                // cout<<i<<": ";
                int k = 0;
                while(k!=m-1){
                    // cout<<j+k<<" ";
                    sub.push_back(A[j+k]);
                    k++;
                }
                // cout<<"    ";
                print(sub);
                diff = abs( *max_element(sub.begin(), sub.end()) - *min_element(sub.begin(), sub.end()) );
                min_diff = min(min_diff, diff);
            }
            cout<<endl;
        }
        // printf("%d\n", min_diff);
 
	}

	return 0;
}