/*
Sandy likes palindromes. A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as it does forward. For example, madam is a palindrome.

On her 7th birthday, Sandy's uncle, Richie Rich, offered her an n-digit check which she refused because the number was not a palindrome. Richie then challenged Sandy to make the number palindromic by changing no more than k digits. Sandy can only change 1 digit at a time, and cannot add digits to (or remove digits from) the number.

Given k and an n-digit number, help Sandy determine the largest possible number she can make by changing <=k digits.

Note: Treat the integers as numeric strings. Leading zeros are permitted and can't be ignored (So 0011 is not a palindrome, 0110 is a valid palindrome). A digit can be modified more than once.

Input Format

The first line contains two space-separated integers, n (the number of digits in the number) and k (the maximum number of digits that can be altered), respectively. 
The second line contains an n-digit string of numbers that Sandy must attempt to make palindromic.

Constraints:
0 < n <= pow(10, 5)
0 <= k <= pow(10, 5)
Each character i in the number is an integer where 0 <= i <= 9.

Output Format

Print a single line with the largest number that can be made by changing no more than k digits; if this is not possible, print -1.

Sample Input 0

4 1
3943
Sample Output 0

3993
Sample Input 1

6 3
092282
Sample Output 1

992299
Sample Input 2

4 1
0011
Sample Output 2

-1
Explanation

Sample 0

There are two ways to make 3943 a palindrome by changing exactly k=1 digits:
1. 3943 -> 3443
2. 3943 -> 3993
3993 > 3443, so we print 3993.
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

typedef long long ll;

using namespace std;

void print(bool arr[], ll size) {
    for(ll i = 0; i < size; i++) {
        clog << arr[i] << ' ';
    }
    clog << endl;
}

bool isPalindrome(string str, ll size) {
    for(ll i = 0; i < size / 2; i++) {
        if(str[i] != str[size - i - 1]) {
            return false;
        }
    }
    return true;
}

string makePalindrome(string num, ll size, ll mods, bool modded[]) {
    // tells ya whether more mods are possible
    bool can_change = true;
    // alter ONCE so that it stays "maximum"
    ll i = 0;
    for(i = 0; i < size / 2; i++) {
        if(num[i] != num[size - i - 1]) {
            if(mods > 0) {
                if(num[i] > num[size - i - 1]) {
                    num[size - i - 1] = num[i];
                    modded[size - i - 1] = true;
                    mods--;
                }
                else {
                    num[i] = num[size - i - 1];
                    modded[i] = true;
                    mods--;
                }
            }
            else {
                can_change = false;
            }
        }
        else {
            continue;
        }
    }
    clog << num << ' ' << mods << endl;
    if(isPalindrome(num, size)) {
        // print(modded, size);
        if(!mods) {
            return num;
        }
        else {
            clog << "here";
            // we've more mods left to update pairs
            // which we modified
            // Also remember that you have +1 mod for each pair you update
            for(ll i = 0; i < size / 2 && mods; i++) {
                // change only if its not '9'
                if(num[i] != '9') {
                    // if modded then need one mod as +1 is added
                    if(modded[size-i-1] || modded[i]) {
                        num[i] = '9';
                        num[size - i - 1] = '9';
                        mods--;
                    }
                    // else need two mods to make the update
                    else if((! modded[size-i-1] || ! modded[i]) && mods >= 2) {
                        num[i] = '9';
                        num[size - i - 1] = '9';
                        mods-=2;
                    }
                }
            }
            // Edge Case
            if(size % 2 && mods && num[size / 2] != '9') {
                num[size / 2] = '9';
                mods--;
            }
            return num;
        }
    }
    return "-1";
}

int main(){
    long long int n;
    long long int k;
    cin >> n >> k;
    string number;
    cin >> number;
    bool modded[n] = {false};
    // Edge Cases
    if(n == 1) {
        if(k == 0) {
            cout << number;
        }
        else {
            cout << 9;
        }
    }
    else {
        cout << makePalindrome(number, n, k, modded) << endl;
    }
    return 0;
}
