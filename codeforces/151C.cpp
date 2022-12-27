#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// only retrieves first 3 primes, otherwise it's too slow
vector<ll> factor(ll n) {
  vector<ll> primes;
  if (n == 1) return primes;
  for (ll d = 1, i = 2; i * i <= n && primes.size() <= 3; i += d, d = 2) {
    while (n % i == 0) {
      primes.push_back(i);
      n /= i;
    }
  }
  if (n > 1) primes.push_back(n);
  return primes;
}

int main() {
  ll n;
  cin >> n;
  auto primes = factor(n);
  if (primes.size() <= 1) cout << "1\n0\n";
  else if (primes.size() == 2) cout << "2\n";
  // you always win if you can narrow it down to two primes
  else cout << "1\n" << primes[0] * primes[1] << "\n";
  return 0;
}
