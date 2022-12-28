// segment tree implementation for range sum queries
// https://cp-algorithms.com/data_structures/segment_tree.html#update-queries
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, t[4 * N];

void build(int a[], int v, int tl, int tr) {
  // case when we reach the leaves
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    // recursively go down
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

void build(int a[]) {
  // start from root
  build(a, 1, 0, n - 1);
}

int sum(int v, int tl, int tr, int l, int r) {
  if (tl > r || tr < l)
    return 0;
  if (l <= tl && tr <= r)
    return t[v];
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tm, l, r) + sum(v * 2 + 1, tm + 1, tr, l, r);
}

int sum(int l, int r) {
  // start from root
  return sum(1, 0, n - 1, l, r);
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(v * 2, tl, tm, pos, val);
    } else {
      update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

void update(int pos, int val) {
  // start from root
  update(1, 0, n - 1, pos, val);
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  n = sizeof(a) / sizeof(a[0]);
  build(a);
  cout << sum(0, 2) << endl;
  update(0, 10);
  cout << sum(0, 2) << endl;
  return 0;
}
