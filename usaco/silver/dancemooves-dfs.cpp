#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX_N = 1e5 + 1, MAX_K = 2e5 + 1;
int n, k;
int init_pos[MAX_N], curr_pos[MAX_N], cycles[MAX_N];
pair<int, int> swaps[MAX_K];

bool vis[MAX_N];
set<int> sets[MAX_N];

queue<int> q;
int unique_pos = 0, cnt[MAX_N], ans[MAX_N];

void add(int node) {
  for (int x : sets[node]) {
    if (cnt[x] == 0) {
      unique_pos++;
    }
    cnt[x]++;
  }
}

void remove(int node) {
  for (int x : sets[node]) {
    if (cnt[x] == 1) {
      unique_pos--;
    }
    cnt[x]--;
  }
}

void dfs(int x) {
  if (vis[x]) return;
  vis[x] = true;
  add(x);
  q.push(x);
  dfs(cycles[x]);
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    init_pos[i] = i;
    curr_pos[i] = i;
    sets[i].insert(i);
  }
  for (int i = 0; i < k; i++) {
    cin >> swaps[i].first >> swaps[i].second;
  }
  for (int i = 0; i < k; i++) {
    // putting before works but not after swap??
    sets[curr_pos[swaps[i].first]].insert(swaps[i].second);
    sets[curr_pos[swaps[i].second]].insert(swaps[i].first);
    swap(curr_pos[swaps[i].first], curr_pos[swaps[i].second]);
  }
  for (int i = 1; i <= n; i++) {
    cycles[curr_pos[i]] = i;
  }
  // vector<int> qs[n + 1];
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      int temp_ans = unique_pos;
      while (!q.empty()) {
        remove(q.front());
        ans[q.front()] = temp_ans;
        q.pop();
      }
    }
    // vector<int> q = {};
    // if (qs[i].size() == 0) {
    //   dfs(i, q);
    //   for (int j = 0; j < q.size(); j++) {
    //     qs[q[j]] = q;
    //   }
    // } else {
    //   q = qs[i];
    // }
    // set<int> s;
    // for (int j = 0; j < q.size(); j++) {
    //   s.insert(sets[q[j]].begin(), sets[q[j]].end());
    // }
    // cout << s.size() << endl;
    // fill(vis, vis + MAX_N, false);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  // for (int i = 1; i <= n; i++) {
  //   for (auto j : sets[i]) {
  //     if (j)
  //       cout << j << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}