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
  string n;
  cin >> n;
  vector<string> valid_ids;
  vector<string> names;
  map<char, int> id_map = {
      {'A', 2},
      {'B', 2},
      {'C', 2},
      {'D', 3},
      {'E', 3},
      {'F', 3},
      {'G', 4},
      {'H', 4},
      {'I', 4},
      {'J', 5},
      {'K', 5},
      {'L', 5},
      {'M', 6},
      {'N', 6},
      {'O', 6},
      {'P', 7},
      {'R', 7},
      {'S', 7},
      {'T', 8},
      {'U', 8},
      {'V', 8},
      {'W', 9},
      {'X', 9},
      {'Y', 9},
  };
  string a;
  while (getline(cin, a)) {
    // cerr << a << endl;
    names.push_back(a);
    string id = "";
    for (int i = 0; i < a.size(); i++) {
      id += '0' + id_map[a[i]];
    }
    valid_ids.push_back(id);
  }
  int count = 0;
  for (int i = 0; i < valid_ids.size(); i++) {
    if (valid_ids[i] == n) {
      cout << names[i] << endl;
      count++;
    }
  }
  if (count == 0) cout << "NONE" << endl;
  return 0;
}