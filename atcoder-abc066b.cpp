#include <iostream>

int main()
{
    using namespace std;
    string s;
    cin >> s;
    
    int32_t len = s.length();
    
    for (auto j = len - 1; j > 0; --j) {
        if (j % 2 == 0) {
            auto k = j / 2;
            if (s.substr(0,k) == s.substr(k,k)) {
                cout << j << endl;
                break;
            }
        }
    }
}
