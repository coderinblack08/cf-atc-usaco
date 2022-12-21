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

int indexing_fn(char c) {
  if (c == 'A')
    return 0;
  if (c == 'C')
    return 1;
  if (c == 'G')
    return 2;
  if (c == 'T')
    return 3;
  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> striped(n), solid(n);
  for (int i = 0; i < n; i++) {
    cin >> striped[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> solid[i];
  }
  int ans = 0;
  // char genes[4] = {'A', 'C', 'G', 'T'};
  for (int a = 0; a < m; a++) {
    for (int b = 0; b < m; b++) {
      for (int c = 0; c < m; c++) {
        if (a != b && b != c && a != c) {
          bool works = true;
          bool in_solid[64] = {false};
          for (int i = 0; i < n; i++) {
            int sixteens = (indexing_fn(solid[i][a])) * pow(4, 2);
            int fours = (indexing_fn(solid[i][b])) * pow(4, 1);
            int ones = (indexing_fn(solid[i][c])) * pow(4, 0);
            in_solid[sixteens + fours + ones] = true;
          }
          for (int i = 0; i < n; i++) {
            int sixteens = (indexing_fn(striped[i][a])) * pow(4, 2);
            int fours = (indexing_fn(striped[i][b])) * pow(4, 1);
            int ones = (indexing_fn(striped[i][c])) * pow(4, 0);
            if (in_solid[sixteens + fours + ones]) {
              works = false;
              break;
            }
          }
          if (works) {
            ans += 1;
          }
        }
      }
    }
  }
  cout << ans / 6;
  return 0;
}
