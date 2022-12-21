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

char pasture[5][5];
set<string> s;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void trace_path(int i, int j, string path) {
  if (path.size() == 6) {
    // cerr << path << endl;
    s.insert(path);
    return;
  }
  for (int k = 0; k < 4; k++) {
    int di = dx[k] + i, dj = dy[k] + j;
    if (di >= 0 && di < 5 && dj >= 0 && dj < 5) {
      trace_path(di, dj, path + pasture[di][dj]);
    }
  }
}

int main() {
  s = {};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> pasture[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      trace_path(i, j, "");
    }
  }
  cout << s.size() << endl;
  return 0;
}