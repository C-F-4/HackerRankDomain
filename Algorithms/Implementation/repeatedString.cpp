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
