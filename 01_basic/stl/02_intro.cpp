// https://www.youtube.com/watch?v=qOHXdhtxyyQ
#include <bits/stdc++.h>
using namespace std;

int max1(int a, int b){
    int out = a > b ? a:b;
    return out;
}

template <typename T>
const T& max2(T& a, T& b){
    return  (a > b) ? a:b;
}

void learn_vector();
void learn_deque();
void learn_list();   
void learn_set(); 
void learn_map(); 
 

int main(){
    learn_vector();
    // learn_deque();
    // learn_list();   
    // learn_set();
    // learn_map(); 

}

void learn_map(){
    map<int, int> M;
    M.insert({1,40});
    M.insert({2,50});
    M.insert({20,500});

    map<int, int>::iterator it;

    for(it=M.begin(); it!=M.end(); it++)
        cout<<it->first<<": "<< it->second<<" ";
}

void learn_set(){
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(100);

    for(int x: S) cout<<x<<" ";
    cout<<endl;
}


void learn_list(){

    list<int> Li;
    for (int i = 1; i <= 10; i++)
    {
        Li.push_back(i*5);
    }

    for(int x: Li)
        cout<<x<<" ";
    cout<<endl;

    // cout<<Li[5]<<endl; // Could be done on vector but not on list

    list<int>::iterator it;
    it = Li.end();   
    cout<<"*it: "<<*it<<endl;
    for (it= Li.begin(); it!=Li.end(); it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;

    list<int>::iterator min_it = min_element(Li.begin(), Li.end());
    cout<<"Minimum element: "<<*min_it<<endl;

    list<int>::iterator max_it = max_element(Li.begin(), Li.end());
    cout<<"Minimum element: "<<*max_it<<endl;

    list<int>::iterator it1 = find(Li.begin(), Li.end(), 40);
    Li.insert(it1, 300);
    Li.insert(it1, 600);

    for(int x: Li) cout<<x<<" ";
    cout<<endl;
}

void learn_deque(){
    deque<int> D;
    for (int i=1; i<5; i++)
    {
        D.push_back(i);
        D.push_front(i*10);
    }

    for(int x: D)
        cout<<x<<" ";
    cout<<endl;
}

void learn_vector(){

    vector<int> V;
    for (int i = 1; i <= 10; i++)
    {
        V.push_back(rand()%100);
    }

    for(int x: V)
        cout<<x<<" ";
    cout<<endl;

    cout<<V[5]<<endl;

    sort(V.begin(), V.end());
    cout<<"Sorted: ";
    for(int x: V) cout<<x<<" ";
    cout<<endl;

    reverse(V.begin(), V.end());
    cout<<"Reverse: ";
    for(int x: V) cout<<x<<" ";
    cout<<endl;

    vector<int>::iterator it;
    it = V.end();   
    cout<<"*it: "<<*it<<endl;
    for (it= V.begin(); it!=V.end(); it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;
}