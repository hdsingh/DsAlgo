#include <bits/stdc++.h>
using namespace std;

struct Node{
	int index = -1; // of word ending here;
	vector<int> remPals; // the indexes of remaining strings which are pals
	Node* ch[26] = {}; 
};

class Solution {
	Node* root;
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
		root = new Node();
		for(int i=0; i<n; ++i)
			insert(words[i],i);	
		
		vector<vector<int>> out;
		for(int i=0; i<n; ++i)
			search(words[i], i, out);
		
		return out;
    }

	void insert(string &word, int idx){
		Node *cur = root;
		int len = word.size();
		for(int i=len-1; i>=0; --i){
			int alp = word[i]-'a';
			if(!cur->ch[alp])
				cur->ch[alp] = new Node();
			
			if(isPal(word,0,i))
				cur->remPals.push_back(idx);			
		
			cur = cur->ch[alp];
		}
        // the remaining empty word is also a pal
        cur->remPals.push_back(idx);
		cur->index = idx;
	}	

	void search(string &word, int idx, vector<vector<int>> &out){
		int len = word.size();
		Node *cur = root;
		for(int i=0; i<len; ++i){
			if(cur->index!=-1 && cur->index!=idx && isPal(word,i,len-1))
				out.push_back({idx, cur->index});
			
			cur = cur->ch[word[i]-'a'];	
			if(!cur) return;		
		}	

		for(int oth_idx: cur->remPals)
			if(oth_idx!=idx)
				out.push_back({idx, oth_idx});
	}

	bool isPal(string &word, int lt, int rt){
		while(lt<rt){
			if(word[lt++]!=word[rt--])
				return false;
		}	
		return true;
	}
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}











