#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX_N = 2e5 + 1;

int n, x;
pair<int, int> A[MAX_N];

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A, A + n);
  int l = 0, r = n - 1;
  while (l < r) {
    ll s = A[l].first + A[r].first;
    if (s < x) {
      l++;
    } else if (s > x) {
      r--;
    } else {
      cout << A[l].second + 1 << " " << A[r].second + 1;
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
}