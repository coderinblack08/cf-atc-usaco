#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX_N = 100000;
int n, q, min_since_last[26], prefix[MAX_N + 1], suffix[MAX_N + 2];

int main() {
  string s;
  cin >> n >> q >> s;
  for (int c = 0; c < 26; c++) min_since_last[c] = -1;
  for (int i = 1; i <= n; i++) {
    int curr = s[i - 1] - 'A';
    for (int c = 0; c < 26; c++) min_since_last[c] = min(min_since_last[c], curr);
    prefix[i] = prefix[i - 1];
    if (min_since_last[curr] < curr) prefix[i]++;
    min_since_last[curr] = curr;
  }
  for (int c = 0; c < 26; c++) min_since_last[c] = -1;
  for (int i = n; i >= 1; i--) {
    int curr = s[i - 1] - 'A';
    for (int c = 0; c < 26; c++) min_since_last[c] = min(min_since_last[c], curr);
    suffix[i] = suffix[i + 1];
    if (min_since_last[curr] < curr) suffix[i]++;
    min_since_last[curr] = curr;
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << prefix[a - 1] + suffix[b + 1] << endl;
  }
  return 0;
}
