#include <bits/stdc++.h>
using namespace std;

// n*len*len*26;
// BFS on the paths. and removing the nodes which are used at the end of exploring a level.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> allWords(wordList.begin(), wordList.end());
		queue<vector<string>> paths;
        paths.push({beginWord});
		vector<vector<string>> ans;

		while(!paths.empty()){
			queue<vector<string>> newPaths;
			unordered_set<string> seen;
			while(!paths.empty()){
				vector<string> path = paths.front(); paths.pop();
				string word = path.back();
				for(int pos=0; pos<word.size(); ++pos){
					char here = word[pos];
					for(char c='a'; c<='z'; ++c){
						word[pos] = c;
						if(allWords.count(word)){
							path.push_back(word);
							seen.insert(word);

							if(word==endWord){
								ans.push_back(path);
							}else{
								newPaths.push(path);	
							}
                            path.pop_back();
						}
					}
					word[pos] = here;				
				}
			}
			paths = newPaths;
			for(auto &word: seen) allWords.erase(word);
		}
		
		return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}