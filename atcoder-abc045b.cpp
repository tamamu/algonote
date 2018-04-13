#include <iostream>

int main()
{
    using namespace std;
    string a, b, c;
    cin >> a >> b >> c;
    
    uint32_t sa, sb, sc;
    sa = sb = sc = 0;
    
    uint32_t turn = 0;
    char winner;
    
    while (true)
    {
        char card;
        if (turn == 0) {
            if (a.length() > sa) {
                card = a[sa];
                sa += 1;
            } else {
                winner = 'A';
                break;
            }
        } else if (turn == 1) {
            if (b.length() > sb) {
                card = b[sb];
                sb += 1;
            } else {
                winner = 'B';
                break;
            }
        } else {
            if (c.length() > sc) {
                card = c[sc];
                sc += 1;
            } else {
                winner = 'C';
                break;
            }
        }
        
        if (card == 'a') {
            turn = 0;
        } else if (card == 'b') {
            turn = 1;
        } else {
            turn = 2;
        }
    }

    cout << winner << endl;
}
