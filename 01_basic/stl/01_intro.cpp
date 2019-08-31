// Source: https://www.youtube.com/watch?v=g-1Cn3ccwXY

#include <bits/stdc++.h>
using namespace std;

bool f(int x, int y){
	return x <=56;
}

int main(){
	map<int, int> m;
	m[0] = 10;
	m[4] = 6;
	m[34] = 5;
	m[32434] = 12;

	for(auto i= m.begin(); i!=m.end(); i++){
		cout<<i->first<<": "<<i->second<<"   ";
	}
	cout<<endl;

	map<char, int> count_letters;
	string x  = "aaa bb ccccc a";
	
	for(char c: x){
		count_letters[c]++;
	}
	cout<<count_letters['b']<<endl;
	
}

void powerOfSTL(){
	set< pair<int, int> > s;
	s.insert({2,3});
	s.insert({10, 20});
	s.insert({30, 400});
	s.insert({401, 450});
}

int learn_set(){
	set<int> s;
	s.insert(100);
	s.insert(2);
	s.insert(5);
	s.insert(-9);
	s.insert(-3);

	for(int x: s)
		cout<<x<<" ";

	cout<<endl;
	// -3 2 100

	auto it = s.find(-3);

	if(it == s.end())
	{
		cout<<"Not present";
	}else{
		cout<<"Present";
		cout<<*it<<endl;
	}

	auto it1 = s.lower_bound(1);
	auto it2 = s.upper_bound(3);

	cout<<*it1<<"  "<<*it2<<endl;

	s.erase(5);
	for(auto x: s)
		cout<<x<<' ';
	cout<<endl;

}

int learn_vector(){
	vector<int> A = {11,4,23,56,12,5};
	sort(A.begin(), A.end());  // O(NlogN)
	for (int i = 0; i < 6; i++)
	{
		cout<<A[i]<<"\t";
	}
	cout<<endl;
	cout<<binary_search(A.begin(), A.end(), 43)<<endl;

	A.push_back(100);
	cout<<binary_search(A.begin(), A.end(), 100)<<endl;
	
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);
	
	vector<int>::iterator it1 = lower_bound(A.begin(), A.end(), 100);
	vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100);
	
	cout<<"it1: "<<*it1<<endl;
	cout<<"it2: "<<*it2<<endl;
	cout<<"it1 - it2: "<<it2 - it1<<endl;

	// Sort in descending order
	sort(A.begin(), A.end(), f);

	for (vector<int>::iterator i = A.begin(); i < A.end(); i++)
	{
		cout<<*i<<'\t';
	}
	cout<<endl;

	// simplification
	auto it3 = lower_bound(A.begin(), A.end(), 100);

	for(int x: A)
	{
		cout<<x<<"\t";
	}

}