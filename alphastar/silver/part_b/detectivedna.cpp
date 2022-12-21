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

int n;
vector<string> dna;
string adj_matrix[7][7];
set<int> vis;

string merge(string a, string b) {
  auto merge_fn = [](string a, string b) {
    int k;
    for (k = 0; k < n; k++) {
      if (a[n - k - 1] != b[k]) {
        break;
      }
    }
    return a.substr(0, n - k) + b;
  };
  // string s1 = merge_fn(a, b);
  // string s2 = merge_fn(b, a);
  // return s1.size() < s2.size() ? s1 : s2;
  return merge_fn(a, b);
}

// string dfs(int node, string total) {
//   cout << node << endl;
//   if (vis.size() == n) {
//     return total;
//   }
//   string ans = "";
//   for (int i = 0; i < n; i++) {
//     if (i != node && !vis.count(i)) {
//       vis.insert(i);
//       string result = dfs(i, merge(total, dna[i]));
//       vis.erase(i);
//       if (ans.size() == 0 || result.size() < ans.size()) {
//         ans = result;
//       }
//     }
//   }
//   return ans;
// }

int main() {
  cin >> n;
  dna.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> dna[i];
  }
  // for (int i = 0; i < n; i++) {
  //   vis.clear();
  //   cout << dfs(i, dna[i]) << endl
  //        << endl;
  // }
  vector<int> pos(n);
  iota(all(pos), 0);
  string ans = "";
  do {
    string abomination = "";
    auto merge_fn = [](string a, string b) {
      int end = 0;
      for (int k = 1; k <= min(a.size(), b.size()); k++) {
        if (a.substr(a.size() - k, k) == b.substr(0, k)) {
          end = k;
        }
      }
      return a.substr(0, a.size() - end) + b;
    };
    for (int i = 0; i < n; i++) {
      abomination = merge_fn(abomination, dna[pos[i]]);
    }
    if (!ans.size() || abomination.size() < ans.size()) {
      ans = abomination;
    }
  } while (next_permutation(all(pos)));
  cout << ans.size() << endl;
  return 0;
}