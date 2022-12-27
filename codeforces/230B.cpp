#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int max_a = 1e6 + 5;
set<double> primes;

void sieve_of_eratosthenes() {
  vector<bool> is_prime(max_a + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= max_a; i++) {
    if (is_prime[i]) {
      primes.insert((double)i);
      for (int j = i + i; j <= max_a; j += i)
        is_prime[j] = false;
    }
  }
}

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }

int main() {
  int n;
  cin >> n;
  sieve_of_eratosthenes();
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if (primes.count(sqrt(a)))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
