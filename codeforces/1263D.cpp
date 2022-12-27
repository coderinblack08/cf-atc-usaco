#include <bits/stdc++.h>
using namespace std;

int n;
bool a['z' + 1][int(2e5) + 1], mark['z' + 1];

bool intersect(char x, char y) {
  for (int i = 0; i < n; i++) {
    if (a[x][i] & a[y][i]) return true;
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto j : s) {
      a[j][i] = true;
      mark[j] = true;
    }
  }
  for (char i = 'a'; i <= 'z'; i++) {
    if (mark[i]) {
      for (char j = 'a'; j <= 'z'; j++) {
        if (i != j && mark[j] && intersect(i, j)) {
          for (int k = 0; k < n; k++) {
            a[i][k] |= a[j][k];
          }
          mark[j] = 0;
        }
      }
    }
  }
  int ans = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    ans += mark[i];
  }
  std::cout << ans << endl;
}
