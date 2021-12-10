#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
    int tot;
    bool bj;
public:
    void play()
    {
        srand(time(0));
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;
        cout << "first cards" << a << "," << b << endl;
        tot = a + b;
        cout << "Total:" << tot << endl;
        if (tot == 21)
        {
            bj = true;
        }
        else
            bj = false;
        char op;
        while (tot <= 21)
        {
            if (tot >= 17) {
                cout << "do you want another card?(y/n):";
                cin >> op;
                if (op != 'y') {
                    break;
                }
            }
            int c = rand() % 10 + 1;
            cout << "Card:" << c << endl;
            tot += c;
            cout << "Total:" << tot << endl;
        }
    }
    int getTotal()
    {
        return tot;
    }
    bool isBlackJack()
    {
        return bj;
    }
};
class Dealer {
    int tot;
    bool bj;

public:
    void play()
    {
        srand(time(0));
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;
        cout << "first cards" << a << "," << b << endl;
        tot = a + b;
        cout << "Total:" << tot << endl;
        if (tot == 21) {
            bj = true;
        }
        else
            bj = false;
        while (tot < 17) {
            int c = rand() % 10 + 1;
            cout << "Card:" << c << endl;
            tot += c;
            cout << "Total:" << tot << endl;
        }
    }
    int getTotal()
    {
        return tot;
    }
    bool isBlackJack()
    {
        return bj;
    }
};
int main()
{
    Player p;
    Dealer d;
    char op;
    do {
        p.play();
        cout << "Player Cards in hand:" << p.getTotal() << endl;
        d.play();
        cout << "Dealer Cards in hand:" << d.getTotal() << endl;
        if (p.getTotal() > 21) {
            cout << "Game Result:Player Bursts" << endl;
        }
        else if (p.isBlackJack()) {
            cout << "Game Result:Player BlackJack" << endl;
        }
        else if (d.isBlackJack()) {
            cout << "Game Result:Dealer BlackJack" << endl;
        }
        else if (p.getTotal() > 21 && d.getTotal() <= 21) {
            cout << "Game Result:Player Burst" << endl;
        }
        else if (d.getTotal() > 21 && p.getTotal() <= 21) {
            cout << "Game Result:Player Wins" << endl;
        }
        else if (d.getTotal() == p.getTotal()) {
            cout << "Game Result:Push" << endl;
        }
        else if (d.getTotal() < p.getTotal()) {
            cout << "Game Result:Player Wins" << endl;
        }
        else if (d.getTotal() > p.getTotal()) {
            cout << "Game Result:Player Bursts" << endl;
        }
        cout << "Do you want to continue?(y/n):";
        cin >> op;
        if (op != 'y') {
            break;
        }
    } while (true);
}
