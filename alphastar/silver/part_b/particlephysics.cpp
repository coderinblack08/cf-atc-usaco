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

int n;
const int MAX_N = 12;
pair<int, int> v[MAX_N + 1];
int next_on_right[MAX_N + 1];
int partner[MAX_N + 1];

bool check_cycle() {
  for (int i = 1; i <= n; i++) {
    int curr = i;
    for (int count = 0; count < n; count++) {
      curr = next_on_right[partner[curr]];
    }
    if (curr != 0) return true;
  }
  return false;
}

int pair_up() {
  int i, total = 0;
  for (i = 1; i <= n; i++) {
    if (partner[i] == 0) break;
  }
  if (i > n) {
    return check_cycle();
  }
  for (int j = i + 1; j <= n; j++) {
    if (partner[j] == 0) {
      partner[i] = j;
      partner[j] = i;
      total += pair_up();
      partner[i] = 0;
      partner[j] = 0;
    }
  }
  return total;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (v[j].first > v[i].first && v[i].second == v[j].second) {
        if (next_on_right[i] == 0 || v[j].first - v[i].first < v[next_on_right[i]].first - v[i].first) {
          next_on_right[i] = j;
        }
        break;
      }
    }
  }
  cout << pair_up() << endl;
  return 0;
}