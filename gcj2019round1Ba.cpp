#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct RPS {
  int r;
  int p;
  int s;
};

void solve(ll x) {
  ll A; cin >> A;
  vector<string> C(A);
  vector<bool> win(A); ll win_count = A;
  for (ll j=0; j < A; ++j) {
    cin >> C[j];
  }
  string y = "";
  ll turn = 0;
  ll hand_count[] = {0, 0, 0};
  while (win_count > 0 && turn < 500) {
    hand_count[0] = 0; hand_count[1] = 0; hand_count[2] = 0;
    bool r=true, p=true, s=true;
    for (ll j=0; j < A; ++j) {
      if (win[j]) continue;
      switch (C[j][turn % C[j].length()]) {
        case 'R': s = false; hand_count[0]+=1; break;
        case 'P': r = false; hand_count[1]+=1; break;
        case 'S': p = false; hand_count[2]+=1; break;
      }
    }
    if (!(r || p || s)) {
      break;
    }
    char hand = 'X';
    if (r == true && p == false && s == false) {
      hand = 'R';
    } else if (r == false && p == true && s == false) {
      hand = 'P';
    } else if (r == false && p == false && s == true) {
      hand = 'S';
    } else {
      if (p && hand_count[0] > 0) {
        hand = 'P';
      } else if (s && hand_count[1] > 0) {
        hand = 'S';
      } else if (r && hand_count[2] > 0) {
        hand = 'R';
      }
    }
    for (ll j=0; j < A; ++j) {
      if (win[j]) continue;
      switch (C[j][turn % C[j].length()]) {
        case 'R': if (hand == 'P') {win[j] = true; win_count--;} break;
        case 'P': if (hand == 'S') {win[j] = true; win_count--;} break;
        case 'S': if (hand == 'R') {win[j] = true; win_count--;} break;
      }
    }
    y.push_back(hand);
    turn++;
  }
  if (win_count <= 0)  {
    cout << "Case #" << x << ": " << y << endl;
  } else { 
    cout << "Case #" << x << ": IMPOSSIBLE" << endl;
  }
  return;
}

int main() {
  ll T; cin >> T;
  for (ll j=0; j < T; ++j) {
    solve(j+1);
  }
  return 0;
}
