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

struct Cow {
  int arrival, time_spent, seniority;
};

int main() {
  int n;
  cin >> n;
  vector<Cow> cows;
  for (int i = 0; i < n; i++) {
    int a, t;
    cin >> a >> t;
    cows.push_back({a, t, i});
  }
  sort(cows.begin(), cows.end(), [](const Cow &a, const Cow &b) {
    return a.arrival < b.arrival;
  });
  set<pair<int, int>> waiting;
  int ans = 0, next_cow = 1;
  int time_after_finishing_grazing = cows[0].arrival + cows[0].time_spent;
  while (next_cow < n || !waiting.empty()) {
    // if there is a cow grazing already, join the waiting queue
    while (next_cow < n && cows[next_cow].arrival <= time_after_finishing_grazing) {
      waiting.insert({cows[next_cow].seniority, next_cow});
      next_cow++;
    }
    // take most senior cow from waiting queue
    if (waiting.size() > 0) {
      ans = max(ans, time_after_finishing_grazing - cows[waiting.begin()->second].arrival);
      time_after_finishing_grazing += cows[waiting.begin()->second].time_spent;
      waiting.erase(waiting.begin());
    }
    // no cows are waiting, so move onto next cow that arrives
    if (waiting.size() == 0 && next_cow < n) {
      time_after_finishing_grazing = cows[next_cow].arrival + cows[next_cow].time_spent;
      next_cow++;
    }
  }
  cout << ans;
  return 0;
}