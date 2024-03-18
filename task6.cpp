#include <iostream>
#include <windows.h>

using namespace std;

class person {
    string name;
    long long number;
public:
person(string name, long long number): name(name), number(number){};
    void show() {cout << name << " +38" << number << endl;};
    //Можна додати форматування номера в формат +38(000)0000000 та перевірку кількості символів, але завдання не про це
 };

int main() {
    SetConsoleOutputCP(65001);
    person *student = new person("Ляшко", 2215192311);
    student->show();
    delete student;
    return 0;
}