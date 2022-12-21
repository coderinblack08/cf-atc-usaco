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

struct Rect {
  int leftX, rightX, topY, bottomY;
};

vector<Rect> v;

int y_sweep_line(const set<int>& contained) {
  if (contained.size() == 0) return 0;
  vector<pair<int, int>> q;
  for (int u : contained) {
    q.push_back(make_pair(v[u].topY, 1));
    q.push_back(make_pair(v[u].bottomY, -1));
  }
  sort(all(q), [&](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  });
  int prev = q[0].first, count = 0, total = 0;
  for (int i = 0; i < q.size(); i++) {
    if (count > 0) {
      total += (prev - q[i].first);
    }
    count += q[i].second;
    prev = q[i].first;
  }
  return total;
}

int main() {
  int n;
  cin >> n;
  // assert(n <= 10);
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].leftX >> v[i].topY >> v[i].rightX >> v[i].bottomY;
  }
  sort(all(v), [](const Rect& a, const Rect& b) { return a.leftX < b.leftX; });
  vector<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    q.push_back(make_pair(i, 1));
    q.push_back(make_pair(i, -1));
  }
  sort(all(q), [&](const pair<int, int>& a, const pair<int, int>& b) {
    int A = a.second == -1 ? v[a.first].rightX : v[a.first].leftX;
    int B = b.second == -1 ? v[b.first].rightX : v[b.first].leftX;
    return A < B;
  });
  set<int> contained;
  ll total_area = 0;
  for (int i = 0; i < q.size(); i++) {
    auto p = q[i];
    if (p.second == -1) {
      contained.erase(p.first);
    } else {
      contained.insert(p.first);
    }
    int dist = 0;
    int pos = p.second == -1 ? v[p.first].rightX : v[p.first].leftX;
    int next = q[i + 1].second == -1 ? v[q[i + 1].first].rightX : v[q[i + 1].first].leftX;
    if (i != q.size() - 1) dist = next - pos;
    int height = y_sweep_line(contained);
    // cerr << height << " " << dist << " " << contained.size() << endl;
    total_area += height * dist;
  }
  cout << total_area << endl;
  return 0;
}