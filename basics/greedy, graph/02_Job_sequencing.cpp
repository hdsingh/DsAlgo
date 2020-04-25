#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

struct Job{
    char id;
    int dead;
    int profit;
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

void printJobSequence(vector<Job> jobs){
    int n = jobs.size();
    vector<int> results(n, -1);

    // 1. sort jobs based on profit;
    sort(jobs.begin(), jobs.end(), cmp);

    for(Job j: jobs) cout<<j.profit<<" ";

    // sequence
    for(int i=0; i<n; i++){
        for(int j= min(n, jobs[i].dead); j>=0; j--){
            if(results[j]==-1){
                results[j] = i;
                break;
            }
        }
    }

    for(int i=1; i<n; i++){
        if(results[i]!=-1) cout<<jobs[results[i]].id<<" ";
    }

}

int main(){
    vector<Job> jobs = { {'a', 2, 100}, {'b', 1, 99}, {'c', 2, 27}, 
                         {'d', 1, 25},  {'e', 3, 15} };
    printJobSequence(jobs);
}