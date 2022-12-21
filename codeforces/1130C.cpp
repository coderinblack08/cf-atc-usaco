#include <bits/stdc++.h>
using namespace std;

int n;
bool mp[51][51];
bool vis[51][51];

void floodfill(int x, int y, vector<pair<int, int>>& v) {
  if (x < 0 || x >= n || y < 0 || y >= n || !mp[x][y] || vis[x][y]) return;
  vis[x][y] = true;
  v.push_back({x, y});
  floodfill(x - 1, y, v);
  floodfill(x + 1, y, v);
  floodfill(x, y - 1, v);
  floodfill(x, y + 1, v);
}

int main() {
  cin >> n;
  int r1, r2, c1, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  r1--;
  r2--;
  c1--;
  c2--;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      mp[i][j] = s[j] == '0' ? true : false;
    }
  }
  vector<pair<int, int>> a, b;
  floodfill(r1, c1, a);
  floodfill(r2, c2, b);
  int ans = INT_MAX;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      int tmp = int(pow(a[i].first - b[j].first, 2) + pow(a[i].second - b[j].second, 2));
      ans = min(ans, tmp);
    }
  }
  if (ans == INT_MAX) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
}