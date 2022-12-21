#include <bits/stdc++.h>
using namespace std;

vector<int> heights;

int main() {
  int n;
  long long total = 0;
  cin >> n;
  heights.resize(n);
  for (auto &h : heights) cin >> h;

  auto run_mono_stack = [&]() {
    stack<int> stk;  // FILO
    // for (int i = 0; i != n; i++) // why does't this work - produces negative values!
    for (int i = 0; i < n; i++) {  // reverse the for loop
      while (!stk.empty() && heights[stk.top()] <= heights[i])
        stk.pop();
      // runs always basically
      if (!stk.empty()) total += i - stk.top() + 1;
      stk.push(i);
    }
  };

  run_mono_stack();
  reverse(heights.begin(), heights.end());
  run_mono_stack();
  cout << total << endl;
}