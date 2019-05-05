#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Point {
  ll x;
  ll y;
};

int main() {
  ll H; cin >> H;
  ll W; cin >> W;
  vector<string> A(H);
  for (ll j=0; j < H; ++j) cin >> A[j];
  queue<Point> openq;
  queue<Point> procq;
  for (ll j=0; j < H; ++j) {
    for (ll k=0; k < W; ++k) {
      if (A[j][k] == '#') openq.push(Point{k, j});
    }
  }
  ll ans = 0;
  while (!openq.empty()) {
    procq = move(openq);
    while (!procq.empty()) {
      Point p = procq.front(); procq.pop();
      if (p.x-1 >= 0 && A[p.y][p.x-1] == '.') {
        A[p.y][p.x-1] = '#';
        openq.push(Point{p.x-1, p.y});
      }
      if (p.x+1 < W && A[p.y][p.x+1] == '.') {
        A[p.y][p.x+1] = '#';
        openq.push(Point{p.x+1, p.y});
      }
      if (p.y-1 >= 0 && A[p.y-1][p.x] == '.') {
        A[p.y-1][p.x] = '#';
        openq.push(Point{p.x, p.y-1});
      }
      if (p.y+1 < H && A[p.y+1][p.x] == '.') {
        A[p.y+1][p.x] = '#';
        openq.push(Point{p.x, p.y+1});
      }
    }
    ans += 1;
  }
  cout << ans-1 << endl;
  return 0;
}
