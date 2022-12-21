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

using pii = pair<int, int>;
vector<vector<char>> board;
const int dx[4] = {-1, 1, 1, -1};
const int dy[4] = {1, 1, -1, -1};
int opponent_count;

void move(int i, int j, vector<pii> path) {
  if (path.size() == opponent_count + 1) {
    for (auto p : path) {
      cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    return;
  }
  for (int k = 0; k < 4; k++) {
    int di = i + dy[k], dj = j + dx[k];
    int dii = di + dy[k], djj = dj + dx[k];
    if (di < 0 || di >= (int)board.size() || dj < 0 || dj >= (int)board[0].size() ||
        dii < 0 || dii >= (int)board.size() || djj < 0 || djj >= (int)board[0].size()) continue;
    if (board[di][dj] == 'o' && board[dii][djj] == '+') {
      board[di][dj] = '+';
      vector<pii> new_path = path;
      new_path.push_back(make_pair(dii, djj));
      move(dii, djj, new_path);
      board[di][dj] = 'o';
    }
  }
}

int main() {
  int n;
  char c;
  cin >> n;
  board.resize(n);
  opponent_count = 0;
  vector<pii> fj_k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c;
      if (c == 'K') fj_k.push_back(make_pair(i, j));
      if (c == 'o') opponent_count++;
      board[i].push_back(c);
    }
  }
  for (auto [i, j] : fj_k) {
    move(i, j, vector<pii>({make_pair(i, j)}));
  }
}