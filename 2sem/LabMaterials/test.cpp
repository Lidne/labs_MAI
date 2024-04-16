#include <iostream>
#include <string>

using namespace std;


int main() {
    string l = "12345678";
    cout << l.substr(0, 1) << endl;
    cout << l.substr(1, 100) << endl;
    cout << l.substr(1, l.size()) << endl;
}