#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for (auto j=0; j < H; ++j) {
        cin >> s[j];
    }
    bool canDraw = true;
    for (auto j=0; j < H; j++) {
        for (auto k=0; k < W; k++) {
            if (s[j][k] == '#') {
                if(H > 1) {
                    if (j == 0) {
                        if (s[1][k] == '#') continue;
                    } else if (j == H-1) {
                        if (s[H-2][k] == '#') continue;
                    } else {
                        if (s[j-1][k] == '#') continue;
                        if (s[j+1][k] == '#') continue;
                    }
                }
                if (W > 1) {
                    if (k == 0) {
                        if (s[j][1] == '#') continue;
                    } else if (k == W-1) {
                        if (s[j][W-2] == '#') continue;
                    } else {
                        if (s[j][k-1] == '#') continue;
                        if (s[j][k+1] == '#') continue;
                    }
                }
                canDraw = false;
            }
        }
        if (!canDraw) {
            break;
        }
    }
    if (canDraw) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
