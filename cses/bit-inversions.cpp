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

string s;
int m;
// all indices when s[i] != s[i + 1]
set<int> diff;
multiset<int> result;

void modify(int k) {
  if (k == 0 || k == s.size()) return;
  auto it = diff.find(k);
  // if it's a diff point, you have to merge [b, k] and [k, a] into [b, a]
  if (it != diff.end()) {
    int a = *prev(it), b = *next(it);
    result.erase(result.find(k - a));
    result.erase(result.find(b - k));
    result.insert(b - a);
    // no longer a difference point after inversion
    diff.erase(it);
  } else {
    // otherwise, separate [b, a] into [b, k] and [k, a]
    it = diff.insert(k).f;
    int a = *prev(it), b = *next(it);
    result.erase(result.find(b - a));
    result.insert(k - a);
    result.insert(b - k);
  }
}

int main() {
  cin >> s >> m;
  diff.insert(0);
  diff.insert(s.size());
  for (int i = 0; i < s.size() - 1; i++)
    if (s[i] != s[i + 1]) diff.insert(i + 1);
  for (auto it = diff.begin(); next(it) != diff.end(); ++it)
    result.insert(*next(it) - *it);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;  // one-indexed
    modify(k - 1);
    // the following index might not be a diff anymore...
    modify(k);
    cout << *result.rbegin() << " ";
  }
  return 0;
}