#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b >= a) {
        cout << min(a, b) << endl;
    } else {
        cout << a-1 << endl;
    }
}
