#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  ll M; cin >> M;
  vector<ll> A(N);
  for (ll j=0; j < N; ++j) cin >> A[j];
  vector<tuple<ll, ll> > BC(M);
  for (ll j=0; j < M; ++j) {
    ll B, C; cin >> B >> C;
    BC[j] = make_tuple(B, C);
  }

  sort(BC.begin(), BC.end(), [](auto x, auto y){
      ll Bx, Cx; tie(Bx, Cx) = x;
      ll By, Cy; tie(By, Cy) = y;
      return Cx > Cy;
      });

  ll rem = N;
  for (ll j=0; j < M && rem > 0; ++j) {
    ll B, C; tie(B, C) = BC[j];
    for (ll k=0; k < B && rem > 0; ++k) {
      rem -= 1;
      A.push_back(C);
    }
  }
  sort(A.rbegin(), A.rend());
  ll ans = 0;
  for (ll j=0; j < N; ++j) ans += A[j];
  cout << ans << endl;
  return 0;
}
