#include <iostream>

int main()
{
    using namespace std;
    int32_t W, a, b;
    cin >> W;
    cin >> a;
    cin >> b;
    
    int32_t diff;
    
    if (a > b && b+W-a < 0) {
        diff = abs(b+W-a);
    } else if (a < b && a+W-b < 0) {
        diff = abs(a+W-b);
    } else {
        diff = 0;
    }
    
    cout << diff << endl;
}
