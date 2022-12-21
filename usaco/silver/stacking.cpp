#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int n, k;

// O(n * K) too slow
// O(n + k) just enough to pass
// ^ prefix sums

int main() {
  cin >> n >> k;
  int A[n + 1];
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    A[a]++;
    A[b + 1]--;
  }
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    if (i > 0) A[i] += A[i - 1];
    nums.push_back(A[i]);
  }
  sort(nums.begin(), nums.end());
  cout << nums[n / 2] << endl;
  return 0;
}