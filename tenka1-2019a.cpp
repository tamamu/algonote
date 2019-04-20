#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll A; cin >> A;
  ll B; cin >> B;
  ll C; cin >> C;
  if ((A <= C && C <= B) || (B <= C && C <= A)) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
  return 0;
}
