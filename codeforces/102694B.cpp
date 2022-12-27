#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dist;
vector<bool> diameter_endpoint;
vector<vector<int>> adj;

void bfs(int from) {
  for (int i = 1; i <= n; i++) {
    dist[i] = -1;
  }
  queue<int> q;
  q.push(from);
  dist[from] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &c: adj[u]) {
      if (dist[c] == -1) {
        dist[c] = dist[u] + 1;
        q.push(c);
      }
    }
  }
}

int farthest() {
  int best = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[best]) {
      best = i;
    }
  }
  return best;
}

int main() {
  cin >> n;
  dist.resize(n + 1, 0);
  adj.resize(n + 1, vector<int>());
  diameter_endpoint.resize(n + 1, false);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfs(1);
  int f = farthest();
  bfs(f);
  f = farthest();

  int d = dist[f];
  for (int i = 1; i <= n; i++) {
    if (dist[i] == d || dist[i] == -1) {
      diameter_endpoint[i] = true;
    }
  }

  bfs(f);
  for (int i = 1; i <= n; i++) {
    if (dist[i] == d || dist[i] == -1) {
      diameter_endpoint[i] = true;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (diameter_endpoint[i]) {
      cout << d + 1;
    } else {
      cout << d;
    }
    cout << endl;
  }

  return 0;
}

