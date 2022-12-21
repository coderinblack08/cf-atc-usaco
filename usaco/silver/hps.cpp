// #include <bits/stdc++.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
#define all(x) begin(x), end(x)
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("hps");
  int n;
  cin >> n;
  vector<int> A[3];
  for (int i = 0; i < 3; i++) {
    A[i].resize(n + 1);
    fill(all(A[i]), 0);
  }
  for (int i = 1; i <= n; i++) {
    char m;
    cin >> m;
    if (m == 'H') {
      A[0][i] += 1;
    } else if (m == 'P') {
      A[1][i] += 1;
    } else {
      A[2][i] += 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      A[j][i] += A[j][i - 1];
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int left = max(A[0][i], max(A[1][i], A[2][i]));
    int right = max(A[0][n] - A[0][i], max(A[1][n] - A[1][i], A[2][n] - A[2][i]));
    ans = max(ans, left + right);
  }
  cout << ans << endl;
  return 0;
}