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
  int rows, columns;
  cin >> rows >> columns;
  vector<string> puzzle(rows);
  for (int i = 0; i < rows; i++) {
    cin >> puzzle[i];
  }
  int ans = 0;
  for (char m = 'A'; m <= 'Z'; m++) {
    for (char o = 'A'; o <= 'Z'; o++) {
      int count = 0;
      if (m != o && m != 'M' && o != 'O') {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < columns; j++) {
            int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
            int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
            if (puzzle[i][j] == m) {
              for (int k = 0; k < 8; k++) {
                string path = "";
                path += puzzle[i][j];
                int curr_x = i, curr_y = j;
                for (int j = 0; j < 2; j++) {
                  curr_x += dx[k];
                  curr_y += dy[k];
                  if (curr_x < 0 || curr_x >= rows || curr_y < 0 ||
                      curr_y >= columns) {
                    break;
                  }
                  path += puzzle[curr_x][curr_y];
                }
                // cout << m << " " << o << " " << path << endl;
                if (path.size() == 3)
                  if (path[0] == m && path[1] == o && path[2] == o) {
                    cerr << m << " " << o << " " << path << endl;
                    count++;
                  }
              }
            }
          }
        }
      }
      ans = max(ans, count);
    }
  }
  cout << ans;
  return 0;
}
