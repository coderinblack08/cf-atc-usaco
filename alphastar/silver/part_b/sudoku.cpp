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

int board[9][9];

bool check(int i, int j, int v) {
  int row = i - i % 3, column = j - j % 3;
  for (int x = 0; x < 9; x++)
    if (board[x][j] == v) return false;
  for (int y = 0; y < 9; y++)
    if (board[i][y] == v) return false;
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (board[row + x][column + y] == v) return false;
    }
  }
  return true;
}

bool dfs(int i, int j) {
  if (i == 9) return true;
  if (j == 9) return dfs(i + 1, 0);
  if (board[i][j] != 0) return dfs(i, j + 1);
  for (int c = 1; c <= 9; c++) {
    if (check(i, j, c)) {
      board[i][j] = c;
      if (dfs(i, j + 1)) return true;
      board[i][j] = 0;
    }
  }
  return false;
}

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
    }
  }
  auto possible = dfs(0, 0);
  if (possible) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "NO SOLUTION" << endl;
  }
  return 0;
}