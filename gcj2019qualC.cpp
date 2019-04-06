#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(ll x) {
  ll N, L; cin >> N >> L;
  vector<ll> A(L);
  string y="";
  for (ll j=0; j < L; ++j) cin >> A[j];
  string str;
  ll a1, a2, b1, b2;
  for (ll j=2; j < A[0]; ++j) {
    if (A[0] % j == 0) {
      a1 = j;
      a2 = A[0] / j;
      break;
    }
  }
  for (ll j=2; j < A[1]; ++j) {
    if (A[1] % j == 0) {
      b1 = j;
      b2 = A[1] / j;
      break;
    }
  }
  if (a1 == b1 || a1 == b2) {
    swap(a1, a2);
  }
  vector<ll> seq, primes;
  seq.push_back(a1); primes.push_back(a1);
  ll prev = a1;
  for (ll j=0; j < L; ++j) {
    prev = A[j] / prev;
    seq.push_back(prev);
    primes.push_back(prev);
  }
  seq.push_back(prev); primes.push_back(prev);
  sort(primes.begin(), primes.end());
  primes.erase(unique(primes.begin(), primes.end()), primes.end());
  for (ll j=0; j < L+1; ++j) {
    for (ll k=0; k < primes.size(); ++k) {
      if (primes[k] == seq[j]) {
        y.push_back('A'+k);
        break;
      }
    }
  }
  cout << "Case #" << x << ": " << y << endl;
}

int main() {
  ll T; cin >> T;
  for (ll j=0; j < T; ++j) solve(j+1);

  return 0;
}
