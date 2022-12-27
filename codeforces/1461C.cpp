#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
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

vector<pi> to_remove;

bool works(vector<int> *v, int x) {
  to_remove.clear();
  multiset<int> ms;
  for (auto i : *v) ms.insert(i);
  while (!ms.empty()) {
    // always get the largest element of ms
    int a = *ms.rbegin();
    ms.erase(ms.find(a));
    int b = x - a;
    // if we can't continue, exit
    if (ms.find(b) == ms.end()) return false;
    ms.erase(ms.find(b));
    to_remove.pb(mp(a, b));
    x = a;
  }
  return ms.empty();
}

void solve() {
  int n;
  cin >> n;
  n *= 2;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(all(v));
  for (int i = 0; i < n - 1; i++) {
    // find possible x by combining largest and every other index
    int x = v[i] + v[n - 1];
    if (works(&v, x)) {
      cout << "YES" << endl;
      cout << x << endl;
      for (auto p : to_remove) {
        cout << p.f << " " << p.s << endl;
      }
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
