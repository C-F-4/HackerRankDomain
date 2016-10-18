/*
Consider an array of n integers, A = [a0, a1, ..., an-1], where all but one of the integers occur in pairs. In other words, every element in A occurs exactly twice except for one unique element.

Given A, find and print the unique element.

Input Format

The first line contains a single integer, n, denoting the number of integers in the array. 
The second line contains n space-separated integers describing the respective values in A.

Constraints

1 <= n <= 100
It is guaranteed that n is an odd number.
0 <= a_i <= 100, where 0 <= i <= n

Output Format

Print the unique number that occurs only once in  on a new line.

Sample Input 0

1
1
Sample Output 0

1
Explanation 0 
The array only contains a single 1, so we print 1 as our answer.

Sample Input 1

3
1 1 2
Sample Output 1

2
Explanation 1 
We have two 1's and one 2. We print 2, because that's the only unique element in the array.

Sample Input 2

5
0 0 1 2 1
Sample Output 2

2
Explanation 2 
We have two 0's, two 1's, and one 2. We print 2, because that's the only unique element in the array.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <climits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/* Space Complexity: O(1) */
/*  Strictly follows the XOR property the A ^ A = 0, leaving out only our lonely integer in tmp variable
    */
/*  It won't work if multiple odd repitions are there of numbers 
    */

int LonelyInteger(vector < int > a, int overrider) {
    int tmp = a[0];
    for(int i = 1; i < a.size(); i++) {
        tmp ^= a[i];
    }
    return tmp;
}

/*  Space Complexity: O(1), since the constraints specifically says 0 <= a[i] <= 100,
    So function "first" requires some fixed range to define our RANGE-based array
    and program'll require that much extra space to run
    and second the space required will be too much if our range is let's say in millions it won't be that much efficient
    */
/*  The problem it solves is if the input array doesn't follow the "every element is repeated ONLY twice except ONE" 
    it'll still be able to find the lonely integer unlike the first function
    */
int LonelyInteger(vector < int > a, double overrider) {
    const int RANGE = 101;
    size_t size = a.size();
    if(size == 0) {
        clog << "Size is zero";
        return INT_MIN;
    }
    else if(size == 1) {
        return a.at(0);
    }
    else {
        int arr[RANGE] = {0};
        int t = 0;
        for(int i = 0; i < size; i++) {
            arr[a.at(i)]++;
        }
        for(int i = 0; i < RANGE; i++) {
            if(arr[i] == 1) { t = i; clog << i << endl; }
        }
        return t;
    }
}

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = LonelyInteger(_a, 1.1);
    cout << res;
    
    return 0;
}
