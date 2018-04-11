#include <iostream>

int main()
{
    using namespace std;
    string o, e;
    cin >> o;
    cin >> e;
    
    int32_t len = o.length() + e.length();
    
    for (auto j = 0; j < len; ++j) {
        if (j % 2 == 0) {
            cout << o[j/2];
        } else {
            cout << e[j/2];
        }
    }
    cout << endl;
}
