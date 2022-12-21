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
  queue<int> q;
  vector<int> d(3 * n + 1, -1);

  q.push(1);
  d[1] = 0;

  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (v == n) {
      cout << d[v] << endl;
      break;
    }
    // if you jump pass n, there only operation is to backtrack to n
    if (v > n) {
      if (d[v - 1] == -1) {
        q.push(v - 1);
        d[v - 1] = d[v] + 1;
      }
    } else {
      for (int u : {v - 1, v + 1, v * 3}) {
        if (u < 0) continue;
        if (d[u] != -1) continue;
        q.push(u);
        d[u] = d[v] + 1;
      }
    }
  }
  return 0;
}

// 165
// 1 -> 2 -> 6 -> 18 -> 54 -> 55 -> 165
