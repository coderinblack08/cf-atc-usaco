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
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }
  stack<int> monotonic_stack;
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (!monotonic_stack.empty() && heights[i] > heights[monotonic_stack.top()]) {
      monotonic_stack.pop();
    }
    if (monotonic_stack.empty()) {
      ans += (n - 1) - i;
    } else {
      ans += monotonic_stack.top() - i - 1;
    }
    monotonic_stack.push(i);
  }
  cout << ans << endl;
  return 0;
}