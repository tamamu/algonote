#include <iostream>

int main()
{
    using namespace std;
    int w, h;
    cin >> w >> h;
    if ((w - h) - (h/3) == 0) {
        cout << "4:3" << endl;
    } else {
        cout << "16:9" << endl;
    }
}
