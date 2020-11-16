#include <bits/stdc++.h>
using namespace std;

struct Node{
    int index = -1; // that ends here
    int remPals; // the remaining len of word is a pal
    Node* ch[26] = {};
};

class Solution{
    Node* root;
public:
    int countPairs(vector<string> &words){
        root = new Node();
        int n = words.size();
        for(int i=0; i<n; ++i){
            insert(words[i], i);
        }      

        int ans = 0;
        for(int i=0; i<n; ++i){
            search(words[i], i, ans);
        }   
        return ans;
    }

    void insert(string &word, int idx){
        Node* cur = root;
        int len = word.size();
        for(int i=len-1; i>=0; --i){
            if(isPal(0,i,word))
                cur->remPals++;
            
            int here = word[i] - 'a';
            if(!cur->ch[here])
                cur->ch[here] = new Node();

            cur = cur->ch[here];
        }
    
        cur->index = idx;
        cur->remPals++;
    }

    void search(string &word, int idx, int &ans){
        Node* cur = root;
        int len = word.size();
        for(int i=0; i<len; ++i){
            if(cur->index!=-1 && isPal(i,len-1,word))
                ++ans;
            cur = cur->ch[word[i]-'a'];
            if(!cur) return;
        }
        ans+=cur->remPals;
        if(cur->index==idx)
            --ans;
    }

    bool isPal(int lt, int rt, string &word){
		while(lt<rt){
			if(word[lt++]!=word[rt--])
				return false;
		}	
		return true;
	}
};

int solve(vector<string>& words) {
    Solution sol; return sol.countPairs(words);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}