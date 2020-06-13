#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename U>
using ordered_map = tree<T, U, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(){
	ordered_set<int>  s;
	s.insert(0); 
	s.insert(3);
    s.insert(10);
    s.insert(6);
	cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2  : 1
	cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based) : 0
	cout << *s.find_by_order(1) << endl; // print the 1-st smallest number in s(0-based) : 3
	cout << *s.find_by_order(2) << endl; // print the 2nd smallest number in s(0-based) : 6
	
	ordered_multiset<int>  ms;
	ms.insert(0); 
	ms.insert(3);
    ms.insert(10);
	ms.insert(3);
    ms.insert(6);
    // {0,3,3,6,10}
	cout << ms.order_of_key(3) << endl; // the number of elements in the s less than 2  : 1
	cout << *ms.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based) : 0
	cout << *ms.find_by_order(1) << endl; // print the 1-st smallest number in s(0-based) : 3
	cout << *ms.find_by_order(2) << endl; // print the 2nd smallest number in s(0-based) : 3

}



// Example:
// 1. https://codeforces.com/contest/1042/problem/D
// 2. https://codeforces.com/problemset/problem/1227/D2
// 3. Cses/Sliding Median

