#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection{
    vector<int> arr;
    unordered_map<int, unordered_set<int>> locs; // {val: {locations in arr}}
public:
    RandomizedCollection(){
        arr.clear();
        locs.clear();
        srand(time(NULL));
    }

    // true if already not present
    bool insert(int val){
        arr.push_back(val);
        locs[val].insert((int)arr.size() - 1);

        return locs[val].size() == 1;
    }

    // true: if present and removed else false
    bool remove(int val){
        if (!locs.count(val)){
            return false;
        }
        int last = arr.back();
        if (last == val){
            locs[val].erase(arr.size() - 1);
            arr.pop_back();
        }else{
            int index_to_del = *locs[val].begin();

            locs[last].erase(arr.size() - 1);
            locs[last].insert(index_to_del);

            locs[val].erase(index_to_del);
            arr[index_to_del] = last;
            arr.pop_back();
        }

        if (locs[val].empty())
            locs.erase(val);

        return true;
    }

    // return a random val
    int getRandom(){
        return arr[rand() % arr.size()];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}