/*
Lilah has a string, s, of lowercase English letters that she repeated infinitely many times.

Given an integer, n, find and print the number of letter a's in the first n letters of Lilah's infinite string.

Input Format

The first line contains a single string, s. 
The second line contains an integer, n.

Constraints
1 <= |s| <= 100
1 <= n <= pow(10,12)

For 25% of the test cases, n <= pow(10,6).

Output Format

Print a single integer denoting the number of letter a's in the first  n letters of the infinite string created by repeating 
s infinitely many times.

Sample Input 0

aba
10
Sample Output 0

7
Explanation 0 
The first n=10 letters of the infinite string are abaabaabaa. Because there are 7 a's, we print 7 on a new line.

Sample Input 1

a
1000000000000
Sample Output 1

1000000000000
Explanation 1 
Because all of the first n=1000000000000 letters of the infinite string are a, we print 1000000000000 on a new line.
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    int ct_a = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') { ct_a ++; }
    }
    if(ct_a == 0) { cout << 0 << endl; }
    else if(ct_a == s.length()) { cout << n << endl; }
    else {
        long tmp = n / s.length();
        long ct = tmp * ct_a;
        long x = n - tmp * s.length();
        for(int i = 0; i < x; i++) {
            if(s[i] == 'a') { ct++; }
        }
        cout << ct << endl;
    }
    return 0;
}
