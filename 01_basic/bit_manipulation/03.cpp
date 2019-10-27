#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

// case conversion
char toUpper(char c){
    return c & ~32;
}

char toLower(char c){
    return c | 32;
}

int main(){
    char a = 'a';
    a = toUpper(a);
    cout<<a<<endl;

    a = toLower('B');
    cout<<a<<endl;

    return 0;
}

// Refer: https://www.geeksforgeeks.org/case-conversion-lower-upper-vice-versa-string-using-bitwise-operators-cc/
// Explanation
// The ASCII table is constructed in such way that the binary 
// representation of lowercase letters is almost identical of binary 
// representation of uppercase letters.

// Character ‘A’ is integer 65 = (0100 0001)2, while character ‘a’ 
// is integer 97 = (0110 0001)2.
// The difference between the ASCII values of ‘a’ and ‘A’ is 32.

// So we can easily change the case of the letters either from 
// Upper to lower or lower to upper by adding or subtracting the 
// difference from the letters using bitwise operators as shown above.