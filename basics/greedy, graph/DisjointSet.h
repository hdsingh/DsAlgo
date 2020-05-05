using namespace std;

class DisjointSet{
	vector<int> par, ranks;
public: 
	void make_sets(int n){
		par.clear(); par.resize(n);
		ranks.clear(); ranks.resize(n);
		// ranks.clear(); ranks.resize(n,1); // to merge by size
		iota(par.begin(),par.end(), 0); // make a node par of itself
	}

	bool union_sets(int a, int b){
		a = find_set(a);
		b = find_set(b);
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

	int find_set(int a){
		if(a==par[a]) return a;
		return par[a] = find_set(par[a]);
	}
};

// https://codeforces.com/problemset/problem/1213/G