#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>

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

struct Range {
  int l, r, id;
  bool operator<(const Range &o) const {
    if (l == o.l) return r < o.r;
    return l < o.l;
  }
};

int main() {
  setIO();
  int n;
  cin >> n;

  vector<Range> ranges(n);
  vector<int> contained(n), contains(n);
  ordered_set<pi> right_boundaries;

  for (int i = 0; i < n; i++) {
    cin >> ranges[i].l >> ranges[i].r;
    ranges[i].id = i;
  }

  sort(all(ranges));

  for (int i = 0; i < n; i++) {
    right_boundaries.insert(mp(ranges[i].r, -1 * i));
    contained[ranges[i].index] = 
      sz(right_boundaries) 
      - right_boundaries.order_of_key(mp(ranges[i].r, -1 * i)) - 1;
  }

  right_boundaries.clear();

  for (int i = n - 1; i >= 0; i--) {
    right_boundaries.insert(mp(ranges[i].r, -1 * i));
    contains[ranges[i].index] = 
      right_boundaries.order_of_key(mp(ranges[i].r, -1 * i));
  }

  for (int i = 0; i < n; i++) cout << contains[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++) cout << contained[i] << " ";
  cout << endl;

  return 0;
}
