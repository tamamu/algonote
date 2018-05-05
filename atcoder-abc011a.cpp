#include <iostream>

int main()
{
    using namespace std;
    int n;
    cin >> n;
    n += 1;
    if (n > 12) n = 1;
    cout << n << endl;
}
