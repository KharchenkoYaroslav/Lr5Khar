#include <iostream>

using namespace std;

void neg(int *n) {
    *n = -*n;
}

void neg(int &n) {
    n = -n;
}

int main() {
    int a = 10;
    int b = 20;

    neg(&a);
    cout << "a = " << a << endl;

    neg(b);
    cout << "b = " << b << endl;

    return 0;
}