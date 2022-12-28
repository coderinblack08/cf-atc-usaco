#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();
  int n;
  cin >> n;
  vector<int> c(n), children[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x >> c[i];
    if (x != -1) children[x - 1].pb(i);
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (c[i] == 1) {
      bool works = 1;
      for (int x : children[i]) {
        if (c[x] == 0) {
          works = 0;
          break;
        }
      }
      if (works) ans.pb(i + 1);
    }
  }
  if (ans.empty()) cout << -1;
  else for (int x : ans) cout << x << " ";
  cout << "\n";
  return 0;
}
