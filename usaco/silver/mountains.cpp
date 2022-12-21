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

const int MAX_N = 1e5 + 1;
int x[MAX_N], y[MAX_N];
int pos[MAX_N], neg[MAX_N];
int cid[MAX_N];

bool cmp(int a, int b) {
  if (neg[a] == neg[b]) return pos[a] > pos[b];
  return neg[a] < neg[b];
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    pos[i] = x[i] + y[i], neg[i] = x[i] - y[i];
    cid[i] = i;
  }
  sort(cid, cid + n, cmp);
  int mx_pos = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    if (pos[cid[i]] > mx_pos) {
      ans += 1;
      mx_pos = pos[cid[i]];
    }
  }
  cout << ans << endl;
  return 0;
}