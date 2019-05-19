#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  ll K; cin >> K;
  double ans = 0.0;
  for (ll j=0; j < N; ++j) {
    double q = 0;
    ll now = j+1;
    while (now < K) {
      now *= 2;
      q += 1;
    }
    ans += (1.0/N) * pow(0.5, q);
  }
  printf("%.10lf\n", ans);
  return 0;
}
