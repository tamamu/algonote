#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(ll x, string N) {
  string A = N, B = "";
  for (unsigned long long j=0; j < N.length(); ++j) {
    B.push_back('0');
  }
  // A = 234, B = 000
  for (unsigned long long j=0; j < N.length(); ++j) {
    if (A[j] == '4') {
      A[j] = '3'; B[j] = '1';
    }
  }
  cout << "Case #" << x << ": " << stoll(A, nullptr, 10) << " " << stoll(B, nullptr, 10) << endl;
}

int main() {
  ll T; cin >> T;
  vector<string> N(T);
  for (ll j=0; j < T; ++j) cin >> N[j];
  for (ll j=0; j < T; ++j) solve(j+1, N[j]);
  return 0;
}
