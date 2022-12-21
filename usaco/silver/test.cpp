#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  vector<int> a = {1, 2, 3, 4, 5, 5, 6};
  sort(all(a));
  for (int c : a) cout << c << " ";
  cout << endl;
  cout << upper_bound(all(a), 4) - begin(a) << " " << lower_bound(all(a), 4) - begin(a) << endl;
  return 0;
}