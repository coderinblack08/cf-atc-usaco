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

int n, ans;
bool board[16][16];

bool valid(int row, int col) {
  for (int i = 0; i < row; i++) {
    if (board[i][col]) return false;
  }
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) return false;
  }
  for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
    if (board[i][j]) return false;
  }
  return true;
}

void dfs(int row) {
  if (row == n) {
    ans++;
    return;
  }
  for (int col = 0; col < n; col++) {
    if (valid(row, col)) {
      board[row][col] = true;
      dfs(row + 1);
      board[row][col] = false;
    }
  }
}

int main() {
  cin >> n;
  dfs(0);
  cout << ans;
  return 0;
}