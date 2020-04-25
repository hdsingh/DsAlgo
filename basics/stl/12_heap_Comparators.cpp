// Ref: GeeksforGeeks, StackOverflow
// C++ program to use priority_queue to implement Min Heap 
// for user defined class 
#include <bits/stdc++.h> 
using namespace std; 

// User defined class, Point 
class Point 
{ 
int x; 
int y; 
public: 
Point(int _x, int _y) 
{ 
	x = _x; 
	y = _y; 
} 
int getX() const { return x; } 
int getY() const { return y; } 
}; 


// 3 Ways:

// 1. Class based
class Comparator1
{ 
public: 
	int operator() (const Point& p1, const Point& p2){ 
		return p1.getX() > p2.getX(); 
	} 
}; 

// 2. Struct Based
struct Comparator2 {
  bool operator() (const Point& p1, const Point& p2){
		return p1.getX() > p2.getX(); 
	} 
};

// Max heap : a<b
// Min heap : a>b

int main () 
{   
	// Creates a Min heap of points (order by x coordinate) 
	priority_queue <Point, vector<Point>, Comparator1 > pq; 

	// Lambda functions
    auto Comparator3 = [](const Point& p1, const Point& p2){ 
		return p1.getX() > p2.getX(); 
	};
	priority_queue<Point, vector<Point>, decltype(Comparator3)> pq1(Comparator3);


	// Insert points into the min heap 
	pq.push(Point(10, 2)); 
	pq.push(Point(2, 1)); 
	pq.push(Point(1, 5)); 

	// One by one extract items from min heap 
	while (pq.empty() == false) 
	{ 
		Point p = pq.top(); 
		cout << "(" << p.getX() << ", " << p.getY() << ")"; 
		cout << endl; 
		pq.pop(); 
	} 

	return 0; 
} 

// Usage Example: 
// 1. 347.top-k-frequent-elements.cpp 
// 2. 373.find-k-pairs-with-smallest-sums.cpp 
// 3. 451.sort-characters-by-frequency.cpp 