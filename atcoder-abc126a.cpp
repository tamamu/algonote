#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  ll K; cin >> K;
  string S; cin >> S;
  S[K-1] += 32;
  cout << S << endl;
  return 0;
}
