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

int x[3010], y[3010], t[3010];
char arr[6010][6010];
int xz, yz, gz;

int compress(int a[], int z) {
  memcpy(t, a, sizeof(t));
  sort(t, t + z);
  int nz = distance(t, unique(t, t + z));
  for (int i = 0; i < z; i++) {
    a[i] = distance(t, lower_bound(t, t + nz, a[i])) * 2;
    // multiply by 2 to allow for gaps in between significant points that have gaps
    // checkout the first example case in which the gap between the middle vert line
    // and the top horz line is mushed together.
  }
  return nz * 2;
}

void dfs(int x, int y) {
  if (x < 0 || x >= xz || y < 0 || y >= yz) return;
  if (arr[x][y] == 'X') return;
  gz += (arr[x][y] == 'S');
  arr[x][y] = 'X';

  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}

int main() {
  setIO("schoolyard");
  int n, m;
  cin >> n >> m;
  int z = 0;
  x[z] = y[z++] = -1e9;
  x[z] = y[z++] = 1e9;
  for (int i = 0; i < 2 * n; i++) {
    cin >> x[z] >> y[z++];
  }
  for (int i = 0; i < m; i++) {
    cin >> x[z] >> y[z++];
  }
  xz = compress(x, z);
  yz = compress(y, z);
  memset(arr, '.', sizeof(arr));
  for (int i = 0; i < n; i++) {
    // compress doesn't sort x or y
    // account for the buffer 1e9, -1e9 values and add 2 respectively
    int a = i * 2 + 2;
    int b = i * 2 + 3;
    int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];
    if (x1 == x2) {
      if (y1 > y2) swap(y1, y2);
      while (y1 != y2) {
        arr[x1][y1] = 'X';
        y1++;
      }
    }
    if (y1 == y2) {
      if (x1 > x2) swap(x1, x2);
      while (x1 != x2) {
        arr[x1][y1] = 'X';
        x1++;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    // buffer by (2 * n) + 2 to get to the students
    int a = i + (2 * n) + 2;
    arr[x[a]][y[a]] = 'S';
  }
  for (int i = 0; i < xz; i++) {
    for (int j = 0; j < yz; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    // buffer by (2 * n) + 2 to get to the students
    int a = i + (2 * n) + 2;
    gz = 0;
    dfs(x[a], y[a]);
    ans = max(ans, gz);
  }
  cout << ans << endl;
  return 0;
}