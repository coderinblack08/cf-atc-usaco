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

set<int> ans;
int A, B, C;
bool vis[21][21][21];

void dfs(int a, int b, int c) {
  if (vis[a][b][c]) return;
  vis[a][b][c] = true;
  if (a == 0) {
    ans.insert(c);
  }
  // pour a into b
  int pour = min(B - b, a);
  dfs(a - pour, b + pour, c);

  // pour a into c
  pour = min(C - c, a);
  dfs(a - pour, b, c + pour);

  // pour b into c
  pour = min(C - c, b);
  dfs(a, b - pour, c + pour);

  // pour b into a
  pour = min(A - a, b);
  dfs(a + pour, b - pour, c);

  // pour c into a
  pour = min(A - a, c);
  dfs(a + pour, b, c - pour);

  // pour c into b
  pour = min(B - b, c);
  dfs(a, b + pour, c - pour);
}

int main() {
  cin >> A >> B >> C;
  dfs(0, 0, C);
  for (auto i : ans) {
    cout << i << " ";
  }
  return 0;
}