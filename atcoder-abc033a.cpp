#include <iostream>

int main()
{
    using namespace std;
    string n;
    cin >> n;
    bool f = true;
    for (auto i=1; i < 4; i++) {
        if (n[i] != n[0]) {
            f = false;
            break;
        }
    }

    if (f) {
        cout << "SAME" << endl;
    } else {
        cout << "DIFFERENT" << endl;
    }
}
