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

int main() {
    int result = 0;
    size_t size = 0;
    std::cin >> size;
    int input = 0;
    for(int i = 0; i < size; i++) {
        std::cin >> input;
        if( i == 0 ) {
            result = input;
        }
        else {
            result ^= input;
        }
    }
        
    if(size == 0) {
        std::cout << "No number is lonely" << std::endl;
    }
    else {
        std::cout << result << std::endl;
    }
    
    return 0;
}
