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

int n, k;
vector<int> A;

bool check(int mid) {
  int start = A[0];
  int group_count = 1;
  for (int i = 0; i < n; i++) {
    if (A[i] - start > 2 * mid) {
      group_count++;
      start = A[i];
    }
  }
  return group_count <= k;
}

int main() {
  cin >> n >> k;
  A.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(all(A));
  int low = 1, high = 1e9;
  while (low < high - 1) {
    int mid = (low + high) / 2;  // checking for if R = mid, if it works
    if (check(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  if (check(low)) {
    cout << low << endl;
  } else {
    cout << high << endl;
  }
  return 0;
}