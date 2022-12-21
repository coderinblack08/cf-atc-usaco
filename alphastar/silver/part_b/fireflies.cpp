// #include <bits/stdc++.h>
// #define all(x) begin(x), end(x)
// #define ll long long
// using namespace std;

// void setIO(string s = "") {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   if ((int)s.size()) {
//     freopen((s + ".in").c_str(), "r", stdin);
//     freopen((s + ".out").c_str(), "w", stdout);
//   }
// }

// int n, c;

// void swap(bool a[], bool b[]) {
//   int i, temp;
//   for (i = 0; i < n; i++) {
//     swap(a[i], b[i]);
//   }
// }

// int main() {
//   cin >> n >> c;
//   vector<int> on(n), off(n);
//   vector<bool> state(n);
//   bool result[n][n];
//   for (int i = 0;; i++) {
//     cin >> on[i];
//     if (on[i] == -1) break;
//   }
//   for (int i = 0;; i++) {
//     cin >> off[i];
//     if (off[i] == -1) break;
//   }
//   int count = 0;
//   for (int a = 0; a <= 1; a++) {
//     for (int b = 0; b <= 1; b++) {
//       for (int c = 0; c <= 1; c++) {
//         for (int d = 0; d <= 1; d++) {
//           auto op1 = [&]() {
//             for (int i = 0; i < n; i++) {
//               state[i] = !state[i];
//             }
//           };
//           auto op2 = [&]() {
//             for (int i = 0; i < n; i += 2) {
//               state[i] = !state[i];
//             }
//           };
//           auto op3 = [&]() {
//             for (int i = 1; i < n; i += 2) {
//               if (i % 2 == 0) {
//                 state[i] = !state[i];
//               }
//             }
//           };
//           auto op4 = [&]() {
//             for (int i = 0; i < n; i += 3) {
//               state[i] = !state[i];
//             }
//           };
//           fill(state.begin(), state.end(), true);
//           for (int i = 0; i < a; i++) op1();
//           for (int i = 0; i < b; i++) op2();
//           for (int i = 0; i < c; i++) op3();
//           for (int i = 0; i < d; i++) op4();
//           bool works = true;
//           if (a + b + c + d > c || (c - a + b + c + d) % 2 == 1) works = false;
//           for (int i = 0; on[i] != -1; i++)
//             if (state[on[i] - 1] == 0) works = false;
//           for (int i = 0; off[i] != -1; i++)
//             if (state[off[i] - 1] == 1) works = false;
//           if (works) {
//             for (int i = 0; i < n; i++) result[count][i] = state[i];
//             count++;
//           }
//         }
//       }
//     }
//   }
//   if (count == 0) {
//     cout << "IMPOSSIBLE" << endl;
//   } else {
//     for (int i = 0; i < count - 1; i++) {
//       for (int j = i + 1; j < count; j++) {
//         if (equal(result[i], result[i] + n, result[j])) {
//           swap(result[i], result[j]);
//         }
//       }
//     }
//     for (int i = 0; i < count; i++) {
//       for (int j = 0; j < n; j++) {
//         cout << result[i][j];
//       }
//       cout << endl;
//     }
//   }
//   return 0;
// }
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

int n, C;
vector<int> on, off;
set<vector<int>> ans;

bool check(vector<int> fireflies) {
  for (int x : on) {
    if (fireflies[x] == 0) return false;
  }
  for (int x : off) {
    if (fireflies[x] == 1) return false;
  }
  return true;
}

vector<int> op_1(vector<int> a) {
  for (int i = 1; i <= n; i++) a[i] = 1 - a[i];
  return a;
}
vector<int> op_2(vector<int> a) {
  for (int i = 1; i <= n; i += 2) a[i] = 1 - a[i];
  return a;
}
vector<int> op_3(vector<int> a) {
  for (int i = 2; i <= n; i += 2) a[i] = 1 - a[i];
  return a;
}
vector<int> op_4(vector<int> a) {
  for (int i = 1; i <= n; i += 3) a[i] = 1 - a[i];
  return a;
}

void dfs(vector<int> fireflies, int count, bool a, bool b, bool c, bool d) {
  if (count > C) return;
  if ((C - count) % 2 == 0) {
    if (check(fireflies)) {
      ans.insert(fireflies);
    }
  }
  if (!a) dfs(op_1(fireflies), count + 1, true, b, c, d);
  if (!b) dfs(op_2(fireflies), count + 1, a, true, c, d);
  if (!c) dfs(op_3(fireflies), count + 1, a, b, true, d);
  if (!d) dfs(op_4(fireflies), count + 1, a, b, c, true);
}

int main() {
  cin >> n >> C;
  int t;
  cin >> t;
  while (t != -1) {
    on.push_back(t);
    cin >> t;
  }
  cin >> t;
  while (t != -1) {
    off.push_back(t);
    cin >> t;
  }
  vector<int> fireflies(n + 1, 1);
  dfs(fireflies, 0, false, false, false, false);
  if (ans.size() == 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (auto x : ans) {
      for (int i = 1; i <= n; i++) cout << x[i];
      cout << endl;
    }
  }
  return 0;
};