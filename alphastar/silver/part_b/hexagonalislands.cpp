#include <bits/stdc++.h>

#include <unordered_map>
#include <unordered_set>
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

int k, h, l;
vector<vector<int>> islands;

struct Node {
  int row, col, index;
  bool operator==(const Node &p) const {
    return row == p.row && col == p.col;
  }
};

struct hash_fn {
  std::size_t operator()(const Node &node) const {
    return node.row ^ node.col;
  }
};

Node starting_point;

void generate_grid() {
  islands.resize(4 * k - 3);
  for (int i = 0; i < islands.size(); i++) {
    islands[i].resize(2 * k - 1);
    fill(islands[i].begin(), islands[i].end(), -1);
  }
  int rows = 3 * k - 3;
  int col = 0, row = rows;
  int more_in_col = k;
  int row_add_direction = 1;
  for (int i = 0; i < (3 * k * (k - 1) + 1); i++, more_in_col--, row -= 2) {
    cerr << "Node: " << i << " " << row << " " << col << " " << more_in_col << endl;
    if (more_in_col == 0) {
      col++;
      more_in_col = (row_add_direction == -1 ? 3 * k - 2 - col : k + col * row_add_direction);
      rows += row_add_direction;
      row = rows;
      if (row == islands.size() - 1) row_add_direction = -1;
    }
    islands[row][col] = i;
    if (i + 1 == h) starting_point = Node{row, col, i};
  }
}

int main() {
  cin >> k >> h >> l;
  generate_grid();
  for (auto &row : islands) {
    for (auto &col : row) {
      cerr << col << " ";
    }
    cerr << endl;
  }
  cerr << "starting point: " << starting_point.row << " " << starting_point.col << endl;
  queue<Node> q;
  unordered_map<Node, int, hash_fn> dist;
  unordered_set<Node, hash_fn> vis;
  q.push(starting_point);
  vis.insert(starting_point);
  dist[starting_point] = 0;
  set<int> ans;
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (dist[v] == l) {
      ans.insert(v.index);
      continue;
    }
    int dr[6] = {-2, 2, 1, -1, 1, -1};
    int dc[6] = {0, 0, 1, 1, -1, -1};
    for (int d = 0; d < 6; d++) {
      int new_row = v.row + dr[d];
      int new_col = v.col + dc[d];
      if (new_row < 0 || new_row >= islands.size() || new_col < 0 || new_col >= 2 * k - 1) continue;
      int new_index = islands[new_row][new_col];
      if (new_index != -1) {
        auto u = Node{new_row, new_col, new_index};
        if (vis.count(u)) continue;
        q.push(u);
        vis.insert(u);
        dist[u] = dist[v] + 1;
      }
    }
  }
  cout << ans.size() << endl;
  for (auto v : ans) cout << v + 1 << endl;
  return 0;
}