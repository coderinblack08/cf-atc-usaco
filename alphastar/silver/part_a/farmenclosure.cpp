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
  int n;
  cin >> n;
  pair<int, int> x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i].first >> y[i].first;
    x[i].second = y[i].second = i;
  }
  sort(x, x + n);
  sort(y, y + n);
  int width = x[n - 1].first - x[0].first;
  int height = y[n - 1].first - y[0].first;
  int best_area = width * height;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        set<int> deleted;
        int left = 0, right = n - 1, bottom = 0, top = n - 1;
        for (auto op : {i, j, k}) {
          if (op == 0) {
            while (deleted.count(x[left].second)) left++;
            deleted.insert(x[left].second);
            left++;
          } else if (op == 1) {
            while (deleted.count(x[right].second)) right--;
            deleted.insert(x[right].second);
            right--;
          } else if (op == 2) {
            while (deleted.count(y[top].second)) top--;
            deleted.insert(y[top].second);
            top--;
          } else {
            while (deleted.count(y[bottom].second)) bottom++;
            deleted.insert(y[bottom].second);
            bottom++;
          }
        }
        int our_area = (x[right].first - x[left].first) * (y[top].first - y[bottom].first);
        best_area = min(our_area, best_area);
      }
    }
  }
  cout << best_area;
  return 0;
}