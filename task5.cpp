#include <iostream>

using namespace std;

int main() {
    float *a = new float;
    long *b = new long;
    char *c = new char;

    *a = 1.5;
    *b = 10000000;
    *c = 'c';

    cout << "a: " << *a << endl;    
    cout << "b: " << *b << endl;   
    cout << "c: " << *c << endl;   

    delete a,b,c;

    return 0;
}