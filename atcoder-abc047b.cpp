#include <iostream>

int main()
{
    using namespace std;
    int32_t W, H, N;
    cin >> W >> H >> N;
    
    int32_t xl = 0, xr = W, yt = 0, yb = H;
    for (auto j = 0; j < N; ++j) {
        int32_t x, y, a;
        cin >> x >> y >> a;
        switch(a) {
            case 1:
                xl = max(xl, x);
                break;
            case 2:
                xr = min(xr, x);
                break;
            case 3:
                yt = max(yt, y);
                break;
            case 4:
                yb = min(yb, y);
                break;
        }
    }
    
    auto area = max(0,xr-xl)*max(0,yb-yt);
    cout << area << endl;
}
