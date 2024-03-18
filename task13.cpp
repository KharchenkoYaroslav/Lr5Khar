#include <iostream>
#include <windows.h>
using namespace std;

int&  choice(int &x, int &y, bool n) {
    if (n) {
        return x;
    } else {
        return y;
    }
}

int main() {
    SetConsoleOutputCP(65001);
    bool n = true;

    int x = 10;
    int y = -10;

    int &ref = choice(x, y, n);

    ref ++;

    cout << ref << ' '  << x << ' ' << y << endl;

    //Єдине корисне використання яке я можу придумати це обирати на яку змінну буде вказувати референс
    //І далі працювати з референсом, а відносно від вибору зміниться одна зі змінних, що додасть трохи гнучкості.

    return 0;
}