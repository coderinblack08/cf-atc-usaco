#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int mid, int r) {
  int p = l, q = mid + 1, k = 0;
  vector<int> temp(r - l + 1);
  for (int i = l; i <= r; i++) {
    if (p > mid) {
      temp[k++] = a[q++];
    } else if (q > r) {
      temp[k++] = a[p++];
    } else if (a[p] < a[q]) {
      temp[k++] = a[p++];
    } else {
      temp[k++] = a[q++];
    }
  }
  for (int i = 0; i < k; i++) {
    a[l++] = temp[i];
  }
}

void mergesort(vector<int> &a, int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) / 2;

  mergesort(a, l, mid);
  mergesort(a, mid + 1, r);
  merge(a, l, mid, r);
}

int main() {
  vector<int> a = {7, 3, 5, 2, 1, 4, 6};
  mergesort(a, 0, a.size() - 1);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  return 0;
}
