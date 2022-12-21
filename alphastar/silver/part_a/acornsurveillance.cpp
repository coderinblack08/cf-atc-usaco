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

struct Event {
  int time;
  int id;
  bool start;
};

int main() {
  int n;
  cin >> n;
  vector<Event> evs;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    evs.push_back({a, i, true});
    evs.push_back({b, i, false});
  }

  sort(evs.begin(), evs.end(), [](const Event& a, const Event& b) {
    return a.time < b.time;
  });

  int prev_ev_time = 0;
  int total_time = 0;
  set<int> active_cows;
  vector<int> un_overlapping_time(n, 0);

  for (auto ev : evs) {
    if (active_cows.size() > 0) {
      total_time += ev.time - prev_ev_time;
    }
    if (active_cows.size() == 1) {
      un_overlapping_time[*active_cows.begin()] += ev.time - prev_ev_time;
    }
    if (ev.start) {
      active_cows.insert(ev.id);
    } else {
      active_cows.erase(ev.id);
    }
    prev_ev_time = ev.time;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, total_time - un_overlapping_time[i]);
  }
  cout << ans << endl;
  return 0;
}