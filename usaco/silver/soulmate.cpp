#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
observations:
1. Answer is always O(log(max(A, B)))
2.
  a) Never a division right after a multiplication operation
  b) Any +1 operations between a multiplication and division operation could be more efficiently moved to after the division
3.
*/

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    ll curr = x, count = 0;
    set<ll> list1;
    set<ll> list2;
    map<ll, ll> map1;
    map<ll, ll> map2;
    while (curr > 0) {
      list1.insert(curr);
      map1[curr] = count;
      if (curr % 2 == 1 && curr != 1) {
        curr++;
      } else {
        curr /= 2;
      }
      count++;
    }
    curr = y, count = 0;
    while (curr > 0) {
      list2.insert(curr);
      map2[curr] = count;
      if (curr % 2 == 1 && curr != 1) {
        curr--;
      } else {
        curr /= 2;
      }
      count++;
    }
    ll ans = 100000;
    for (auto next : list1) {
      auto it = lower_bound(begin(list2), end(list2), next);
      if (*it >= next && it != list2.end()) {
        ans = min(ans, map1[next] + map2[*it] + (*it - next));
      }
    }
    cout << ans << endl;
  }
}

/*
997 -> 120

a  | b
998
499
500
250
125
126
63    120
63    60
64    60
32    60
16    60
16    30
16    15
8     15
8     14
8     7
4     7
4     6
4     3
2     3
2     2

31 -> 13
32 13
16 13
8 13
8 12
8 6
4 6
4 3
2 3
2 2
*/
