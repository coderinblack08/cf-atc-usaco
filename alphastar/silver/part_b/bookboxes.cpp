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

int n, ans;
vector<int> books;

void dfs(int a, int b, int c, int curr) {
  // vector<int> sizes = {a, b, c};
  // sort(sizes.begin(), sizes.end(), greater<int>());
  int first = max(a, max(b, c));
  int last = min(a, min(b, c));
  int middle;
  if (a == first && c == last) {
    middle = b;
  } else if (b == first && a == last) {
    middle = c;
  } else {
    middle = a;
  }
  if (first > ans) return;
  if (curr == n) {
    ans = min(ans, first);
    return;
  }
  auto next = books[curr++];
  set<int> vis;
  dfs(a + next, b, c, curr);
  dfs(a, b + next, c, curr);
  dfs(a, b, c + next, curr);
}

int main() {
  cin >> n;
  books.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> books[i];
  }
  ans = INT_MAX;
  dfs(0, 0, 0, 0);
  cout << ans;
  return 0;
}