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
  setIO("bcount");
  int n, q;
  cin >> n >> q;
  vector<int> B[3];
  for (int i = 0; i < 3; i++) {
    B[i].resize(n + 1);
    fill(all(B[i]), 0);
  }
  for (int i = 1; i <= n; i++) {
    int breed;
    cin >> breed;
    B[breed - 1][i] += 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      B[j][i] += B[j][i - 1];
    }
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << B[0][b] - B[0][a - 1] << " "
         << B[1][b] - B[1][a - 1] << " "
         << B[2][b] - B[2][a - 1] << "\n";
  }
  return 0;
}