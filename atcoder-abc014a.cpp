#include <iostream>

int main()
{
    using namespace std;
    int a, b;
    cin >> a >> b;
    int c = a % b;
    if (c > 0) {
        cout << b - c << endl;
    } else {
        cout << 0 << endl;
    }
}
