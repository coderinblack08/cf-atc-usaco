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
  int a, b;
  cin >> a >> b;
  int n, p;
  cin >> n >> p;

  vector<int> buckets(n);
  for (int i = 0; i < n; i++) cin >> buckets[i];

  queue<int> q;
  vector<bool> used(p);
  vector<int> d(p);

  q.push(a);
  used[a] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == b) {
      cout << d[v] << endl;
      return 0;
    }
    for (int u : buckets) {
      int new_v = (v * u) % p;
      if (!used[new_v]) {
        used[new_v] = true;
        q.push(new_v);
        d[new_v] = d[v] + 1;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}