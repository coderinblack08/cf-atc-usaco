#include <bits/stdc++.h>
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
  int n;
  cin >> n;
  int a[n], parent[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    parent[a[i]]++;
  }
  int ans = n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (parent[i] == 0) {
      q.push(i);
      ans--;
    }
  }
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    parent[a[top]]--;
    if (parent[a[top]] == 0) {
      q.push(a[top]);
      ans--;
    }
  }
  cout << ans;
  return 0;
}