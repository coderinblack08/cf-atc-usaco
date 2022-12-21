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

string reverse(string s) {
  string r;
  for (int i = s.size() - 1; i >= 0; i--) {
    r += s[i];
  }
  return r;
}

bool is_palindrome(string s) {
  return s == reverse(s);
}

int main() {
  setIO("scramble");
  int n;
  cin >> n;
  vector<string> names(n);
  vector<string> order(n);
  for (int i = 0; i < n; i++) {
    cin >> names[i];
    sort(begin(names[i]), end(names[i]), greater<char>());
    order[i] = names[i];
  }
  sort(begin(names), end(names));
  map<string, pair<int, int>> mp;
  // all names are reversed
  for (int i = 0; i < n; i++) {
    string curr = names[i];
    mp[curr].first = lower_bound(begin(names), end(names), reverse(curr)) - begin(names) + 1;
  }
  for (int i = 0; i < n; i++) {
    names[i] = reverse(names[i]);
  }
  sort(begin(names), end(names));
  // all names are alphabetical
  for (int i = 0; i < n; i++) {
    string curr = names[i];
    // if the word isn't a palindrome, we know the original word would be in front and count towards the one-indexing
    // since we're using lower_bound, inserting palindromes wouldn't be the same
    mp[reverse(curr)].second = lower_bound(begin(names), end(names), reverse(curr)) - begin(names) + is_palindrome(curr);
  }
  // output based on the original order
  for (int i = 0; i < n; i++) {
    cout << mp[order[i]].first << " " << mp[order[i]].second << endl;
  }
  return 0;
}