#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define ll long long
using namespace std;

typedef pair<int, int> node;
typedef pair<node, node> edge;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  int n;
  int ans = 0;
  string s;
  cin >> n >> s;

  set<edge> vis_edge;
  set<node> vis_node;
  node prev{0, 0};
  vis_node.insert(prev);

  for (int i = 0; i < n; i++) {
    auto [x, y] = prev;
    if (s[i] == 'N') y++;
    if (s[i] == 'S') y--;
    if (s[i] == 'E') x++;
    if (s[i] == 'W') x--;

    edge a{{x, y}, prev}, b{prev, {x, y}};
    node curr{x, y};
    if (vis_edge.find(a) == vis_edge.end() &&
        vis_edge.find(b) == vis_edge.end() &&
        vis_node.find(curr) != vis_node.end()) {
      ans++;
    }
    vis_edge.insert(a);
    vis_edge.insert(b);
    vis_node.insert(curr);

    prev = {x, y};
  }

  cout << ans << "\n";
  return 0;
}