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

int main() {
  int n, t, k;
  cin >> n >> t >> k;
  assert(t == 1);
  int l = 1, r = n;
  while (l <= r) {
    int m = (l + r + 1) / 2, count;
    cout << "? 1 " << m << endl;
    cin >> count;
    if (m - count < k) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << "! " << r + 1 << endl;
  return 0;
}
