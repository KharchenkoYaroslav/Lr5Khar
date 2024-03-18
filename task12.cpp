#include <iostream>
#include <cstdlib>
using namespace std;

class array {
    int width, hight;
    char **p;
public:
    array(int numW, int numH) {
        width = numW;
        hight = numH;
        p = new char*[width];
        for (int i = 0; i < width; i++) {
            p[i] = new char[hight];
        }
    }
    ~array() {
        for (int i = 0; i < width; i++) {
            delete [] p[i];
        }
        delete [] p;
    }
    char &put(int i, int j) {
        if (i < 0 || i >= width || j < 0 || j >= hight) {
            cout << "Bounds error! \n";
            exit(1);
        }
        return p[i][j];
    }
    char get(int i, int j) {
        if (i < 0 || i >= width || j < 0 || j >= hight) {
            cout << "Bounds error!\n";
            exit(1);
        }
        return p[i][j];
    }
};

int main() {
    array a(2, 3);
    a.put(0, 1) = 'A';
    a.put(1, 2) = 'B';
    cout << a.get(0, 1) << a.get(1, 2) << "\n";
    // now generate run - time boundary error
    a.put(11, 2) = '!';
    return 0;
}