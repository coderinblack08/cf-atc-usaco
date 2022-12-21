#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int largest_ss_length = 0;
    for (int i = 0; i < a.length(); i++) {
      for (int j = i; j < a.length(); j++) {
        if (b.find(a.substr(i, j - i + 1)) != string::npos) {
          largest_ss_length = max(largest_ss_length, j - i + 1);
        }
      }
    }
    cout << a.length() + b.length() - 2 * largest_ss_length << endl;
  }
}