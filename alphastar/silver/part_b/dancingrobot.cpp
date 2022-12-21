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
  // tracking the size of the stage
  int left, right, top, bottom;
  vector<pair<int, int>> dog = {
      make_pair(0, 0),  // RR
      make_pair(0, 1),  // RL
      make_pair(1, 0),  // FR
      make_pair(1, 1),  // FL
  };
  left = 0, right = 1, top = 1, bottom = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    pair<int, int>* curr;
    string foot = s.substr(0, 2);
    if (foot == "RR") {
      curr = &dog[0];
    }
    if (foot == "RL") {
      curr = &dog[1];
    }
    if (foot == "FR") {
      curr = &dog[2];
    }
    if (foot == "FL") {
      curr = &dog[2];
    }
    char instruction = s[2];
    if (instruction == 'F') {
      curr->first += 1;
      right = max(right, curr->first);
    }
    if (instruction == 'B') {
      curr->first -= 1;
      left = min(left, curr->first);
    }
    if (instruction == 'R') {
      curr->second -= 1;
      bottom = min(bottom, curr->second);
    }
    if (instruction == 'L') {
      curr->second += 1;
      top = max(top, curr->second);
    }
    if (instruction == 'P') {
      for (int i = 0; i < 4; i++) {
        if (dog[i] == *curr) continue;
        int x = dog[i].first, y = dog[i].second;
        dog[i].first = curr->first + (y - curr->second);
        dog[i].second = curr->second + (curr->first - x);
        right = max(right, dog[i].first);
        left = min(left, dog[i].first);
        top = max(top, dog[i].second);
        bottom = min(bottom, dog[i].second);
      }
    }
  }
  cout << (right - left + 1) * (top - bottom + 1) << endl;
  return 0;
}