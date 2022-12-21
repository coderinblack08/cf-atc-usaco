#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX_N = 2501;
int n, PS[MAX_N][MAX_N];
pair<int, int> P[MAX_N];

bool y_comp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int get_sum(int from_x, int to_x, int from_y, int to_y) {
  return PS[to_x][to_y] - PS[from_x - 1][to_y] - PS[to_x][from_y - 1] +
         PS[from_x - 1][from_y - 1];
}

int main() {
  cin >> n;
  // io
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    P[i] = {x, y};
  }
  // we are given every x, y is unique
  // coord compression
  sort(P, P + n);
  for (int i = 0; i < n; i++) {
    P[i].first = i + 1;
  }
  sort(P, P + n, y_comp);
  for (int i = 0; i < n; i++) {
    P[i].second = i + 1;
  }
  // init psum array
  for (int i = 0; i < n; i++) {
    PS[P[i].first][P[i].second] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      PS[i][j] += PS[i - 1][j] + PS[i][j - 1] - PS[i - 1][j - 1];
    }
  }
  ll ans = n + 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans += get_sum(min(P[i].first, P[j].first), max(P[i].first, P[j].first), 1, min(P[i].second, P[j].second)) * get_sum(min(P[i].first, P[j].first), max(P[i].first, P[j].first), max(P[i].second, P[j].second), n);
    }
  }
  cout << ans << endl;
  return 0;
}
