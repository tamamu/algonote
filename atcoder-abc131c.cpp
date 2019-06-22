#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return (a*b)/gcd(a, b);
}

int main() {
  ll A; cin >> A;
  ll B; cin >> B;
  ll C; cin >> C;
  ll D; cin >> D;
  ll CD = lcm(C, D);
  ll AC = (A-1)/C;
  ll AD = (A-1)/D;
  ll ACD = (A-1)/CD;
  ll BC = B/C;
  ll BD = B/D;
  ll BCD = B/CD;
  cout << (B-BC-BD+BCD) - (A-AC-AD+ACD) + 1 << endl;
  return 0;
}
