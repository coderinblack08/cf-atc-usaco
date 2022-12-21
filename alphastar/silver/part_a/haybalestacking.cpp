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
  int n, k;
  cin >> n >> k;
  vector<int> hay_bales(n);
  for (int i = 0, a, b; i < k; i++) {
    cin >> a >> b;
    hay_bales[--a]++;
    hay_bales[b]--;
  }
  for (int i = 0; i < n; i++) {
    if (i) hay_bales[i] += hay_bales[i - 1];
  }
  sort(hay_bales.begin(), hay_bales.end());
  cout << hay_bales[n / 2] << endl;
  return 0;
}