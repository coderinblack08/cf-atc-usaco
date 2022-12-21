#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int n, q;

int main() {
  cin >> n >> q;
  vector<int> bales(n);
  for (int i = 0; i < n; i++) cin >> bales[i];
  sort(begin(bales), end(bales));
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;

    // 2 3 5 7
    cout << upper_bound(begin(bales), end(bales), b) - lower_bound(begin(bales), end(bales), a)
         << endl;
  }
  return 0;
}