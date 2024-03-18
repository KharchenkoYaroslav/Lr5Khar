#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char* p;

    p = new char[100];//В ідеалі використовувати не char* а string тоді і прописувати обмеження не треба

    strcpy(p, " This is a test. ");

    cout << p;

    return 0;
}