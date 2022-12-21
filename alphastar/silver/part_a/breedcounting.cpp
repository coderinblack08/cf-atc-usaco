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
  int n, q;
  cin >> n >> q;
  vector<int> holsteins(n + 1), guernseys(n + 1), jerseys(n + 1);
  for (int i = 0; i < n; i++) {
    int breed_id;
    cin >> breed_id;
    if (breed_id == 1) {
      holsteins[i + 1] = 1;
    } else if (breed_id == 2) {
      guernseys[i + 1] = 1;
    } else {
      jerseys[i + 1] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    holsteins[i + 1] += holsteins[i];
    guernseys[i + 1] += guernseys[i];
    jerseys[i + 1] += jerseys[i];
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << holsteins[b] - holsteins[a - 1] << " " << guernseys[b] - guernseys[a - 1] << " " << jerseys[b] - jerseys[a - 1] << endl;
  }
  return 0;
}