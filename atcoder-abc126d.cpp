#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct TreeNode {
    int val;
    vector<tuple<ll, ll> > conn;
    TreeNode(int x) {
      val = x;
    }
};

int main() {
  ll N; cin >> N;
  vector<TreeNode> nodes;
  for (ll j=0; j < N; ++j) {
    nodes.push_back(TreeNode(0));
  }
  vector<bool> opened(N);
  for (ll j=0; j < N-1; ++j) {
    ll u, v, w; cin >> u >> v >> w;
    nodes[u-1].conn.push_back(make_tuple(w, v-1));
    nodes[v-1].conn.push_back(make_tuple(w, u-1));
  }
  queue<tuple<TreeNode*, ll>> q;
  q.push(make_tuple(&nodes[0], 0)); opened[0] = true;
  while (!q.empty()) {
    TreeNode* node; ll d;
    tie(node, d) = q.front(); q.pop();
    for (tuple<ll, ll> iter : node->conn) {
      ll dist, next; tie(dist, next) = iter;
      if (!opened[next]) {
        opened[next] = true;
        ll dd = d + dist;
        nodes[next].val = dd % 2 == 0 ? 0 : 1;
        q.push(make_tuple(&nodes[next], dd));
      }
    }
  }
  for (ll j=0; j < N; ++j) {
    cout << nodes[j].val << endl;
  }
  return 0;
}
