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

int n, k, p;

int main() {
  cin >> n >> k >> p;
  vector<int> q;
  for (int i = 0; i < k; i++) {
    q.push_back(i + 1);
  }
  vector<int> harry;
  for (int turn = 1; q.size() > 0; turn = (turn + 1) % n) {
    int curr = q.front();
    q.erase(q.begin());
    if (turn == 0) {
      harry.push_back(curr);
    }
    for (int i = 0; i < p; i++) {
      q.push_back(q.front());
      q.erase(q.begin());
    }
  }
  sort(all(harry));
  for (int acorn : harry) cout << acorn << endl;
  return 0;
}