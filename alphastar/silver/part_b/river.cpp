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

int adj_matrix['z' + 1]['z' + 1];
map<char, vector<char>> adj_list_1, adj_list_2;

int main() {
  int n;  // ≤ 700
  cin >> n;
  for (int i = 0; i < n; i++) {
    char a, b;
    int f;
    cin >> a >> b >> f;
    if (a > b) swap(a, b);
    adj_matrix[a][b] += f;
    // adj_list_1[a].push_back(b);
    // adj_list_2[b].push_back(a);
  }
  // for (auto &p : adj_list_1) {
  //   if (p.first != 'A' && p.first != 'Z') {
  //     if (p.second.size() == 0) {
  //       for (auto &u : adj_list_2[p.first]) {
  //         adj_matrix[u][p.first] = 0;
  //         adj_list_1.erase(p.first);
  //         adj_list_1[u].erase(find(all(adj_list_1[u]), p.first));
  //       }
  //     }
  //   }
  // }
  // for (auto &p : adj_list_1) {
  //   if (p.first != 'A' && p.first != 'Z' && p.second.size() == 1 && adj_list_2[p.first].size() == 1) {
  //     char next = p.second[0];
  //     char prev = adj_list_2[p.first][0];
  //     char curr = p.first;
  //     adj_matrix[prev][next] += min(adj_matrix[prev][curr], adj_matrix[curr][next]);
  //     adj_matrix[prev][curr] = adj_matrix[curr][next] = 0;
  //     adj_list_1.erase(curr);
  //     // cerr << prev << " " << curr << " " << next << ": " << adj_list_1[prev].size() << endl;
  //     adj_list_1[prev].erase(find(all(adj_list_1[prev]), curr));
  //     adj_list_1[prev].push_back(next);
  //     adj_list_2[next].erase(find(all(adj_list_2[next]), curr));
  //   }
  // }
  // int ans = 1e9;
  // queue<char> q;
  // q.push('A');
  // while (!q.empty()) {
  //   char v = q.front();
  //   q.pop();
  //   if (v == 'Z') break;
  //   for (char u : adj_list_1[v]) {
  //     ans = min(ans, adj_matrix[v][u]);
  //     q.push(u);
  //   }
  // }
  // cout << ans;
  return 0;
}