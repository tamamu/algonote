#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll P; cin >> P;
  ll Q; cin >> Q;
  ll R; cin >> R;
  cout << min(P+Q, min(Q+R, R+P)) << endl;
  return 0;
}
