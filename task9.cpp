#include <iostream>

using namespace std;

int main() {
    double *a = new double(-123.0987);
    
    cout << "a: " << *a << endl;    
   
    delete a;

    return 0;
}