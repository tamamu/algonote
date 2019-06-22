#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  vector<tuple<ll, ll> > AB(N);
  for (ll j=0; j < N; ++j) {
    ll A, B; cin >> A >> B;
    AB[j] = make_tuple(A, B);
  }
  sort(AB.begin(), AB.end(), [](auto l, auto r){
        return get<1>(l) < get<1>(r);
      });
  ll t = 0;
  bool flag = true;
  for (ll j=0; j < N; ++j) {
    ll a, b; tie(a, b) = AB[j];
    t += a;
    if (t > b) {
      flag = false;
      break;
    }
  }
  cout << (flag?"Yes":"No") << endl;
  return 0;
}
