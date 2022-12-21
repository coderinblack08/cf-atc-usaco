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

int n, s, e;
set<string> total;

vector<string> split(string s, char c = ' ') {
  vector<string> res;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    res.push_back(x);
  return res;
}

string vector_to_string(vector<int> v) {
  string res = "";
  for (int i : v) res += to_string(i);
  return res;
}

void check_permutations(map<int, int> &requirements, vector<int> rolls) {
  if (rolls.size() == n) {
    bool works = true;
    for (auto [_, v] : requirements) {
      if (v > 0) works = false;
    }
    if (works) total.insert(vector_to_string(rolls));
    return;
  }
  for (int i = 1; i <= s; i++) {
    rolls.push_back(i);
    if (requirements.count(i)) requirements[i]--;
    check_permutations(requirements, rolls);
    if (requirements.count(i)) requirements[i]++;
    rolls.pop_back();
  }
}

int main() {
  cin >> n >> s >> e;
  for (int i = 0; i < e; i++) {
    string s;
    cin >> s;
    auto fragments = split(s, '+');
    map<int, int> requirements;
    for (string u : fragments) {
      auto cr = split(u, 'x');
      requirements[atoi(cr[1].c_str())] = atoi(cr[0].c_str());
    }
    check_permutations(requirements, {});
  }
  cout << total.size() << endl;
  return 0;
}