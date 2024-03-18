#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>

using namespace std;

#define SIZE 255

class strtype {
    char *p; 
    int len; 
public:
    strtype();
    ~strtype();
    void set(char const *ptr);
    void show();
};

strtype::strtype() {
    p = new char[SIZE]; 
    if (!p) { 
        cout << "Помилка виділення пам'яті\n";
        exit(1); 
    }
    *p = '\0';
    len = 0;
}


strtype::~strtype() {
    cout << "Звільняю пам'ять\n";
    delete [] p;
}
void strtype::set(char const *ptr){
    if (strlen(ptr) > SIZE){
        cout << "Рядок завеликий\n";
        return;
    }
    strcpy(p, ptr);
    len = strlen(p);
}

void strtype::show() {
    cout << p << " - довжина: " << len;
    cout << "\n";
}


int main() {
    SetConsoleOutputCP(65001);
    strtype s1, s2;
    s1.set("test1");
    s2.set("test 2");
    s1.show(); 
    s2.show();
    return 0; 
}