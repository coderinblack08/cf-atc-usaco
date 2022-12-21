#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int N;

int get_next(int s) {
  return s ^ (s >> 1) ^ (s & 1 ? 1 << N - 1 : 0);
}

int main() {
  long long B;
  cin >> N >> B;

  int s = 0;
  for (int i = N - 1; i >= 0; i--) {
    int v;
    cin >> v;
    if (v) s |= 1 << i;
  }

  int s0 = s;
  int s1 = s;
  for (; B > 0; B--) {
    s0 = get_next(s0);
    s1 = get_next(get_next(s1));
    if (s0 == s1) {
      B--;
      break;
    }
  }
  if (B) {
    int rho = 1;
    for (s0 = get_next(s0); s0 != s1; rho++) {
      s0 = get_next(s0);
    }
    B %= rho;
  }
  for (; B > 0; B--) {
    s0 = get_next(s0);
  }
  for (int i = N - 1; i >= 0; i--) {
    cout << (s0 & 1 << i ? 1 : 0) << endl;
  }
  return 0;
}