#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int arr[], int size, int k) {
  int aux[size];
  for(int i = 0; i < size; i++) {
    int new_index = i + k;
    while(new_index >= size) {
      new_index -= size;
    }
    aux[new_index] = arr[i];
  }
  for(int i = 0; i < size; i++) {
    arr[i] = aux[i];
  }
  return;
}

int main(void) {
  int n, k, q;
  cin >> n >> k >> q;
  int arr[n] = {0};
  for(int i = 0; i < n; i++) {
     cin >> arr[i];
  }
  rotate(arr, n, k);
  int index;
  for(int i = 0; i < q; i++) {
    cin >> index;
    cout << arr[index] << endl;
  }
  return 0;
}
