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

const int MAX_N = 101;
int adj[MAX_N][MAX_N];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> adj[i][j];
    }
  }

  queue<int> q;
  vector<bool> used(n);
  vector<int> levels[n];
  vector<int> d(n);

  d[m] = 0;
  q.push(m);
  used[m] = true;
  levels[0].push_back(m);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (adj[v][i] && !used[i]) {
        used[i] = true;
        q.push(i);
        d[i] = d[v] + 1;
        levels[d[i]].push_back(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (levels[i].size() == 0) break;
    sort(levels[i].begin(), levels[i].end());
    for (auto u : levels[i]) {
      cout << u << " ";
    }
    cout << endl;
  }
  return 0;
}