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
  string s, e;
  cin >> s >> e;
  set<string> dict;
  string line;
  while (std::getline(std::cin, line)) {
    dict.insert(line);
  }
  set<string> vis;
  queue<string> q;
  map<string, int> d;
  q.push(s);
  d[s] = 0;
  vis.insert(s);
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (v == e) {
      cout << d[v];
      break;
    }
    for (int i = 0; i < v.size(); i++) {
      for (char c = 'a'; c <= 'z'; c++) {
        string t = v;
        t[i] = c;
        if (dict.count(t) && !vis.count(t)) {
          d[t] = d[v] + 1;
          vis.insert(t);
          q.push(t);
        }
      }
    }
  }
  return 0;
}