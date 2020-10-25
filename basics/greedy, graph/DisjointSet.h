using namespace std;

class DSU{
public:
	vector<int> par, ranks;

	DSU(int n){
		par.assign(n+1,0);
		ranks.assign(n+1,0);
		// ranks.assign(n+1,1); // to merge by size
		iota(par.begin(),par.end(), 0); // make a node par of itself
	}

	bool union_sets(int a, int b){
		a = find_par(a);
		b = find_par(b);
		if(a==b) return false; // already united, since having same par

		if(ranks[a]<ranks[b])
			swap(a,b);
		par[b] = a;

        // to merge by rank
		if(ranks[a]==ranks[b])
			ranks[a]++;
        
        // To merge by size
        // ranks[a]+=ranks[b];

		return true;
	};

	int find_par(int a){
		if(a==par[a]) return a;
		return par[a] = find_par(par[a]);
	}
};

// https://codeforces.com/problemset/problem/1213/G
// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
// https://codeforces.com/problemset/problem/766/D (Opposite)
// https://codeforces.com/problemset/problem/1131/D (DSU + Topsort, unite nodes + Graph algo)
// https://codeforces.com/problemset/problem/400/D  (DSU  + FloydWarshall)
// https://leetcode.com/problems/rank-transform-of-a-matrix/