#include <iostream>

int main()
{
    using namespace std;
    int32_t A, B, X;
    cin >> A >> B >> X;
    
    auto x = X-A;

    if (x >= 0 && A <= X && x <= B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
