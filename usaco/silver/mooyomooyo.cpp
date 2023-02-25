#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int n, k;
int board[101][11];
bool visited[101][11];
vector<pi> comp[101 * 11];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int color, int cp) {
  if (x < 0 || x >= n || y < 0 || y >= 10) return;
  if (visited[x][y]) return;
  if (board[x][y] != color) return;
  visited[x][y] = true;
  comp[cp].pb(mp(x, y));
  for (int i = 0; i < 4; i++) {
    dfs(x + dx[i], y + dy[i], color, cp);
  }
}

bool move() {
  memset(visited, false, sizeof(visited));
  // find connected components
  int c = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10; j++)
      if (!visited[i][j] && board[i][j] != 0) dfs(i, j, board[i][j], c++);
  vi v;
  for (int i = 0; i < c; i++) {
    if (comp[i].size() >= k) {
      v.pb(i);
    }
  }
  if (v.size() == 0) return false;
  for (auto x : v)
    for (auto y : comp[x]) board[y.f][y.s] = 0;

  for (int c = 0; c < 10; c++) {
    queue<int> q;
    for (int r = n - 1; r >= 0; r--) {
      if (board[r][c] != 0) q.push(board[r][c]);
    }
    for (int r = n - 1; r >= 0; r--) {
      if (q.empty()) {
        board[r][c] = 0;
      } else {
        board[r][c] = q.front();
        q.pop();
      }
    }
  }
  for (int i = 0; i < c; i++) comp[i].clear();
  return true;
}

int main() {
  setIO("mooyomooyo");
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 10; j++) {
      board[i][j] = s[j] - '0';
    }
  }
  while(move());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
  return 0;
}
