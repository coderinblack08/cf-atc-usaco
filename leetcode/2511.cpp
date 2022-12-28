#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int captureForts(vector<int> &forts) {
    int n = forts.size();
    int ans = 0;

    auto solve = [&]() -> void {
      int curr = -1;
      for (int i = 0; i < n; i++) {
        if (forts[i] == 1) curr = 0;
        if (forts[i] == 0 && curr != -1) curr++;
        if (forts[i] == -1) {
          ans = max(ans, curr);
          curr = -1;
        }
      }
    };

    solve();
    reverse(forts.begin(), forts.end());
    solve();

    return ans;
  }
};
