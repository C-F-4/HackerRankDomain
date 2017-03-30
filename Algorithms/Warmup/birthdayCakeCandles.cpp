/*
Colleen is turning n years old! She has n candles of various heights on her cake, and candle i has height h(i). Because the taller 
candles tower over the shorter ones, Colleen can only blow out the tallest candles.

Given the height h(i) for each individual candle, find and print the number of candles she can successfully blow out.

Input Format

The first line contains a single integer, n, denoting the number of candles on the cake. 
The second line contains n space-separated integers, where each integer i describes the height of candle i.

Constraints
1 =< n <= pow(10, 5)
1 =< height(i) <= pow(10,7)

Output Format

Print the number of candles Colleen blows out on a new line.

Sample Input 0

4
3 2 1 3
Sample Output 0

2
Explanation 0

We have one candle of height 1, one candle of height 2, and two candles of height 3. Colleen only blows out the tallest candles, 
meaning the candles where height=3. Because there are 2 such candles, 
we print 2 on a new line.
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

int candlesBlown(vector<int> h) {
    int max = 0;
    for(int i = 0; i < h.size(); i++) {
        if(h.at(i) > max) {
            max = h.at(i);
        }
    }
    int ct = 0;
    for(int i = 0; i < h.size(); i++) {
        if(h.at(i) == max) {
            ct ++;
        }
    }
    return ct;
}

int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int height_i = 0;height_i < n;height_i++){
       cin >> height[height_i];
    }
    cout << candlesBlown(height) << endl;
    return 0;
}
