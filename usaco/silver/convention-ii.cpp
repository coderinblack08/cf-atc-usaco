#include <bits/stdc++.h>
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
  int c, start, duration;
  bool operator<(const Cow& other) const {
    return c < other.c;
  }
};

int main() {
  setIO("convention2");
  int n;
  cin >> n;
  vector<Cow> cows;
  for (int c = 0; c < n; c++) {
    int start, duration;
    cin >> start >> duration;
    cows.push_back({c, start, duration});
  }

  sort(cows.begin(), cows.end(), [](Cow a, Cow b) {
    return a.start < b.start;
  });

  int time = 0;
  int curr = 0;
  int longest_wait = 0;
  set<Cow> wait;
  while (curr < n || !wait.empty()) {
    if (curr < n && cows[curr].start <= time) {
      // put in wait
      wait.insert(cows[curr]);
      curr++;
    } else if (wait.empty()) {
      // none in wait
      time = cows[curr].start + cows[curr].duration;
      curr++;
    } else {
      // process next in line
      auto next = *wait.begin();
      longest_wait = max(longest_wait, time - next.start);
      time += next.duration;
      wait.erase(wait.begin());
    }
  }

  cout << longest_wait << endl;
}
