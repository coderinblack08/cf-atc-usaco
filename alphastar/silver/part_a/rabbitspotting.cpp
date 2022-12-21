#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define ll long long
using namespace std;

void setIO(std::string s = "") {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
};

int main() {
  // setIO("learning");
  int n, a, b;
  cin >> n >> a >> b;
  vector<pair<int, string>> cows(n);
  for (int i = 0; i < n; i++) cin >> cows[i].second >> cows[i].first;
  cows.push_back({INT_MIN, "NS"});
  cows.push_back({INT_MAX, "NS"});
  sort(all(cows));
  int area_covered = 0;
  for (int i = 0; i < cows.size() - 1; i++) {
    int start = cows[i].first;
    int end = cows[i + 1].first;
    int mid = (start + end) / 2;

    if (cows[i].second == "S") {
      int s = max(a, start + 1);
      int e = min(b, mid);
      if (e >= s) {
        area_covered += e - s + 1;
      }
    }

    if (cows[i + 1].second == "S") {
      int s = max(a, mid + 1);
      int e = min(b, end);
      if (e >= s) {
        area_covered += e - s + 1;
      }
    }

    if (cows[i].second == "NS" && cows[i + 1].second == "S" && (start % 2) == (end % 2) && a <= mid && mid <= b) {
      // (start % 2) == (end % 2) means that (start - end) % 2 == 0, meaning there is a distinct middle cow
      area_covered++;
    }
  }
  cout << area_covered;
  return 0;
}